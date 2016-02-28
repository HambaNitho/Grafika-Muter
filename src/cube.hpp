#ifndef CUBE_H
#define CUBE_H

#include "point.h"

class cube{
public:
	cube(point p1_, int edge_);
	~cube();
	
private:
	point p1;
	point p2;
	point p3;
	point p4;
	point p5;
	point p6;
	point p7;
	point p8;
	int edge;
};
#endif