#include <iostream>
#include <cmath>
using namespace std;

int foo1(int, int);
int foo2(int);
int main(){
    int x, y, z;
    cin >> x >> y >> z;
    cout << "foo1(x,y): " << foo1(x,y) <<endl;
    cout << "foo2(z):" << foo2(z) <<endl;

    return 0;
}

int foo1(int a, int b){

    //return pow(a,b);
    int result = 1;
    for(int loop=0; loop < b; ++loop){
        result *= a;
    }
    return result;


}

int foo2(int a){

    //return abs(a);
    return a >=0 ? a:-a;
}
