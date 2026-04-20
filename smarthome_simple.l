%{
#include "y.tab.h"
#include <stdlib.h>
%}

%option caseless
%option noyywrap

%%

/* ─── Keywords ─── */
"if"            return IF;
"then"          return THEN;
"else"          return ELSE;
"end"           return END;
"set"           return SET;
"status"        return STATUS;
"scene"         return SCENE;

/* ─── Device Control ─── */
"on"            return ON;
"off"           return OFF;

/* ─── Operators ─── */
"=="            return EQ;
">"             return GT;
"<"             return LT;
"="             return ASSIGN;

/* ─── Sensors ─── */
"temp"          return TEMP;
"motion"        return MOTION;
"time"          return TIME;

/* ─── Devices ─── */
"light"         return LIGHT;
"fan"           return FAN;
"ac"            return AC;
"alarm"         return ALARM;
"camera"        return CAMERA;

/* ─── Sensor Values ─── */
"detected"      return DETECTED;
"clear"         return CLEAR;
"morning"       return MORNING;
"night"         return NIGHT;

/* ─── Numbers ─── */
[0-9]+          { yylval = atoi(yytext); return NUM; }

/* ─── Whitespace & Comments ─── */
[ \t\n\r]       ;
"#"[^\n]*       ;   /* Skip comments */

/* ─── Invalid Token ─── */
.               return INVALID;

%%
