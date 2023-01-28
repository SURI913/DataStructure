#include <iostream>
using namespace std;

class Rectangle {
	int width, hight;
public:
	Rectangle(int w = 0, int h =0): width{w}, hight{h} { }
	int getWidth() { return width; }
	int getHight() { return hight; }
	void setWidth(int w) { width = w; }
	void setHight(int h) { hight = h; }

	int area() { return width * hight; }
	int perimeter() { return 2 * (width + hight); }
};