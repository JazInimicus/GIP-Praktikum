#include "CImgGIP05.h" 
#include "MyRectangle.h"
void MyRectangle::set_x1(int x) { x1 = x; }
void MyRectangle::set_y1(int x) { y1 = x; }
void MyRectangle::set_x2(int x) { x2 = x; }
void MyRectangle::set_y2(int x) { y2 = x; }
int MyRectangle::get_x1() const { return x1; }
int MyRectangle::get_y1() const { return y1; }
int MyRectangle::get_x2() const { return x2; }
int MyRectangle::get_y2() const { return y2; }
void MyRectangle::set(int x_1, int y_1, int x_2, int y_2) { set_x1(x_1); set_y1(y_1); set_x2(x_2); set_y2(y_2); }
void MyRectangle::draw() { gip_draw_rectangle(x1, y1, x2, y2, blue); }
bool MyRectangle::does_not_collide_with(const MyRectangle& other) { return (this->get_x2() < other.get_x1() || other.get_x2() < this->get_x1() || other.get_y1() > this->get_y2() || this->get_y1() > other.get_y2()); }