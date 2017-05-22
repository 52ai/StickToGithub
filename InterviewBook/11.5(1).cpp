#include <iostream>
#include <stdio.h>

using namespace std;

class Bird{
	public:
		void eat();
		void sleep();
		void fly();

};

class ostrich{
	public:
		Bird eat(){cout << "ostrich eat"<<endl;};
		Bird sleep(){cout << "ostrich sleep"<<endl;};

};

int main(int argc, char const *argv[])
{
	ostrich momo;

	momo.eat();
	momo.sleep();

	return 0;
}
