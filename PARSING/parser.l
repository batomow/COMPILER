%{
#include "tokens.h"
%}

%%
\/\/.*$                         { /* do nothing */}
\/\*.*?\*\/                     { /* do nothing */}
"["                             return OBRAK;
"]"                             return CBRAK;
"("                             return OPARE;
")"                             return CPARE;
","                             return COMMA;
"->"                            return ARROW;
"=="                            return EQQ;
">="                            return GTEQ;
"<="                            return LTEQ;
"!="                            return NTEQ;
"="                             return EQ;
">"                             return GT;
"<"                             return LT;
"!"                             return NT;
"+"                             return SUM;
"-"                             return RES;
"*"                             return MUL;
"/"                             return DIV;
"^^"                            return SQR;
"^"                             return POW;
"&&"                            return AND;
"||"                            return OR;
"\r"                            return CR;
"\n"                            return LF;
[ \t]                           return TWS;
MAINSCENE                       return MSCN;
SCENES                          return SCNS;
deploy                          return DPLY;
if                              return IF;
elif                            return ELIF;
else                            return ELSE;
for                             return FOR;
while                           return WHILE;
var                             return VAR;
mat                             return MAT;
mat4                            return MAT4;
map                             return MAP;
order                           return ORDER;
"execute order"                 return XRDER;
meditate                        return MEDITATE;
(lie|truth)                     return BOOL;
[a-zA-Z][a-zA-Z0-9]*\.fs        return FID;
[a-zA-Z][a-zA-Z0-9]*\.holo      return MID;
[a-zA-Z][a-zA-Z0-9]*            return ID;
\'[a-z]\'                       return CHAR;
\"(\\.|[^"\\])*\"               return STRING;
[-+]?[0-9]*?i                   return INT;
[-+]?[0-9]*\.?[0-9]?f           return FLOAT;
[-+]?[0-9]*\.?[0-9]?d           return DOUBLE;

%%

int yywrap(void){
    return 1;
}

