#include <iostream>
using namespace std;

class Base{
public:
	int val;
	Base(){val = 1;}

};

class Derive: public Base{
public:
	int val;
	Derive(int i){val = Base::val +i;}
};

int main(int argc, char const *argv[])
{
	Derive d(10);
	cout << d.Base::val<<endl;
	cout << d.val<<endl;
	return 0;
}