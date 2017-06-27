#include <iostream>
#include <bitset>

using namespace std;

int main(){
    bitset<32> bitvec(0xffff);
    cout << "bitvec:" << bitvec <<endl;
    bitset<32> bv(1010101);
    cout << "bv:" << bv <<endl;
    string strval = "101010101";
    bitset<32> bv1(strval);
    cout << "bv1:" << bv1 <<endl;
    bitset<32> bv3;
    int x = 0, y=1, z;
    z = x+y;
    while(z <= 21){
        bv3.set(z);
        x = y;
        y = z;
        z = x + y;
    }
    cout << "bv3:" << bv3.to_ulong() <<endl;

    return 0;
}
