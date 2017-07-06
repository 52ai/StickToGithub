#include <iostream>
using namespace std;

void reset(int *ip){
    *ip = 0;
    ip =0;
}

int foo1(int, const int*);
void myswap1(int*, int*);
void myswap2(int&, int&);
void myswap3(int*&, int*&);
int main(){
    int i =42;
    int *ip = &i;
    cout << "i: "<<i<<",ip: "<<ip<<endl;
    reset(ip);
    cout << "i: "<<i<<",ip: "<<ip<<endl;
    int x, y;
    cin >> x>>y;
    cout << "foo1(int, const int*): " << foo1(x, &y)<<endl;
    cout << "x,y: "<<x<<" , "<<y<<endl;
    myswap1(&x,&y);
    cout << "x,y: "<<x<<" , "<<y<<endl;
    myswap2(x,y);
    cout << "x,y: "<<x<<" , "<<y<<endl;

    int *xp = &x;
    int *yp = &y;
    cout << "*xp,*yp: " << *xp << " , " << *yp <<endl;
    myswap3(xp , yp);
    cout << "*xp,*yp: " << *xp << " , " << *yp <<endl;

    return 0;
}

int foo1(int a, const int* bp){

    return a >= *bp?a:*bp;
}

void myswap1(int* ap, int* bp){

    int temp=*ap;
    *ap = *bp;
    *bp = temp;
}
void myswap2(int& a, int & b){
    int temp = a;
    a=b;
    b=temp;

}
void myswap3(int* &ap, int* &bp){
    int* temp = ap;
    ap = bp;
    bp = temp;
}


