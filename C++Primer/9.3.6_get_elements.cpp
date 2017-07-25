#include <iostream>
#include <list>

using namespace std;

int main(){

    list<int> ilist(10, 42);
    ilist.resize(15,-1);
    if(!ilist.empty()){
        list<int>::reference val1 = *ilist.begin();
        list<int>::reference val2 = ilist.front();
        cout << "val1:" << val1 <<endl;
        cout << "val2:" << val2 <<endl;
        list<int>::reference val3 = *--ilist.end();//end迭代器指向容器的超出末端位置的下一个位置
        list<int>::reference val4 = ilist.back();
        cout << "val3:" << val3 <<endl;
        cout << "val4:" << val4 <<endl;

    }


    return 0;
}
