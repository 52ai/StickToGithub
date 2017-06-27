#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string st2("Hello, world!");
    //char *str = st2;
    //char *str = st2.c_str();
    const char *str = st2.c_str();
    cout << str <<endl;
    //st2 = st2 + "--By Wayne";
    cout << str <<endl;
    const size_t arr_size = 6;
    int int_arr[arr_size] = {0, 1, 2, 3, 4, 5};
    vector<int> ivec(int_arr, int_arr+arr_size);
    for(vector<int>::iterator iter = ivec.begin();iter != ivec.end();++iter)
        cout << *iter << " ";
    cout << endl;

    int ia[3][4] = {{1},{2},{3}};
    for(int i=0;i < 3;++i){
        /*
        for(int j = 0; j < 4; ++j){
            cout << ia[i][j] << " ";
        }*/
        cout << ia[i];
        cout << endl;
    }
    int i=0,j=0;
    ++i = j++;
    cout << "i: " << i <<endl;
    cout << "j: " << j <<endl;
    return 0;
}
