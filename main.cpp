/*
	Debmeet   2018A7PS0385H
	Anirudh   2018A7PS0673H
	Sri Chand 2017A7PS0272H
*/
/* Compile using ------------> g++ main.cpp linecircle.cpp tidieralgo.cpp -lglut -lGL -lGLU */
#include <iostream>
#include "tidieralgo.h"
#include "linecircle.h"
#include <vector>
#include <GL/glut.h>
using namespace std;
void init() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//Use single refresh buffer and RGB color mode
																							   //refresh buffer is responsible for updating contents of a window when refresh is performed.
	glutInitWindowPosition(100, 100);//Position of the Window
	glutInitWindowSize(1366, 768);//Size of the Window
	glutCreateWindow("Computer Graphics Assignment"); //Creates a Window with given title
	glClearColor(0.0, 0.0, 0.0, 0);//BackgroundColor
	glColor3f(1.0, 1.0, 1.0);
	gluOrtho2D(0, 1366,0,768);//World Window limits(x,x,y,y)
}
tree *t;//pointer to tree class in tidieralgo.h
void drawTidierTree(void)//user defined function to draw
{
	t->Tidier();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);//Initialing the OpenGL Utility Toolkit
	init();
	int menu_decision, n;
	cout << "Computer Graphics Assignment" << endl;
rego:
	cout << "Make Trees" << endl;
	cout << " 1. Random tree with n vertices" << endl;
	cout << " 2. Balanced tree with n vertices" << endl;
	cout << "Enter your Choice: ";
	cin >> menu_decision;
	cout << endl<< "Enter n: ";
	cin >> n;
	if (menu_decision == 1)
		t = new tree(n, false);
	else if (menu_decision == 2)
		t = new tree(n, true);
	else 
		goto rego;
	glutDisplayFunc(drawTidierTree);//Draws the picture(user defined) on Display Window
	glutMainLoop();//Finishes the window processing operations
	int x;
	cin >> x;//just to hold the window in place
	return 0;
}
