#include <iostream>
#include <string>
using namespace std;

char &get_val(string &str, string::size_type ix){
    int arr1[10];
    for(size_t loop=0;loop!=10;++loop){
        cout << arr1[loop] << " ";
    }
    cout << endl;
    return str[ix];
}
int main(){
    string s("a value");
    int arr2[10];
    for(size_t loop=0;loop!=10;++loop){
        cout << arr2[loop] << " ";
    }
    cout << endl;
    cout << s << endl;
    get_val(s, 0) = 'A';

    cout << get_val(s,0) <<endl;

    return 0;
}
