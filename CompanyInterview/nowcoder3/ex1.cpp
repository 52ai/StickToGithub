#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int isDoubleString(const char* str){
    int flag = 1;
    int str_len = strlen(str);
    //cout << strlen(str)<<endl;
    if(str_len %2 != 0) {flag =0;}
    else{
        for(int i=0;i < str_len/2;i++){
            if(str[i] != str[str_len/2 + i]){
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

int main(){

    string cin_string;
    cin >> cin_string;
    const char* cin_c_str = cin_string.c_str();
    int slen = strlen(cin_c_str)-1;
    //cout << slen<<endl;

    while(slen-- > 0){
        if(isDoubleString(cin_string.substr(0,slen).c_str())) break;
    }
    cout << slen <<endl;
    return 0;
}
