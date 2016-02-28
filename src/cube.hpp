#ifndef CUBE_H
#define CUBE_H

#include "point.hpp"
#include "polygon.hpp"

class cube{
public:
	cube(point p1_, int edge_);
	~cube();
	polygon get_side(int s);
	
private:
	polygon pl1;
	polygon pl2;
	polygon pl3;
	polygon pl4;
	polygon pl5;
	polygon pl6;
	int edge;
};
#endif