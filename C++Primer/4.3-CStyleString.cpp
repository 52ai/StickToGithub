#include <iostream>
#include <cstring>
using namespace std;

int main(){

    char ca[] = "Hello, C++!";
    const char *p = ca;
    while(*p){
        cout << *p;
        ++p;
    }

    const char *noerror = "success";
    // ...
    const char *err189 = "Error: a function declaration must"
                         "specify a function return type!";
    const char *errorTxt;
    int errorFound;
    cout << "errorFound: " <<errorFound << endl;
    cin >> errorFound;
    if(errorFound)
        errorTxt = err189;
    else
        errorTxt = noerror;
    size_t dimension = strlen(errorTxt)+1;
    char *errMsg = new char[dimension];
    cout << "errMsg: " << errMsg <<endl;
    strncpy(errMsg, errorTxt, dimension);
    cout << "errMsg: " << errMsg <<endl;
    delete [] errMsg;
    cout << "errMsg: " << errMsg <<endl;
    return 0;
}
