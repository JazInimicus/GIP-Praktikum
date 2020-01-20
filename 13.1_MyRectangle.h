#pragma once
class MyRectangle {
protected:
	int x1, y1; //Linke obere Ecke
	int x2, y2; //Rechte untere Ecke

public:
	MyRectangle(int x_1 = 0, int y_1 = 0, int x_2 = 20, int y_2 = 20) { set(x_1, y_1, x_2, y_2); }
	void set_x1(int x);
	void set_y1(int x);
	void set_x2(int x);
	void set_y2(int x);
	int get_x1() const;
	int get_y1() const;
	int get_x2() const;
	int get_y2() const;
	void set(int x_1, int y_1, int x_2, int y_2);
	void draw();
	bool does_not_collide_with(const MyRectangle& other);
};

