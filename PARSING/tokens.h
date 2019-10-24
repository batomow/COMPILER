/* ---- TOKEN DEFINITION ---- */


/* General symbols */
#define SYM_OBRAC 100	// "[" Open Bracket 
#define SYM_CBRAC 101	// "]" Close Bracket 
#define SYM_OPARE 102	// "(" Open Parenthesis 
#define SYM_CPARE 103	// ")" Close Parenthesis 
#define SYM_OCURL 104	// "{" Open Curly Braces 
#define SYM_CCURL 105	// "}" Close Curly Braces 
#define SYM_COMMA 106	// "," Comma 
#define SYM_ARROW 107	// "->" Arrow 
#define SYM_COLON 108	// ":" Colon 

/* Mathematical and logical symbols */
#define MTH_SEQUA 200	// "=" Single equal sign 
#define MTH_DEQUA 201	// "==" Doble equal sign 
#define MTH_GT 202		// ">" Greater than
#define MTH_LT 203		// "<" Less than 
#define MTH_GTEQ 204	// ">=" Greater than or equal
#define MTH_LTEQ 205	// "<=" Less than or equal
#define MTH_NOT 206   	// "!" Logical not
#define MTH_NOTEQ 207	// "!=" Not equal
#define MTH_PLUS 208	// "+" Plus sign
#define MTH_MINUS 209	// "-" Minus sign
#define MTH_ASTRK 210	// "*" Asterisk
#define MTH_DIVIS 211	// "/" Forward Slash
#define MTH_POWER 212	// "^" Power sign
#define MTH_ROOT 213	// "^^" Double power sign, used for roots 
#define MTH_AND 214		// "&&" Logical AND
#define MTH_OR 215		// "||" Logical OR

/* White-space and new line characters */
#define LF 300			//Line-feed
#define CR 301			// Carriage return
#define TWS 302 		// Tab or white-space

/* Reserved words used for file, variable and scene management */
#define RES_MSCN 400	// "MAINSCENE"
#define RES_SCNS 401	// "SCENES"
#define RES_DPLY 402	// "deploy"
#define V_ID 403		// Variable Id
#define F_ID 404		// File Id (followed by .fs)
#define M_ID 405		// Module Id (followed by .holo)

/* Logical structures reserved keywords */
#define LOG_IF 500		// "if" reserved for if structure
#define LOG_ELIF 501	// "elif" reserved for elif structure
#define LOG_ELSE 502	// "else" reserved for else structure
#define LOG_FOR 503		// "for" reserved for for structure
#define LOG_WHILE 504	// "while" reserved for while structure

/* Data types and var reserved word */
#define V_VAR 600		// "var" reserved word
#define V_CHAR 601		// Constant of type char
#define V_STRING 602	// Constant of type string
#define V_FLOAT 602		// Constant of type float
#define V_INT 603		// Constant of type int
#define V_DOUBLE 604	// Constant of type Double
#define V_BOOL 605		// Constant of type boolean (truth|lie)
#define V_MAT 606		// "mat" reserved word
#define V_MAT4 607		// "mat4" reserved word
#define V_MAP 607		// "map" reserved word

/* Orders reserved words */
#define RES_ORDER 700	// "order" reserved word
#define RES_XRDER 701	// "execute order" reserved words
#define RES_MEDIT 702	// "meditate" reserved word
#define RES_RETRN 703	// "return" reserved word

