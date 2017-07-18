#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){

    int val1=512, val2=1024,val3,val4;
    ostringstream format_message;
    format_message << "val1:" << val1 << "val2:" << val2 << "\n";
    cout << format_message.str() <<endl;
    istringstream input_istring(format_message.str());
    cout << input_istring.str() <<endl;
    //val1=0,val2=0;
    string dump;
    input_istring >> dump >> val1 >> dump >> val2;

    cout  << val1 << " " << val2 << endl;

    string line, word;
    while(getline(cin,line)){

        istringstream stream(line);
        while(stream >> word){

            cout << word <<endl;
        }
    }


    return 0;
}
