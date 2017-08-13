#include <iostream>

using namespace std;

int main(){
    int x,f,d,p;
    cin >> x >> f >> d >> p;
    if(d < x){
        cout << "0";
    }
    else if (d >= x && f >=1 && d <= f*x){
        cout << d/x;

    }
    else if( d > f*x && f >= 1){
        cout << (d-f*x)/(x+p) + f ;

    }

    return 0;
}
