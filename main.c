#include <stdio.h> 
#include <stdlib.h> 
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glut.h>

int main(int argc, char** argv){ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_RGB); 
	glutCreateWindow("GLEW test"); 
	/* Initialize GLEW */ 	
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}
	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

	return 0;
}
