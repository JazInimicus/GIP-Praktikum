#pragma once
#include "MyRectangle.h"
class MyFilledRectangle : public MyRectangle
{
public:
	MyFilledRectangle(int x_1 = 0, int y_1 = 0, int x_2 = 20, int y_2 = 20);
	void draw();

};
