%{
#include "tokens.h"
%}

%%

"//".*			        { return COMMENT; /* 800 */}
"/*"([^*]|(\*+[^*/]))*\*+\/      { return MCOMMENT; /* 801 */}

"\r"				{ return CR; /* 301 */ }
"\n"				{ return LF; /* 300 */ }
(\t|\s)                          { return TWS; /* 302 */}

"MAINSCENE"			{ return RES_MSCN; /* 400 */ }
"CURRENTSCENE"                  { return RES_CSCN; /* 407 */ }
"NEXTSCENE"                     { return RES_NSCN; /* 408 */ }
"SCENES"			{ return RES_SCNS; /* 401 */}
"deploy"			{ return RES_DPLY; /* 402 */}
"if"				{ return LOG_IF; /* 500 */}
"elif"				{ return LOG_ELIF; /* 501 */}
"else"				{ return LOG_ELSE; /* 502 */}
"for"				{ return LOG_FOR; /* 503 */}
"while"				{ return LOG_WHILE; /* 504 */}
"var"				{ return VAR; /* 600 */}
"vector"                        { return V_VECTOR; /* 610 */}
"mat"				{ return V_MAT; /*  607 */}
"mat4"				{ return V_MAT4; /* 608 */}
"map"				{ return V_MAP; /* 609 */}
"order"				{ return RES_ORDER; /* 700 */}
"execute order"			{ return RES_XRDER; /* 701 */}
"station"                       { return STATION; /* 704 */ } 
"element"                       { return ELEMENT; /* 705 */ }
"sacred texts"                  { return ENUM; /* 611 */ }
"meditate"			{ return RES_MEDIT; /* 702 */}
"return"			{ return RES_RETRN; /* 703 */}

(lie|truth)			{ return V_BOOL; /* bool 606 */ }

[a-z][a-zA-Z0-9]*               { return ID; /* 403 */}
[a-zA-Z][a-zA-Z0-9]*\.fs        { return F_ID; /* 404 */}
[a-zA-Z][a-zA-Z0-9]*\.holo      { return M_ID; /* 405 */}

\'(\\.|[^"\\])*\'			{ return V_CHAR; /* char 601 */ }
[-+]?[0-9]+i?			{ return V_INT; /* int  604 */ }
[-+]?[0-9]+\.?[0-9]*f?		{ return V_FLOAT; /* float 603 */ }
[-+]?[0-9]+\.?[0-9]*d		{ return V_DOUBLE; /* double 605 */ }
\"(\\.|[^"\\])*\"		{ return V_STRING; /* string 602*/ }

"["				{ return SYM_OBRAC; /* 100 */}
"]"				{ return SYM_CBRAC; /* 101 */}
"("				{ return SYM_OPARE; /* 102 */}
")"				{ return SYM_CPARE; /* 103 */}
"{"				{ return SYM_OCURL; /* 104 */}
"}"				{ return SYM_CCURL; /* 105 */}
","				{ return SYM_COMMA; /* 106 */}
"->"				{ return SYM_ARROW; /* 107 */}
":"				{ return SYM_COLON; /* 108 */}

"=="				{ return MTH_DEQUA; /* 201 */}
">="				{ return MTH_GTEQ; /* 204 */}
"<="				{ return MTH_LTEQ; /* 205 */}
"!="				{ return MTH_NOTEQ; /* 207 */}
"="				{ return MTH_SEQUA; /* 200 */}
">"				{ return MTH_GT; /* 202 */}
"<"				{ return MTH_LT; /* 203 */}
"!"				{ return MTH_NOT; /* 206 */}
"+"				{ return MTH_PLUS; /* 208 */}
"-"				{ return MTH_MINUS; /* 209 */}
"*"				{ return MTH_ASTRK; /* 210 */}
"/"				{ return MTH_DIVIS; /* 211 */}
"^^"				{ return MTH_ROOT; /* 213 */}
"^"				{ return MTH_POWER; /* 212 */ }
"&&"				{ return MTH_AND; /* 214 */}
"||"				{ return MTH_OR; /* 215 */}

.				{ /* do nothing */}

%%

int yywrap(void){
    return 1;
}

