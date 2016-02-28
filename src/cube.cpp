#include "cube.hpp"

cube::cube(point p1, int edge_){
	edge = edge_;
	
	point p2(p1.get_x()+edge, p1.get_y(), p1.get_z());
	point p3(p1.get_x()+edge, p1.get_y()-edge, p1.get_z());
	point p4(p1.get_x(), p1.get_y()-edge, p1.get_z());

	point p5(p1.get_x(), p1.get_y(), p1.get_z()+edge);
	point p6(p5.get_x()+edge, p5.get_y(), p5.get_z());
	point p7(p5.get_x()+edge, p5.get_y()-edge, p5.get_z());
	point p8(p5.get_x(), p5.get_y()-edge, p5.get_z());

	pl1.add_point(p1);
	pl1.add_point(p2);
	pl1.add_point(p3);
	pl1.add_point(p4);
	
	pl2.add_point(p2);
	pl2.add_point(p6);
	pl2.add_point(p7);
	pl2.add_point(p3);

	pl3.add_point(p5);
	pl3.add_point(p6);
	pl3.add_point(p7);
	pl3.add_point(p8);

	pl4.add_point(p1);
	pl4.add_point(p5);
	pl4.add_point(p8);
	pl4.add_point(p4);
	
	pl5.add_point(p5);
	pl5.add_point(p6);
	pl5.add_point(p2);
	pl5.add_point(p1);

	pl6.add_point(p8);
	pl6.add_point(p7);
	pl6.add_point(p3);
	pl6.add_point(p5);	
}

cube::~cube(){
	
}

polygon cube::get_side(int s){
	switch(s){
		case 1: return pl1;
		case 2: return pl2;
		case 3: return pl3;
		case 4: return pl4;
		case 5: return pl5;
		case 6: return pl6;
	}
}
