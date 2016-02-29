#include <iostream>
#include "gl.hpp"

using namespace std;

int main() {
  polygon p;
  p.add_point(0, 0);
  p.add_point(50, 20);
  p.add_point(50, 30);
  p.add_point(0, 50);


  polygon p2;
  p2.add_point(30, 0);
  p2.add_point(50, 50);
  p2.add_point(30, 70);
  p2.add_point(0, 50);


  drawer::get_instance()->add_polygon(p, 0xffff0000);
  drawer::get_instance()->add_polygon(p2, 0xffff00ff);
  drawer::get_instance()->draw();

  canvas::get_instance()->render();
  canvas::get_instance()->clear();
  return 0;
}
