#include <windows.h>

#include <GL/glut.h>

#include <stdlib.h>
#include <stdio.h>

void display(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Define a cor de fundo da cena (cor usada para limpar o buffer de cor)
	glClear(GL_COLOR_BUFFER_BIT);//Inicializa o buffer de cores antes de ele ser alterado

	glMatrixMode(GL_MODELVIEW); //Informa que as operações seguintes serão executadas na matrix modelview
	glLoadIdentity(); //Carrega a matriz identidade


	  
    //Parede da Porta
	glBegin(GL_QUADS);
     	glColor3f(0.9f, 0.0f, 0.0f);
		glVertex2f(-0.2f,-0.2f);
		glVertex2f(0.2f, -0.2f);       
		glVertex2f(0.2f, 0.2f);       
		glVertex2f(-0.2f, 0.2f);
	glEnd();//Encerra a criação de pontos
	
	//Porta
	glBegin(GL_QUADS);
     	glColor3f(0.7f, 0.0f, 0.5f);
		glVertex2f(-0.1f,-0.2f);
		glVertex2f(0.1f, -0.2f);    
		glVertex2f(0.1f, 0);       
		glVertex2f(-0.1f, 0);
	glEnd();//Encerra a criação de pontos
	

	//Ma�aneta Porta
	glPointSize(6); //Define quantos pixels representarão um vértice na tela
		glBegin(GL_POINTS);{
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(-0.05f, -0.1);
		}
		glEnd();
		
	//TELHADO FRENTE
	glBegin(GL_TRIANGLES);
	    glColor3f(0.0f, 0.9f, 0.0f); 
	    glVertex2f(0.2f, 0.2f); 
		glVertex2f(0, 0.4f);          
		glVertex2f(-0.2f, 0.2f);
	       
	glEnd();  
	
	//TELHADO
	glBegin(GL_POLYGON);
     	glColor3f(0.0f, 0.0f, 0.6f);
		glVertex2f(0.2f, 0.2f); 
		glVertex2f(0, 0.4f); 
		glVertex2f(0.75f, 0.4f);
		glVertex2f(0.95f, 0.2f);          
		glVertex2f(0.75f, 0.4f);   
		
	glEnd();
	
	//PAREDE
   glBegin(GL_QUADS);
     	glColor3f(0.0f, 0.0f, 0.2f);
		glVertex2f(0.2f, -0.2f);       
		glVertex2f(0.2f, 0.2f);
		glVertex2f(0.95f, 0.2f);              
		glVertex2f(0.95f, -0.2f);
		
	glEnd();
	
	//Janelas
	glBegin(GL_QUADS);
     	glColor3f(0.0f, 0.4f, 0.0f);
		glVertex2f(0.25f, 0.010f);       
		glVertex2f(0.25f, 0.13f);
		glVertex2f(0.50f, 0.13f);              
		glVertex2f(0.50f, 0.010f);
		
	glEnd();
	
	//Janelas
	glBegin(GL_QUADS);
     	glColor3f(0.0f, 0.4f, 0.0f);
		glVertex2f(0.60f, 0.010f);       
		glVertex2f(0.60f, 0.13f);
		glVertex2f(0.85f, 0.13f);              
		glVertex2f(0.85f, 0.010f);
		
	glEnd();
	
	//Linhas Janelas
	glLineWidth(2);
	    glBegin(GL_LINES);{
	    glColor3f(0.0f, 0.0f, 1.0f);
     	glVertex2f(0.25f, 0.07f);
		glVertex2f(0.50f, 0.07f); 
		
	}
	glLineWidth(2);
	    glBegin(GL_LINES);{
	    glColor3f(0.0f, 0.0f, 1.0f);
     	glVertex2f(0.37f, 0.01f);
		glVertex2f(0.37f, 0.13f); 
		
	}
		
		
	glEnd();
	
	//Linhas Janelas
	glLineWidth(2);
		glBegin(GL_LINES);{
		glColor3f(0.0f, 0.0f, 1.0f);
	    glVertex2f(0.60f, 0.07f); 
	    glVertex2f(0.85f, 0.07f); 
	    
	}
		glLineWidth(2);
	    glBegin(GL_LINES);{
	    glColor3f(0.0f, 0.0f, 1.0f);
     	glVertex2f(0.72f, 0.01f);
		glVertex2f(0.72f, 0.13f); 
		
	}	
		
	glEnd();
	
	//Sombra da porta
	glBegin(GL_QUADS);
     	glColor3f(0.0f, 0.0f, 0.4f);
		glVertex2f(-0.1f,-0.2f);
		glVertex2f(0.1f, -0.2f);    
		glVertex2f( 0.1f, -0.35f);          
		glVertex2f(-0.25f, -0.35f);
		
	glEnd();
	
	

	glFlush(); //Informa que as operações devem ser processadas imediatamente e exibidas na tela
}
	

/*Recebe um o comprimento (width) e altura (height) da janela em pixels.*/
void resize(GLsizei w, GLsizei h) {
	if (h == 0)
		h = 1;

	printf("Tam. janela: (%i,%i)\n",w,h);
}

/*Recebe um código para cada tecla (ASCII) e as coordenadas do mouse.*/
void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 27:
		exit(0);
		break;
	case 32:
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Define a cor de fundo da cena (cor usada para limpar o buffer de cor)
		break;
	default:
		printf("Código tecla: %i. Mouse em (%i,%i)\n",key,x,y);
		break;
	}
	glutPostRedisplay(); //Informa que a janela atual deve ser redesenhada
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv); //Inicializa a OpenGL
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Configura os modos de exibição (mais detalhes no futuro)
	glutInitWindowSize(500, 500); //Define o tamanho da janela em pixels
	glutInitWindowPosition(0, 0); //Define a posição inicial da janela
	glutCreateWindow("Primeiro Exemplo"); //Cria a janela especificando seu título
	glutDisplayFunc(display); //Especifica a função de rendering (exibe a cena no loop)
	glutReshapeFunc(resize); //Especifica função a ser executada quando a janela é redimensionada
	glutKeyboardFunc(keyboard); //Especifica função a ser executada quando uma tecla é pressionada

	glutMainLoop(); //Executa o loop de renderização
	return 0;
}
