#include "linecircle.h"
#include <math.h>
#include <GL/glut.h>
/*! Lights up a pixel using OpenGL */
void draw_pixel(GLint x, GLint y)
{
	glColor3f(1.0, 1.0, 0.0);//object color
	glPointSize(1.7);//sets the size of points to be drawn (in pixels)
	glBegin(GL_POINTS);//writes pixels on the frame buffer with the current drawing color
	glVertex2i(x,500-y);//subtracted because otherwise the tree was going below
	glEnd();
}
void draw_liney(int x1, int y1, int x2, int y2)
{
	if(y2 > y1)
	{
		int dx = x2 - x1;
		int dy = abs(y2 - y1);
		int d = 2 * dy - dx;//decision variable
		int incrE = 2 * dy;
		int incrNE = 2 * (dy - dx);
		int x = x1;
		int y = y1;
		draw_pixel(x, y);
		while (x < x2)
		{
			if (d <= 0)
			d += incrE;
			else
			{
				d += incrNE;
				y ++;
			}
			x++;
			draw_pixel(x, y);
		}
	}
	else
	{
		int dx = x2 - x1;
		int dy = abs(y2 - y1);
		int d = 2 * dy - dx;
		int incrE = 2 * dy;
		int incrNE = 2 * (dy - dx);
		int x = x1;
		int y = y1;
		draw_pixel(x, y);
		while (x < x2)
		{
			if (d <= 0)
				d += incrE;
			else
			{
				d += incrNE;
				y--;
			}	
			x++;
			draw_pixel(x, y);
		}
	}
}
void draw_linex(int x1, int y1, int x2, int y2)
{
	if(x2>x1)
	{
		int dx = abs(x2 - x1);
		int dy = y2 - y1;
		int d = 2 * dx - dy;
		int incrE = 2 * dx;
		int incrNE = 2 * (dx - dy);
		int x = x1;
		int y = y1;
		draw_pixel(x, y);
		while (y < y2)
		{
			if (d <= 0)
				d += incrE;
			else
			{
				d += incrNE;
				x++;
			}
			y++;
			draw_pixel(x, y);
		}
	}
	else
	{
		int dx = abs(x2 - x1);
		int dy = y2 - y1;
		int d = 2 * dx - dy;
		int incrE = 2 * dx;
		int incrNE = 2 * (dx - dy);
		int x = x1;
		int y = y1;
		draw_pixel(x, y);
		while (y < y2)
		{
			if (d <= 0)
				d += incrE;
			else
			{
				d += incrNE;
				x--;
			}
			y++;
			draw_pixel(x, y);
		}
	}
}
/*! Bresenham Algorithm for drawing line */
void line(int x1, int y1, int x2, int y2)
{
	if ((x2 >= x1) && (y2 >= y1))
	{
		if (x2 - x1 > y2 - y1)
			draw_liney(x1, y1, x2, y2);
		else
			draw_linex(x1, y1, x2, y2);
	}
	else if ((x2 >= x1) && (y2 < y1))
	{
		if (x2 - x1 > y1 - y2)
			draw_liney(x1, y1, x2, y2);
		else
			draw_linex(x2, y2, x1, y1);
	}
	else
		line(x2, y2, x1, y1);
}
void primitives::draw_line(void)
{
	line(x1, y1,x2,y2);
	glFlush(); //empties all buffers, causing all issued commands to be executed ASAP
}
void plot_circle(int x, int y, int cx, int cy)
{
	//using the 8Way symmetry
	draw_pixel(cx + x, cy + y);
	draw_pixel(cx - x, cy + y);
	draw_pixel(cx + x, cy - y);
	draw_pixel(cx - x, cy - y);
	draw_pixel(cx + y, cy + x);
	draw_pixel(cx - y, cy + x);
	draw_pixel(cx + y, cy - x);
	draw_pixel(cx - y, cy - x);
}
/*! Mid-point algorithm */
void circle(int cx, int cy, int r)
{
	int x = 0;
	int y = r;
	int d = 1 - r;
	int deltaE = 3;
	int deltaSE = -2 * r + 5;
	plot_circle(x, y, cx, cy);
	while (y > x)
	{
		if (d < 0)
		{
			d += deltaE;
			deltaE += 2;
			deltaSE += 2;
		}
		else
		{
			d += deltaSE;
			deltaE += 2;
			deltaSE += 4;
			--y;
		}
		++x;
		plot_circle(x, y, cx, cy);
	}
}
/*! This function draws the circle */
void primitives::draw_circle(void)
{
	for(int i=radius;i>=0;i--)
		circle(cx, cy, i);
	glFlush(); //empties all buffers, causing all issued commands to be executed ASAP
}
/*! This function sets the object to be used as a line between two points(given their x,y coordinates) */
void primitives::use_line(int sx1, int sy1, int sx2, int sy2)
{
	x1 = sx1;
	x2 = sx2;
	y1 = sy1;
	y2 = sy2;
	cx = 0;
	cy = 0;
	radius = 0;
}
/*! This function sets the object to be used as a circle with center coordinates and radius */
void primitives::use_circle(int scx, int scy, int sradius)
{
	cx = scx;
	cy = scy;
	radius = sradius;
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
}

