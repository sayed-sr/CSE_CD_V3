%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(const char *s);

/* Device States */
int light = 0, fan = 0, ac = 0, alarm = 0, camera = 0;

/* Sensor Values */
int temp_val = 25, motion_val = 0, time_period = 0;
%}

%token IF THEN ELSE END SET STATUS SCENE
%token ON OFF EQ GT LT ASSIGN
%token TEMP MOTION TIME LIGHT FAN AC ALARM CAMERA
%token DETECTED CLEAR MORNING NIGHT NUM INVALID

%%

/* ─── Main Program ─── */
program:
      /* empty */
    | program statement
;

statement:
      if_statement
    | set_statement
    | sensor_assignment
;

/* ─── IF/THEN/ELSE Rules (Lines 30-36: Rule Definition) ─── */
if_statement:
    IF condition THEN action_list END {
        printf("IF rule executed\n");
    }
;

/* ─── Conditions (Lines 39-52: Condition Definition) ─── */
condition:
    TEMP GT NUM {
        if (temp_val > $3) {
            printf("✔ temp(%d) > %d is TRUE\n", temp_val, $3);
            $$ = 1;
        } else {
            printf("✘ temp(%d) > %d is FALSE\n", temp_val, $3);
            $$ = 0;
        }
    }
  | MOTION EQ DETECTED {
        $$ = motion_val;
        printf("%s motion == detected\n", $$?"✔":"✘");
    }
;

action_list: action | action_list action ;

action:
    SET AC ON { ac = 1; printf("→ AC turned ON\n"); }
  | SET FAN ON { fan = 1; printf("→ Fan turned ON\n"); }
  | SET LIGHT ON { light = 1; printf("→ Light turned ON\n"); }
;

/* ─── Sensor Input (Lines 64-68: Sensor Assignment) ─── */
sensor_assignment:
    TEMP ASSIGN NUM { temp_val = $3; printf("Temp set to %d°C\n", $3); }
  | MOTION ASSIGN DETECTED { motion_val = 1; printf("Motion: DETECTED\n"); }
;

%%

int main() {
    printf("=== Smart Home Parser ===\n");
    yyparse();
    printf("\nFinal State: AC=%s, Fan=%s, Light=%s\n",
           ac?"ON":"OFF", fan?"ON":"OFF", light?"ON":"OFF");
    return 0;
}

int yyerror(const char *s) {
    printf("Error: %s\n", s);
    return 0;
}
