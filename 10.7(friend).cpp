#include <iostream>
#include <math.h>
using namespace std;

class Point{
	private:
		float x;
		float y;
	public:
		Point(float a=0.0f, float b=0.0f):x(a),y(b){};
		friend float distance(Point& left, Point& right);

};

float distance(Point& left, Point& right){
	return sqrt((left.x - right.x)*(left.x - right.x) + (left.y - right.y)*(left.y - right.y));
}

int main(int argc, char const *argv[])
{
	Point p1(1.0,1.0);
	Point p2(2.0,2.0);
	cout << distance(p1,p2)<<endl;
	return 0;
}