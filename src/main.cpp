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
  p2.add_point(10, 50);

  std::list<polygon> polygons;
  polygons.push_back(p);
  polygons.push_back(p2);
  //drawer::get_instance()->add_polygon(p, 0xffff0000);
  //drawer::get_instance()->add_polygon(p2, 0xffff00ff);
  //drawer::get_instance()->draw();

  std::list<uint32_t> colors;
  colors.push_back(0xffff0000);
  colors.push_back(0xffff00ff);

  std::vector<int> x_pos = p.scanline(50);
  printf("%d\n",x_pos[0]);

  fillo f(polygons, colors);
  f.fill_polygons();

  canvas::get_instance()->render();
  canvas::get_instance()->clear();
  return 0;
}
