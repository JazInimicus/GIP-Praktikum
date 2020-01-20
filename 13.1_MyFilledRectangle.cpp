#include "CImgGIP05.h" 
#include "MyFilledRectangle.h"

MyFilledRectangle::MyFilledRectangle(int x_1, int y_1, int x_2, int y_2) : MyRectangle(x_1, y_1, x_2, y_2) {}
void MyFilledRectangle::draw()
{
	gip_stop_updates();
	MyRectangle::draw();
	if (this->get_x1() + 2 < this->get_x2() - 2 && this->get_y1() + 2 < this->get_y2() - 2)
		for (int i = y1 + 2; i <= y2 - 2; i++)
			gip_draw_line(this->get_x1() + 2, i, this->get_x2() - 2, i, red);
	gip_start_updates();
}
