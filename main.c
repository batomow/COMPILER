#include <stdio.h> 
#include <stdlib.h> 
#include <jedi.h> 
#include <GLEW/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h> 

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

     
/*int testhash(Var key, int size){
	int hash = 0; 
	switch(key.type){
		
	}
	return hash; 
}*/

int main(){ 
	Var items[] = {NewVarI(11), NewVarS("Carlos"), NewVarC('D'), NewVarF(10.2)};
	Stack s1 = NewStackFromArray(items, 4); 
	s1.print(&s1); 

	int numitems[] = {1, 2, 3, 4, 5}; 
	Var* items2 = NewVarArrayI(numitems, 5); 

	Stack s2 = NewStackFromArrayRaw(TypeInt, numitems, 5); 
	s2.print(&s2); 

	Stack s3 = NewStackFromArray(items2, 5); 
	s3.print(&s3); 

        int err = OpenWindow(); 
        if (err)
            return err; 
        return 0; 
}
