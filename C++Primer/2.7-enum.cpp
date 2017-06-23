#include <iostream>

int main(){
    enum Points {a=2,b,c=3,d};
    std::cout << a << ","
              << b << ","
              << c << ","
              << d
              <<std::endl;
    Points p1 = d;
    Points p2;
    p2 = p1;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    return 0;
}
