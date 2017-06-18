#include <iostream>
int main(){
    int ival = 1024;
    int &refVal = ival;
    std::cout << "ival:" << ival << "\n"
              << "refVal:" << refVal
              <<std::endl;
    refVal = 2048;
    std::cout << "ival:" << ival << "\n"
          << "refVal:" << refVal
          <<std::endl;

    int &r1=refVal, &r2=r1;
    r1 = 4096;
    std::cout << "ival:" << ival << "\n"
      << "refVal:" << refVal << "\n"
      << "r1:" << r1 << "\n"
      << "r2:" << r2 << "\n"
      <<std::endl;
    const int c_ival = 1024;
    const int &c_refVal = c_ival;
    //int &ref2 = c_ival; //error: nonconst reference to a const object

    int i =42;
    const int &r3 = 42;
    const int &r4 = r3 + i;
    // int &r5 = 42;//error:initializer must be an object
    // int &r6;//error: a reference must be initialized
    return 0;
}
