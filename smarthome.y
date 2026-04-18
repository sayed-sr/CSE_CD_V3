%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex(void);
int yyerror(const char *s);

/* ─── DEVICE STATE TABLE ─── */
int light_state    = 0;   /* 0 = OFF, 1 = ON  */
int fan_state      = 0;
int ac_state       = 0;
int heater_state   = 0;
int alarm_state    = 0;
int camera_state   = 0;
int sprinkler_state= 0;
int door_state     = 0;   /* 0 = locked, 1 = unlocked */

/* ─── SENSOR STATE ─── */
int temp_val       = 25;  /* degrees Celsius (default) */
int humidity_val   = 50;  /* percent (default)         */
int motion_val     = 0;   /* 0=clear, 1=detected       */
int smoke_val      = 0;   /* 0=clear, 1=detected       */
int door_sensor    = 0;   /* 0=closed, 1=open          */
int time_period    = 0;   /* 0=day, 1=morning, 2=night */

/* ─── EMERGENCY OVERRIDE ─── */
int emergency_mode = 0;

/* ─── LOG ─── */
int log_count = 0;
char log_entries[50][128];

/* ─── HELPERS ─── */
void log_event(const char *msg) {
    if (log_count < 50) {
        strncpy(log_entries[log_count++], msg, 127);
    }
    printf("  [LOG] %s\n", msg);
}

void ast(const char *parent, const char *child) {
    printf("  AST: (%s -> %s)\n", parent, child);
}

const char* onoff(int state) { return state ? "ON" : "OFF"; }

void print_status() {
    printf("\n╔══════════════════════════════════════╗\n");
    printf("║        DEVICE STATUS DASHBOARD       ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  💡 Light     : %-20s║\n", onoff(light_state));
    printf("║  🌀 Fan       : %-20s║\n", onoff(fan_state));
    printf("║  ❄️  AC        : %-20s║\n", onoff(ac_state));
    printf("║  🔥 Heater    : %-20s║\n", onoff(heater_state));
    printf("║  🔔 Alarm     : %-20s║\n", onoff(alarm_state));
    printf("║  📷 Camera    : %-20s║\n", onoff(camera_state));
    printf("║  💧 Sprinkler : %-20s║\n", onoff(sprinkler_state));
    printf("║  🚪 Door      : %-20s║\n", door_state ? "UNLOCKED" : "LOCKED");
    printf("╠══════════════════════════════════════╣\n");
    printf("║         SENSOR READINGS              ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║  🌡️  Temp      : %-3d°C               ║\n", temp_val);
    printf("║  💧 Humidity  : %-3d%%                ║\n", humidity_val);
    printf("║  👁️  Motion    : %-20s║\n", motion_val ? "DETECTED" : "CLEAR");
    printf("║  🔥 Smoke     : %-20s║\n", smoke_val ? "DETECTED" : "CLEAR");
    printf("║  🚪 Door Snsr : %-20s║\n", door_sensor ? "OPEN" : "CLOSED");
    printf("╚══════════════════════════════════════╝\n\n");
}
%}

/* ─── TOKENS ─── */
%token IF THEN ELSE END AND OR
%token SET STATUS LOG SCENE
%token ON OFF LOCK UNLOCK
%token EQ NEQ GT LT GTE LTE ASSIGN
%token TIME TEMP MOTION HUMIDITY SMOKE DOOR
%token LIGHT FAN AC HEATER ALARM CAMERA SPRINKLER
%token MORNING NIGHT DAY DETECTED CLEAR OPEN CLOSED EMERGENCY
%token HIGH LOW NORMAL NUM
%token INVALID

%%

/* ─── TOP-LEVEL PROGRAM ─── */
program:
      /* empty */
    | program statement
;

statement:
      if_statement
    | set_statement
    | status_statement
    | log_statement
    | scene_statement
    | sensor_assignment
    | emergency_statement
;

/* ─── IF / THEN / ELSE / END ─── */
if_statement:
    IF condition THEN action_list END {
        ast("if_stmt", "condition+actions");
    }
  | IF condition THEN action_list ELSE action_list END {
        ast("if_stmt", "condition+then+else");
    }
;

/* ─── CONDITIONS ─── */
condition:
    simple_condition
  | simple_condition AND simple_condition {
        ast("condition", "AND");
    }
  | simple_condition OR simple_condition {
        ast("condition", "OR");
    }
;

simple_condition:
    TEMP GT NUM {
        ast("cond", "temp>");
        if (temp_val > $3)
            printf("  ✔ Condition TRUE: temp(%d) > %d\n", temp_val, $3);
        else
            printf("  ✘ Condition FALSE: temp(%d) > %d\n", temp_val, $3);
        $$ = (temp_val > $3) ? 1 : 0;
    }
  | TEMP LT NUM {
        ast("cond", "temp<");
        if (temp_val < $3)
            printf("  ✔ Condition TRUE: temp(%d) < %d\n", temp_val, $3);
        else
            printf("  ✘ Condition FALSE: temp(%d) < %d\n", temp_val, $3);
        $$ = (temp_val < $3) ? 1 : 0;
    }
  | TEMP EQ NUM {
        ast("cond", "temp==");
        $$ = (temp_val == $3) ? 1 : 0;
        printf("  %s Condition: temp(%d) == %d\n", $$?"✔":"✘", temp_val, $3);
    }
  | HUMIDITY GT NUM {
        ast("cond", "humidity>");
        $$ = (humidity_val > $3) ? 1 : 0;
        printf("  %s Condition: humidity(%d) > %d\n", $$?"✔":"✘", humidity_val, $3);
    }
  | HUMIDITY LT NUM {
        ast("cond", "humidity<");
        $$ = (humidity_val < $3) ? 1 : 0;
        printf("  %s Condition: humidity(%d) < %d\n", $$?"✔":"✘", humidity_val, $3);
    }
  | MOTION EQ DETECTED {
        ast("cond", "motion==detected");
        $$ = motion_val;
        printf("  %s Condition: motion == detected\n", $$?"✔":"✘");
    }
  | MOTION EQ CLEAR {
        ast("cond", "motion==clear");
        $$ = !motion_val;
        printf("  %s Condition: motion == clear\n", $$?"✔":"✘");
    }
  | SMOKE EQ DETECTED {
        ast("cond", "smoke==detected");
        $$ = smoke_val;
        printf("  %s Condition: smoke == detected\n", $$?"✔":"✘");
    }
  | DOOR EQ OPEN {
        ast("cond", "door==open");
        $$ = door_sensor;
        printf("  %s Condition: door == open\n", $$?"✔":"✘");
    }
  | DOOR EQ CLOSED {
        ast("cond", "door==closed");
        $$ = !door_sensor;
        printf("  %s Condition: door == closed\n", $$?"✔":"✘");
    }
  | TIME EQ NIGHT {
        ast("cond", "time==night");
        $$ = (time_period == 2);
        printf("  %s Condition: time == night\n", $$?"✔":"✘");
    }
  | TIME EQ MORNING {
        ast("cond", "time==morning");
        $$ = (time_period == 1);
        printf("  %s Condition: time == morning\n", $$?"✔":"✘");
    }
  | TIME EQ DAY {
        ast("cond", "time==day");
        $$ = (time_period == 0);
        printf("  %s Condition: time == day\n", $$?"✔":"✘");
    }
;

/* ─── ACTION LIST ─── */
action_list:
      action
    | action_list action
;

action:
    device_action
  | log_statement
;

device_action:
    SET LIGHT ON {
        ast("action", "light=ON");
        light_state = 1;
        printf("  → 💡 Light turned ON\n");
        log_event("Light turned ON by rule");
    }
  | SET LIGHT OFF {
        ast("action", "light=OFF");
        light_state = 0;
        printf("  → 💡 Light turned OFF\n");
        log_event("Light turned OFF by rule");
    }
  | SET FAN ON {
        ast("action", "fan=ON");
        fan_state = 1;
        printf("  → 🌀 Fan turned ON\n");
        log_event("Fan turned ON by rule");
    }
  | SET FAN OFF {
        ast("action", "fan=OFF");
        fan_state = 0;
        printf("  → 🌀 Fan turned OFF\n");
        log_event("Fan turned OFF by rule");
    }
  | SET AC ON {
        ast("action", "ac=ON");
        ac_state = 1;
        printf("  → ❄️  AC turned ON\n");
        log_event("AC turned ON by rule");
    }
  | SET AC OFF {
        ast("action", "ac=OFF");
        ac_state = 0;
        printf("  → ❄️  AC turned OFF\n");
        log_event("AC turned OFF by rule");
    }
  | SET HEATER ON {
        ast("action", "heater=ON");
        heater_state = 1;
        printf("  → 🔥 Heater turned ON\n");
        log_event("Heater turned ON by rule");
    }
  | SET HEATER OFF {
        ast("action", "heater=OFF");
        heater_state = 0;
        printf("  → 🔥 Heater turned OFF\n");
        log_event("Heater turned OFF by rule");
    }
  | SET ALARM ON {
        ast("action", "alarm=ON");
        alarm_state = 1;
        printf("  → 🔔 ALARM ACTIVATED!\n");
        log_event("Alarm activated by rule");
    }
  | SET ALARM OFF {
        ast("action", "alarm=OFF");
        alarm_state = 0;
        printf("  → 🔔 Alarm deactivated\n");
        log_event("Alarm deactivated by rule");
    }
  | SET CAMERA ON {
        ast("action", "camera=ON");
        camera_state = 1;
        printf("  → 📷 Camera activated\n");
        log_event("Camera activated by rule");
    }
  | SET CAMERA OFF {
        ast("action", "camera=OFF");
        camera_state = 0;
        printf("  → 📷 Camera deactivated\n");
        log_event("Camera deactivated by rule");
    }
  | SET SPRINKLER ON {
        ast("action", "sprinkler=ON");
        sprinkler_state = 1;
        printf("  → 💧 Sprinkler activated!\n");
        log_event("Sprinkler activated by rule");
    }
  | SET SPRINKLER OFF {
        ast("action", "sprinkler=OFF");
        sprinkler_state = 0;
        printf("  → 💧 Sprinkler deactivated\n");
        log_event("Sprinkler deactivated by rule");
    }
  | LOCK DOOR {
        ast("action", "door=LOCKED");
        door_state = 0;
        printf("  → 🚪 Door LOCKED\n");
        log_event("Door locked by rule");
    }
  | UNLOCK DOOR {
        ast("action", "door=UNLOCKED");
        door_state = 1;
        printf("  → 🚪 Door UNLOCKED\n");
        log_event("Door unlocked by rule");
    }
;

/* ─── DIRECT SET STATEMENT ─── */
set_statement:
    SET LIGHT ON {
        light_state = 1;
        ast("set_stmt", "light=ON");
        printf("  → 💡 Light turned ON\n");
        log_event("Light turned ON directly");
    }
  | SET LIGHT OFF {
        light_state = 0;
        ast("set_stmt", "light=OFF");
        printf("  → 💡 Light turned OFF\n");
        log_event("Light turned OFF directly");
    }
  | SET FAN ON {
        fan_state = 1;
        ast("set_stmt", "fan=ON");
        printf("  → 🌀 Fan turned ON\n");
    }
  | SET FAN OFF {
        fan_state = 0;
        ast("set_stmt", "fan=OFF");
        printf("  → 🌀 Fan turned OFF\n");
    }
  | SET ALARM ON {
        alarm_state = 1;
        ast("set_stmt", "alarm=ON");
        printf("  → 🔔 Alarm ON\n");
    }
  | SET ALARM OFF {
        alarm_state = 0;
        ast("set_stmt", "alarm=OFF");
        printf("  → 🔔 Alarm OFF\n");
    }
  | SET CAMERA ON {
        camera_state = 1;
        ast("set_stmt", "camera=ON");
        printf("  → 📷 Camera ON\n");
    }
  | LOCK DOOR {
        door_state = 0;
        ast("set_stmt", "door=LOCKED");
        printf("  → 🚪 Door LOCKED\n");
    }
  | UNLOCK DOOR {
        door_state = 1;
        ast("set_stmt", "door=UNLOCKED");
        printf("  → 🚪 Door UNLOCKED\n");
    }
;

/* ─── SENSOR ASSIGNMENTS ─── */
sensor_assignment:
    TEMP ASSIGN NUM {
        ast("sensor", "temp=val");
        temp_val = $3;
        printf("  → 🌡️  Temperature set to %d°C\n", temp_val);
    }
  | HUMIDITY ASSIGN NUM {
        ast("sensor", "humidity=val");
        humidity_val = $3;
        printf("  → 💧 Humidity set to %d%%\n", humidity_val);
    }
  | MOTION ASSIGN DETECTED {
        ast("sensor", "motion=detected");
        motion_val = 1;
        printf("  → 👁️  Motion sensor: DETECTED\n");
    }
  | MOTION ASSIGN CLEAR {
        ast("sensor", "motion=clear");
        motion_val = 0;
        printf("  → 👁️  Motion sensor: CLEAR\n");
    }
  | SMOKE ASSIGN DETECTED {
        ast("sensor", "smoke=detected");
        smoke_val = 1;
        printf("  → 🔥 Smoke sensor: DETECTED\n");
    }
  | SMOKE ASSIGN CLEAR {
        ast("sensor", "smoke=clear");
        smoke_val = 0;
        printf("  → 🔥 Smoke sensor: CLEAR\n");
    }
  | DOOR ASSIGN OPEN {
        ast("sensor", "door=open");
        door_sensor = 1;
        printf("  → 🚪 Door sensor: OPEN\n");
    }
  | DOOR ASSIGN CLOSED {
        ast("sensor", "door=closed");
        door_sensor = 0;
        printf("  → 🚪 Door sensor: CLOSED\n");
    }
  | TIME ASSIGN MORNING {
        ast("sensor", "time=morning");
        time_period = 1;
        printf("  → 🌅 Time set to MORNING\n");
    }
  | TIME ASSIGN NIGHT {
        ast("sensor", "time=night");
        time_period = 2;
        printf("  → 🌙 Time set to NIGHT\n");
    }
  | TIME ASSIGN DAY {
        ast("sensor", "time=day");
        time_period = 0;
        printf("  → ☀️  Time set to DAY\n");
    }
;

/* ─── EMERGENCY OVERRIDE ─── */
emergency_statement:
    EMERGENCY {
        ast("emergency", "override");
        emergency_mode = 1;
        alarm_state    = 1;
        camera_state   = 1;
        sprinkler_state= 1;
        door_state     = 1;   /* unlock for evacuation */
        printf("  ⚠️  EMERGENCY MODE ACTIVATED!\n");
        printf("  → All alarms ON, cameras ON, sprinklers ON, doors UNLOCKED\n");
        log_event("EMERGENCY MODE ACTIVATED — all safety systems triggered");
    }
;

/* ─── SCENE SHORTCUTS ─── */
scene_statement:
    SCENE MORNING {
        ast("scene", "morning");
        printf("  → 🌅 Morning Scene activated\n");
        light_state  = 1;
        fan_state    = 0;
        ac_state     = 0;
        door_state   = 1;   /* unlock */
        camera_state = 1;
        printf("     Lights ON, Door UNLOCKED, Camera ON\n");
        log_event("Morning scene activated");
    }
  | SCENE NIGHT {
        ast("scene", "night");
        printf("  → 🌙 Night Scene activated\n");
        light_state  = 0;
        fan_state    = 1;
        door_state   = 0;   /* lock */
        camera_state = 1;
        printf("     Lights OFF, Fan ON, Door LOCKED, Camera ON\n");
        log_event("Night scene activated");
    }
  | SCENE NORMAL {
        ast("scene", "normal");
        printf("  → 🏠 Normal Scene activated — resetting all devices\n");
        light_state = fan_state = ac_state = heater_state = 0;
        alarm_state = camera_state = sprinkler_state = 0;
        door_state  = 0;
        emergency_mode = 0;
        log_event("Normal scene activated — all devices reset");
    }
;

/* ─── STATUS COMMAND ─── */
status_statement:
    STATUS {
        ast("status", "print");
        print_status();
    }
;

/* ─── LOG COMMAND ─── */
log_statement:
    LOG {
        ast("log", "print");
        printf("\n  ── Event Log (%d entries) ──\n", log_count);
        int i;
        for (i = 0; i < log_count; i++)
            printf("  [%02d] %s\n", i+1, log_entries[i]);
        if (log_count == 0)
            printf("  (no events logged yet)\n");
        printf("\n");
    }
;

%%

/* ─── MAIN ─── */
int main() {
    printf("╔══════════════════════════════════════╗\n");
    printf("║  Smart Home Automation Rule Engine   ║\n");
    printf("║  Lex + Yacc Compiler Project         ║\n");
    printf("╚══════════════════════════════════════╝\n\n");
    printf("Parsing rules...\n\n");

    yyparse();

    printf("\n════════════ FINAL STATE ════════════\n");
    print_status();

    printf("Event Log Summary: %d event(s) recorded.\n", log_count);
    printf("\nCompilation & execution complete.\n");
    return 0;
}

int yyerror(const char *s) {
    printf("  ❌ Syntax Error: %s\n", s);
    return 0;
}
