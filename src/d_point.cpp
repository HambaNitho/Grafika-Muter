#include "gl.hpp"
#include <math.h>

int main () {

  point camera_pos(300,300,-100);
  double o_x = -0.1;
  double o_y = -0.5;
  double o_z = 0;

  point a(500,500,10);
  point b(700,500,10);
  point c(700,700,10);
  point d(500,700,10);

  line line_1(a.camera_tranform(camera_pos, o_x, o_y, o_z),
              b.camera_tranform(camera_pos, o_x, o_y, o_z));
  line line_2(b.camera_tranform(camera_pos, o_x, o_y, o_z),
              c.camera_tranform(camera_pos, o_x, o_y, o_z));
  line line_3(c.camera_tranform(camera_pos, o_x, o_y, o_z),
              d.camera_tranform(camera_pos, o_x, o_y, o_z));
  line line_4(d.camera_tranform(camera_pos, o_x, o_y, o_z),
              a.camera_tranform(camera_pos, o_x, o_y, o_z));

  line_1.draw(0xffff0000);
  line_2.draw(0xffff0000);
  line_3.draw(0xffff0000);
  line_4.draw(0xffff0000);

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

  line_5.draw(0xff00ff00);
  line_6.draw(0xff00ff00);
  line_7.draw(0xff00ff00);
  line_8.draw(0xff00ff00);

  line line_9(a.camera_tranform(camera_pos, o_x, o_y, o_z),
              e.camera_tranform(camera_pos, o_x, o_y, o_z));
  line line_10(b.camera_tranform(camera_pos, o_x, o_y, o_z),
              f.camera_tranform(camera_pos, o_x, o_y, o_z));
  line line_11(c.camera_tranform(camera_pos, o_x, o_y, o_z),
              g.camera_tranform(camera_pos, o_x, o_y, o_z));
  line line_12(d.camera_tranform(camera_pos, o_x, o_y, o_z),
              h.camera_tranform(camera_pos, o_x, o_y, o_z));

  line_9.draw();
  line_10.draw();
  line_11.draw();
  line_12.draw();

  canvas::get_instance()->render();
  return 0;
}
