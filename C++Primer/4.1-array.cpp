#include <iostream>
#include <vector>
using namespace std;

int main(){
    const size_t array_size = 7;
    int ia1[] = {0, 1, 2, 3, 4, 5 ,6};
    int ia2[array_size];// local array, elements uninitialized

    //copy elements from ia1 into ia2
    for(size_t ix = 0; ix != array_size; ++ix)
        ia2[ix] = ia1[ix];

    for(size_t ix = 0; ix != array_size; ++ix)
        cout << ia2[ix]<< " ";
    cout << endl;

    const size_t arr_sz = 5;
    int int_arr[arr_sz] = {0, 1, 2, 3, 4};
    // pbegin points to first element, pend points just after the last
    for(int *pbegin = int_arr, *pend = int_arr + arr_sz;pbegin != pend; ++pbegin){
        cout << *pbegin << " "; // print current element
    }
    cout <<endl;
    vector<int> ivec(10,1);
    for(vector<int>::iterator iter=ivec.begin(); iter != ivec.end(); ++iter){

        cout << *iter << " ";
    }

    return 0;
}
