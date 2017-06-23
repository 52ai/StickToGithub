#include <iostream>
#include <string>

using namespace std;

int main(){
    string s_in,s_result;
    bool flag = false;
    getline(cin,s_in);
    for(string::size_type ix=0; ix !=s_in.size(); ++ix){
        if(ispunct(s_in[ix])){
            flag = true;
        }
        else{
            s_result += s_in[ix];
        }
    }
    if(flag){
        cout << "Result:" << s_result <<endl;
    }
    else{

        cout << "No Punctuation character in the string?!" <<endl;
    }

    return 0;
}
