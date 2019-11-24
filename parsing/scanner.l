%{
	#include "parser.tab.h"

	extern int yylex();

	extern void yyerror();

	void multilineComment();
    
    char buffer[256]; 
%}

Digit			[0-9]
Letter			[a-zA-Z_]
EOL			\n\r

%%

\/\/.*\n		{  /*single line comment: do nothing */ }
"/*"			{ multilineComment(); }

"\r"				{ /* printf("CR\n"); */ return CR; /* 301 */ }
"\n"				{ printf("lf\n"); return LF; /* 300 */ }

"if"				{ printf("IF "); return LOG_IF; }
"elif"				{ printf("ELIF "); return LOG_ELIF; }
"else"				{ printf("ELSE "); return LOG_ELSE; }
"for"				{ printf("FOR "); return LOG_FOR; }
"while"				{ printf("WHILE "); return LOG_WHILE; }
"var"				{ printf("var "); return V_VAR; }
"array"				{ printf("arr "); return V_ARR; }
"mat"				{ printf("mat "); return V_MAT; }
"vector"			{ printf("vector "); return V_VECTOR; }
"element"			{ printf("element "); return V_ELEM; }
"order"				{ printf("order "); return RES_ORDER; }
"meditate"			{ printf("medit "); return RES_MEDIT; }
"return"			{ printf("return "); return RES_RETRN; }
"bool"				{   
                        yylval.datatype = TypeBool; 
                        printf("bool "); return T_BOOL; 
                    }
"char"				{   
                         yylval.datatype = TypeChar; 
                        printf("char "); return T_CHAR; 
                    }
"int"				{   
                         yylval.datatype = TypeInt; 
                        printf("int "); return T_INT; 
                    }
"float"				{   
                         yylval.datatype = TypeFloat; 
                        printf("float "); return T_FLOAT; 
                    }
"double"			{
                        yylval.datatype = TypeDouble; 
                        printf("double "); return T_DOUBLE; 
                    }
"string"			{ 
   
                        yylval.datatype = TypeString; 
                        printf("string "); return T_STRING; 
                    }
(lie|truth)			{   char aux[100];  
                        sscanf(yytext, "%s", aux);
                        yylval.yybool = strcmp(aux, "lie") == 0 ? 0 : 1; 
                        yylval.yybool == 0 ? printf("bool(lie) ") : printf("bool(truth) "); 
                        return V_BOOL; /* bool */ 
                    }

[a-z][a-zA-Z0-9]*               {   
                                    sscanf(yytext, "%s", buffer); 
                                    yylval.yystring = buffer; 
                                    printf("v_id "); return V_ID; 
                                }

[a-zA-Z][a-zA-Z0-9]*\.fs        { printf("f_id "); return F_ID; }
[a-zA-Z][a-zA-Z0-9]*\.holo      { printf("m_id "); return M_ID; }

\'[a-zA-Z0-9]\'			{   char aux[3];
                            sscanf(yytext, "%s", aux); 
                            yylval.yychar = aux[1]; 
                            printf("char('%c') ", aux[1]); return V_CHAR; /* char */ 
                        }

[-+]?[0-9]+i?			{   int aux; 
                            sscanf(yytext, "%d", &aux);
                            yylval.yyint = aux; 
                            printf("int(%d) ", aux); return V_INT; /* int */ 
                        }
[-+]?[0-9]+\.?[0-9]*f?		{   float aux; 
                                sscanf(yytext, "%f", &aux); 
                                yylval.yyfloat = aux; 
                                printf("float(%f) ", aux); return V_FLOAT; /* float */ 
                            }

[-+]?[0-9]+\.?[0-9]*d		{   double aux; 
                                sscanf(yytext, "%lf", &aux);
                                yylval.yydouble = aux; 
                                printf("double(%lf) ", aux); return V_DOUBLE; /* double */ 
                            }

\"(\\.|[^"\\])*\"		{   
                            sscanf(yytext, "%s", buffer);
                            yylval.yystring = buffer; 
                            printf("string(%s) ", yylval.yystring); return V_STRING; /* string */ 
                        }


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

"=="				{   yylval.op = EEQ;
                        printf("== "); return MTH_DEQUA; }
">="				{   yylval.op = GTE;
                        printf(">= "); return MTH_GTEQ; }
"<="				{   yylval.op = LTE; 
                        printf("<= "); return MTH_LTEQ; }
"!="				{   yylval.op = NEQ; 
                        printf("!= "); return MTH_NOTEQ; }
"="				{   yylval.op = ASSIGN;
                    printf("= "); return MTH_SEQUA; }
">"				{   yylval.op = GT; 
                    printf("> "); return MTH_GT; }
"<"				{   yylval.op = LT;
                    printf("< "); return MTH_LT; }
"!"				{   yylval.op = NEG;   
                    printf("! "); return MTH_NOT; }
"+"				{   yylval.op = SUM;
                    printf("+ "); return MTH_PLUS; }
"-"				{   yylval.op = RES; 
                    printf("- "); return MTH_MINUS; }
"*"				{   yylval.op = MULT;
                    printf("* "); return MTH_ASTRK; }
"/"				{    yylval.op = DIV; 
                     printf("/ "); return MTH_DIVIS; }
"^^"				{   yylval.op = ROOT; 
                        printf("^^ "); return MTH_ROOT; }
"^"				{   yylval.op = POW; 
                    printf("^ "); return MTH_POWER; }
"&&"				{   yylval.op = AND; 
                        printf("&& "); return MTH_AND; }
"||"				{   yylval.op = OR; 
                        printf("|| "); return MTH_OR; }
"\t"                    {   printf("\t"); }
"    "                  {   printf("\t"); }
[ \v\f]			{ /* do nothing */}
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

