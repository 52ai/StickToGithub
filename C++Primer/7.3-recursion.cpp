#include <iostream>
using namespace std;

int factorial(int val);

int main(){

    int num = 3;
    cout << factorial(num)<<endl;
    return 0;
}

int factorial(int val){
    if(val > 1){
        return val*factorial(val -1);
    }

    return 1;

}
