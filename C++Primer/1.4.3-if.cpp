#include <iostream>

int main(){
    std::cout << "Enter two numbers:"<<std::endl;
    int v1,v2,sum=0;
    std::cin >> v1 >> v2;//read input
    int lower,upper;
    if(v1 <= v2){
        lower = v1;
        upper = v2;
    }
    else{
        lower = v2;
        upper = v1;
    }

    for(int i = v1;i <= v2;++i){
        sum += i;
    }
    std::cout << "Sum of " <<lower<<"to"<<upper<<"inclusive is " << sum << std::endl;
}
