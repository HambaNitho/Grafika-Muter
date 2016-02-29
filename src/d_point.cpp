#include "gl.hpp"
#include <math.h>
#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

int main () {

  point camera_pos(300,300,-100);
  double o_x = -0.1;
  double o_y = -0.5;
  double o_z = 0;

  point a(500,500,10);
  point b(700,500,10);
  point c(700,700,10);
  point d(500,700,10);
  
  int i = 0;

  while (i < 15) {
    o_y += i*0.01;
      
    line line_1(a.camera_tranform(camera_pos, o_x, o_y, o_z),
                b.camera_tranform(camera_pos, o_x, o_y, o_z));
    line line_2(b.camera_tranform(camera_pos, o_x, o_y, o_z),
                c.camera_tranform(camera_pos, o_x, o_y, o_z));
    line line_3(c.camera_tranform(camera_pos, o_x, o_y, o_z),
                d.camera_tranform(camera_pos, o_x, o_y, o_z));
    line line_4(d.camera_tranform(camera_pos, o_x, o_y, o_z),
                a.camera_tranform(camera_pos, o_x, o_y, o_z));

    // line_1.draw(0xffff0000);
    // line_2.draw(0xffff0000);
    // line_3.draw(0xffff0000);
    // line_4.draw(0xffff0000);


    

    point e(500,500,190);
    point f(700,500,190);
    point g(700,700,190);
    point h(500,700,190);

    line line_5(e.camera_tranform(camera_pos, o_x, o_y, o_z),
                f.camera_tranform(camera_pos, o_x, o_y, o_z));
    line line_6(f.camera_tranform(camera_pos, o_x, o_y, o_z),
                g.camera_tranform(camera_pos, o_x, o_y, o_z));
    line line_7(g.camera_tranform(camera_pos, o_x, o_y, o_z),
                h.camera_tranform(camera_pos, o_x, o_y, o_z));
    line line_8(h.camera_tranform(camera_pos, o_x, o_y, o_z),
                e.camera_tranform(camera_pos, o_x, o_y, o_z));

    // line_5.draw(0xff00ff00);
    // line_6.draw(0xff00ff00);
    // line_7.draw(0xff00ff00);
    // line_8.draw(0xff00ff00);

    line line_9(a.camera_tranform(camera_pos, o_x, o_y, o_z),
                e.camera_tranform(camera_pos, o_x, o_y, o_z));
    line line_10(b.camera_tranform(camera_pos, o_x, o_y, o_z),
                f.camera_tranform(camera_pos, o_x, o_y, o_z));
    line line_11(c.camera_tranform(camera_pos, o_x, o_y, o_z),
                g.camera_tranform(camera_pos, o_x, o_y, o_z));
    line line_12(d.camera_tranform(camera_pos, o_x, o_y, o_z),
                h.camera_tranform(camera_pos, o_x, o_y, o_z));

    polygon pdepan;
    pdepan.add_point(a.camera_tranform(camera_pos, o_x, o_y, o_z));
    pdepan.add_point(b.camera_tranform(camera_pos, o_x, o_y, o_z));
    pdepan.add_point(c.camera_tranform(camera_pos, o_x, o_y, o_z));
    pdepan.add_point(d.camera_tranform(camera_pos, o_x, o_y, o_z));

    polygon pbelakang;
    pbelakang.add_point(e.camera_tranform(camera_pos, o_x, o_y, o_z));
    pbelakang.add_point(f.camera_tranform(camera_pos, o_x, o_y, o_z));
    pbelakang.add_point(g.camera_tranform(camera_pos, o_x, o_y, o_z));
    pbelakang.add_point(h.camera_tranform(camera_pos, o_x, o_y, o_z));

    polygon patas;
    patas.add_point(a.camera_tranform(camera_pos, o_x, o_y, o_z));
    patas.add_point(e.camera_tranform(camera_pos, o_x, o_y, o_z));
    patas.add_point(f.camera_tranform(camera_pos, o_x, o_y, o_z));
    patas.add_point(b.camera_tranform(camera_pos, o_x, o_y, o_z));

    polygon pkanan;
    pkanan.add_point(b.camera_tranform(camera_pos, o_x, o_y, o_z));
    pkanan.add_point(f.camera_tranform(camera_pos, o_x, o_y, o_z));
    pkanan.add_point(g.camera_tranform(camera_pos, o_x, o_y, o_z));
    pkanan.add_point(c.camera_tranform(camera_pos, o_x, o_y, o_z));

    polygon pkiri;
    pkiri.add_point(a.camera_tranform(camera_pos, o_x, o_y, o_z));
    pkiri.add_point(e.camera_tranform(camera_pos, o_x, o_y, o_z));
    pkiri.add_point(h.camera_tranform(camera_pos, o_x, o_y, o_z));
    pkiri.add_point(d.camera_tranform(camera_pos, o_x, o_y, o_z));
    
    // line_9.draw();
    // line_10.draw();
    // line_11.draw();
    // line_12.draw();



    if (o_y < 0) {
      drawer::get_instance()->add_polygon(pkiri, 0xff383838);
      drawer::get_instance()->add_polygon(patas, 0xff989898);
      drawer::get_instance()->add_polygon(pdepan, 0xff4D4D4D);
      drawer::get_instance()->add_polygon(pkanan, 0xffFFFFFF);
    } else {
      drawer::get_instance()->add_polygon(pkanan, 0xffFFFFFF);
      drawer::get_instance()->add_polygon(patas, 0xff989898);
      drawer::get_instance()->add_polygon(pdepan, 0xff4D4D4D);
      drawer::get_instance()->add_polygon(pkiri, 0xff383838);
    }
    

    usleep(100000);
    drawer::get_instance()->draw();
    canvas::get_instance()->render();
    canvas::get_instance()->clear();
    i++;
  }

  
  return 0;
}
