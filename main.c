#include <stdio.h> 
#include <stdlib.h> 
#include <GL/glew.h>
#include <GL/gl.h> 
#include <GLFW/glfw3.h> 

int main(int argc, char** argv){ 
	GLFWwindow* window; 
	if(!glfwInit())
		return -1; 
	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL); 
	if(!window){
		glfwTerminate(); 
		return -1; 
	}
	glfwMakeContextCurrent(window); 

	/* Initialize GLEW */ 	
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	while(!glfwWindowShouldClose(window)){
		glClear(GL_COLOR_BUFFER_BIT); 
		glfwSwapBuffers(window); 
		glfwPollEvents(); 
	}
	glfwTerminate(); 

	return 0;
}
