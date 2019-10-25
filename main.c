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

extern int yylex();
extern int yylineno;
extern char* yytext; 

int main(){ 
    int ntoken = yylex();
    int counter = 0; 
    while(ntoken){
        printf("%d  ", ntoken); 
        ntoken = yylex(); 
        counter++; 
        if(counter >= 10){
            printf(" line: %d\n", yylineno); 
            counter = 0; 
        }
    }
    return 0; 
}
