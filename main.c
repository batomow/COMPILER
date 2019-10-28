#include <stdio.h> 
#include <stdlib.h> 
#include <jedi.h> 
#include <string.h> 
#include <GLEW/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h> 
#include <tokens.h> 
#define PRIME 57

int OpenWindow(){
    GLFWwindow* window;
    
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    
    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    GLenum err = glewInit();
   
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    fprintf(stdout, "Supported OpenGL: %s\n", glGetString(GL_VERSION)); 
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        
        /* Poll for and process events */
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0; 

}

unsigned int testHash(char* word){
    unsigned int hash = 0; 
    for(hash = 0; *word != '\0'; word++){
       hash = hash << 1; 
       hash = hash^(*word); 
    }
    return hash;  
}

/*unsigned int testHash2(char* word){
    unsigned int hash = 0; 
    for(unsigned int hash = 0, pow = 0; *word != '\0'; word++, pow++){
        printf("%d\t%d", (int)(*word), (pow); 
    }
    return hash; 
}*/

char* showBitsLetter(char letter){
    char* result = (char*)calloc(sizeof(char), 9); 
    int counter = 0; 
    for(int i = 7; i >=0; i--){
       result[counter] = ((1 << i) & letter) ? '1' : '0';
       counter++; 
    }
    result[8] = '\0'; 
    return result; 
}

char** showBitsWord(char* word, int size){
    char** result = (char**)calloc(sizeof(char*), size); 
    for(int n = 0; n<size; n++){
        result[n] = showBitsLetter(word[n]); 
    }
    return result; 
}

KeyValuePair* fillMap(int size){
    KeyValuePair* newMap = (KeyValuePair*)calloc(size+1, sizeof(KeyValuePair)); 
    newMap[0] = NewKeyValuePair(NewVarI(size), NewVarI(size)); //size cheat
    newMap[1] = NewKeyValuePair(NewVarI(100), NewVarS("[")); 
    newMap[2] = NewKeyValuePair(NewVarI(101), NewVarS("]")); 
    newMap[3] = NewKeyValuePair(NewVarI(102), NewVarS("(")); 
    newMap[4] = NewKeyValuePair(NewVarI(103), NewVarS(")")); 
    newMap[5] = NewKeyValuePair(NewVarI(104), NewVarS("{")); 
    newMap[6] = NewKeyValuePair(NewVarI(105), NewVarS("}")); 
    newMap[7] = NewKeyValuePair(NewVarI(106), NewVarS(",")); 
    newMap[8] = NewKeyValuePair(NewVarI(107), NewVarS("->")); 
    newMap[9] = NewKeyValuePair(NewVarI(108), NewVarS(":")); 

    newMap[10] = NewKeyValuePair(NewVarI(200), NewVarS("=")); 
    newMap[11] = NewKeyValuePair(NewVarI(201), NewVarS("==")); 
    newMap[12] = NewKeyValuePair(NewVarI(202), NewVarS(">")); 
    newMap[13] = NewKeyValuePair(NewVarI(203), NewVarS("<")); 
    newMap[14] = NewKeyValuePair(NewVarI(204), NewVarS(">=")); 
    newMap[15] = NewKeyValuePair(NewVarI(205), NewVarS("<=")); 
    newMap[16] = NewKeyValuePair(NewVarI(206), NewVarS("!")); 

    newMap[17] = NewKeyValuePair(NewVarI(207), NewVarS("!=")); 
    newMap[18] = NewKeyValuePair(NewVarI(208), NewVarS("+")); 
    newMap[19] = NewKeyValuePair(NewVarI(209), NewVarS("-")); 
    newMap[20] = NewKeyValuePair(NewVarI(210), NewVarS("*")); 
    newMap[21] = NewKeyValuePair(NewVarI(211), NewVarS("/")); 
    newMap[22] = NewKeyValuePair(NewVarI(212), NewVarS("^")); 
    newMap[23] = NewKeyValuePair(NewVarI(213), NewVarS("^^")); 
    newMap[24] = NewKeyValuePair(NewVarI(214), NewVarS("*&&")); 
    newMap[25] = NewKeyValuePair(NewVarI(215), NewVarS("||")); 


    newMap[26] = NewKeyValuePair(NewVarI(300), NewVarS("\\n")); 
    newMap[27] = NewKeyValuePair(NewVarI(301), NewVarS("\\r")); 
    newMap[28] = NewKeyValuePair(NewVarI(302), NewVarS("\\t")); 

    newMap[29] = NewKeyValuePair(NewVarI(400), NewVarS("MAINSCENE")); 
    newMap[30] = NewKeyValuePair(NewVarI(401), NewVarS("SCENES")); 
    newMap[31] = NewKeyValuePair(NewVarI(402), NewVarS("deploy")); 
    newMap[32] = NewKeyValuePair(NewVarI(403), NewVarS("ID")); 
    newMap[33] = NewKeyValuePair(NewVarI(404), NewVarS("FileID")); 
    newMap[34] = NewKeyValuePair(NewVarI(405), NewVarS("ModuleID")); 

    newMap[35] = NewKeyValuePair(NewVarI(500), NewVarS("if")); 
    newMap[36] = NewKeyValuePair(NewVarI(501), NewVarS("elif")); 
    newMap[37] = NewKeyValuePair(NewVarI(502), NewVarS("else")); 
    newMap[38] = NewKeyValuePair(NewVarI(503), NewVarS("for")); 
    newMap[39] = NewKeyValuePair(NewVarI(504), NewVarS("while")); 

    newMap[40] = NewKeyValuePair(NewVarI(600), NewVarS("var")); 
    newMap[41] = NewKeyValuePair(NewVarI(601), NewVarS("char")); 
    newMap[42] = NewKeyValuePair(NewVarI(602), NewVarS("string")); 
    newMap[43] = NewKeyValuePair(NewVarI(603), NewVarS("float")); 
    newMap[44] = NewKeyValuePair(NewVarI(604), NewVarS("int")); 
    newMap[45] = NewKeyValuePair(NewVarI(605), NewVarS("double")); 
    newMap[46] = NewKeyValuePair(NewVarI(606), NewVarS("bool")); 
    newMap[47] = NewKeyValuePair(NewVarI(607), NewVarS("mat")); 
    newMap[48] = NewKeyValuePair(NewVarI(608), NewVarS("mat4")); 
    newMap[49] = NewKeyValuePair(NewVarI(609), NewVarS("map")); 

    newMap[50] = NewKeyValuePair(NewVarI(700), NewVarS("order")); 
    newMap[51] = NewKeyValuePair(NewVarI(701), NewVarS("execute order")); 
    newMap[52] = NewKeyValuePair(NewVarI(702), NewVarS("meditate")); 
    newMap[53] = NewKeyValuePair(NewVarI(703), NewVarS("return")); 

    newMap[54] = NewKeyValuePair(NewVarI(800), NewVarS("//Comment"));
    newMap[55] = NewKeyValuePair(NewVarI(801), NewVarS("/* multiline comment */")); 
    newMap[56] = NewKeyValuePair(NewVarI(610), NewVarS("vector")); 
    newMap[57] = NewKeyValuePair(NewVarI(704), NewVarS("station")); 
    newMap[58] = NewKeyValuePair(NewVarI(705), NewVarS("element")); 
    newMap[59] = NewKeyValuePair(NewVarI(611), NewVarS("enum")); 
    return newMap; 
}

char* getValue(KeyValuePair* map, int key){
   int size = map[0].value.data.iVal;
   char* value = ""; 
   for(int n = 1; n<size; n++){
       if(key == map[n].key.data.iVal){
           value = map[n].value.data.sVal;
       }
   }
   return value; 
}

extern int yylex();
extern int yylineno;
extern char* yytext;  

int main(){ 
    KeyValuePair* psudo_map = fillMap(60); 
    int ntoken = yylex();
    while(ntoken){
        if(ntoken == 300){
            printf("LF\n"); 
        }else if (ntoken == 301){
            printf("CR\r"); 
        }else if(ntoken == 302){
            printf("\t"); 
        }else{
            printf("%s ", getValue(psudo_map, ntoken)); 
        }
        ntoken = yylex(); 
    }
    free(psudo_map); 
    return 0; 
}
