%{
	#include "parser.tab.h"

	extern int yylex();

	extern void yyerror();

	void multilineComment();
%}

Digit			[0-9]
Letter			[a-zA-Z_]
Hex			[a-fA-F0-9]
EOL			\n\r

%%

\/\/.*\n		{  /*single line comment: do nothing */ }
"/*"			{ multilineComment(); }

"\r"				{ /* printf("CR\n"); */ return CR; /* 301 */ }
"\n"				{ printf("lf\n"); return LF; /* 300 */ }

"MAINSCENE"			{ printf("MSCN "); return RES_MSCN; }
"SCENES"			{ printf("SCENES "); return RES_SCNS; }
"deploy"			{ printf("DPLY "); return RES_DPLY; }
"if"				{ printf("IF "); return LOG_IF; }
"elif"				{ printf("ELIF "); return LOG_ELIF; }
"else"				{ printf("ELSE "); return LOG_ELSE; }
"for"				{ printf("FOR "); return LOG_FOR; }
"while"				{ printf("WHILE "); return LOG_WHILE; }
"var"				{ printf("var "); return V_VAR; }
"array"				{ printf("arr "); return V_ARR; }
"mat"				{ printf("mat "); return V_MAT; }
"mat4"				{ printf("mat4 "); return V_MAT4; } 
"map"				{ printf("map "); return V_MAP; }
"vector"			{ printf("vector "); return V_VECTOR; }
"element"			{ printf("element "); return V_ELEM; }
"order"				{ printf("order "); return RES_ORDER; }
"execute order"			{ printf("xrder "); return RES_XRDER; }
"meditate"			{ printf("medit "); return RES_MEDIT; }
"return"			{ printf("retrn "); return RES_RETRN; }

(lie|truth)			{ printf("bool "); return V_BOOL; /* bool */ }

[a-z][a-zA-Z0-9]*               { printf("v_id "); return V_ID; }
[a-zA-Z][a-zA-Z0-9]*\.fs        { printf("f_id "); return F_ID; }
[a-zA-Z][a-zA-Z0-9]*\.holo      { printf("M_ID "); return M_ID; }

#{Hex}{6}					{ printf("hex "); return V_HEX; /* hexadecimal color */ }
\'[a-zA-Z0-9]\'			{ printf("char "); return V_CHAR; /* char */ }
[-+]?[0-9]+i?			{ printf("int "); return V_INT; /* int */ }
[-+]?[0-9]+\.?[0-9]*f?		{ printf("float "); return V_FLOAT; /* float */ }
[-+]?[0-9]+\.?[0-9]*d		{ printf("double "); printf(""); return V_DOUBLE; /* double */ }
\"(\\.|[^"\\])*\"		{ printf("string "); return V_STRING; /* string */ }


"["				{ printf("[ "); return SYM_OBRAC; }
"]"				{ printf("] "); return SYM_CBRAC; }
"("				{ printf("( "); return SYM_OPARE; }
")"				{ printf(") "); return SYM_CPARE; }
"{"				{ printf("{ "); return SYM_OCURL; }
"}"				{ printf("} "); return SYM_CCURL; }
","				{ printf(", "); return SYM_COMMA; }
"->"				{ printf("-> "); return SYM_ARROW; }
":"				{ printf(": "); return SYM_COLON; }
"."				{ printf(". "); return SYM_DOT; }

"=="				{ printf("== "); return MTH_DEQUA; }
">="				{ printf(">= "); return MTH_GTEQ; }
"<="				{ printf("<= "); return MTH_LTEQ; }
"!="				{ printf("!= "); return MTH_NOTEQ; }
"="				{ printf("= "); return MTH_SEQUA; }
">"				{ printf("> "); return MTH_GT; }
"<"				{ printf("< "); return MTH_LT; }
"!"				{ printf("! "); return MTH_NOT; }
"+"				{ printf("+ "); return MTH_PLUS; }
"-"				{ printf("- "); return MTH_MINUS; }
"*"				{ printf("* "); return MTH_ASTRK; }
"/"				{ printf("/ "); return MTH_DIVIS; }
"^^"				{ printf("^^ "); return MTH_ROOT; }
"^"				{ printf("^ "); return MTH_POWER; }
"&&"				{ printf("&& "); return MTH_AND; }
"||"				{ printf("|| "); return MTH_OR; }

[ \t\v\f]			{ /* do nothing */}
.				{ yyerror("Invalid character"); return *yytext;}

%%

void multilineComment() {
	char c, c1;

	loop:
		while ((c = input()) != '*' && c != 0) { }

		if ((c1 = input()) != '/' && c != 0)
		{
			goto loop;
		}
}

int yywrap(void){
    return 1;
}

