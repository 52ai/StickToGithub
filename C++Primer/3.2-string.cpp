#include <iostream>
#include <string>
using namespace std;

int main(){
    string str("I am Wayne, What your name?");
    string::size_type punct_cnt = 0;
    //str[1] = '*';//string的下标操作可以用作左值
    for(string::size_type ix=0; ix != str.size(); ++ix)
        cout << str[ix] <<endl;
    cout << str[0] <<endl;
    for(string::size_type ix=0;ix != str.size(); ++ix){
        if(ispunct(str[ix]))
            ++punct_cnt;
        str[ix] = tolower(str[ix]);
        }

    cout << punct_cnt
         << " punctuation characters in " << str <<endl;

    string s;
    cout << s <<endl;
    //该实现不合法，因为s[0]表示s的第一个字符，而s是一个空字符串，其长度为0.也许不会报错，但是不合法
    cout << s[0] <<endl;

    return 0;
}
