%{
#include "tokens.h"
%}

Digit			[0-9]
Letter			[a-zA-Z_]
Hex			[a-fA-F0-9]
EOL			\n\r

%%

\/\/.*\r*\n			{ printf(yytext); /*single line comment: do nothing */ }
\/\*(.|\r*\n)*\*\/		{ printf(yytext); /*multiline comment: do nothing */ }

"\r"				{ return CR; /* 301 */ }
"\n"				{ return LF; /* 300 */ }

"MAINSCENE"			{ return RES_MSCN; }
"SCENES"			{ return RES_SCNS; }
"deploy"			{ return RES_DPLY; }
"if"				{ return LOG_IF; }
"elif"				{ return LOG_ELIF; }
"else"				{ return LOG_ELSE; }
"for"				{ return LOG_FOR; }
"while"				{ return LOG_WHILE; }
"var"				{ return V_VAR; }
"mat"				{ return V_MAT; }
"mat4"				{ return V_MAT4; }
"map"				{ return V_MAP; }
"order"				{ return RES_ORDER; }
"execute order"			{ return RES_XRDER; }
"meditate"			{ return RES_MEDIT; }
"return"			{ return RES_RETRN; }

(lie|truth)			{ return V_BOOL; /* bool */ }

[a-z][a-zA-Z0-9]*               { return V_ID; }
[a-zA-Z][a-zA-Z0-9]*\.fs        { return F_ID; }
[a-zA-Z][a-zA-Z0-9]*\.holo      { return M_ID; }

\'[a-zA-Z0-9]\'			{ return V_CHAR; /* char */ }
[-+]?[0-9]+i?			{ return V_INT; /* int */ }
[-+]?[0-9]+\.?[0-9]*f?		{ return V_FLOAT; /* float */ }
[-+]?[0-9]+\.?[0-9]*d		{ return V_DOUBLE; /* double */ }
\"(\\.|[^"\\])*\"		{ return V_STRING; /* string */ }

"["				{ return SYM_OBRAC; }
"]"				{ return SYM_CBRAC; }
"("				{ return SYM_OPARE; }
")"				{ return SYM_CPARE; }
"{"				{ return SYM_OCURL; }
"}"				{ return SYM_CCURL; }
","				{ return SYM_COMMA; }
"->"				{ return SYM_ARROW; }
":"				{ return SYM_COLON; }

"=="				{ return MTH_DEQUA; }
">="				{ return MTH_GTEQ; }
"<="				{ return MTH_LTEQ; }
"!="				{ return MTH_NOTEQ; }
"="				{ return MTH_SEQUA; }
">"				{ return MTH_GT; }
"<"				{ return MTH_LT; }
"!"				{ return MTH_NOT; }
"+"				{ return MTH_PLUS; }
"-"				{ return MTH_MINUS; }
"*"				{ return MTH_ASTRK; }
"/"				{ return MTH_DIVIS; }
"^^"				{ return MTH_ROOT; }
"^"				{ return MTH_POWER; }
"&&"				{ return MTH_AND; }
"||"				{ return MTH_OR; }

.				{ /* do nothing */}

%%

int yywrap(void){
    return 1;
}

