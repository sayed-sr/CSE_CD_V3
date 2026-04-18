%{
#include "y.tab.h"
#include <stdlib.h>
#include <string.h>
%}

%option caseless
%option noyywrap

%%

"if"            return IF;
"then"          return THEN;
"else"          return ELSE;
"end"           return END;
"and"           return AND;
"or"            return OR;

"set"           return SET;
"status"        return STATUS;
"log"           return LOG;
"scene"         return SCENE;

"on"            return ON;
"off"           return OFF;
"lock"          return LOCK;
"unlock"        return UNLOCK;

"=="            return EQ;
"!="            return NEQ;
">"             return GT;
"<"             return LT;
">="            return GTE;
"<="            return LTE;
"="             return ASSIGN;

"time"          return TIME;
"temp"          return TEMP;
"motion"        return MOTION;
"humidity"      return HUMIDITY;
"smoke"         return SMOKE;
"door"          return DOOR;

"light"         return LIGHT;
"fan"           return FAN;
"ac"            return AC;
"heater"        return HEATER;
"alarm"         return ALARM;
"camera"        return CAMERA;
"sprinkler"     return SPRINKLER;

"morning"       return MORNING;
"night"         return NIGHT;
"day"           return DAY;
"detected"      return DETECTED;
"clear"         return CLEAR;
"open"          return OPEN;
"closed"        return CLOSED;
"emergency"     return EMERGENCY;

"high"          return HIGH;
"low"           return LOW;
"normal"        return NORMAL;

[0-9]+          { yylval = atoi(yytext); return NUM; }

[ \t\n\r]       ;
"#"[^\n]*       ;   /* comments */
.               return INVALID;

%%
