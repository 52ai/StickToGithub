#include <iostream>
#include <unistd.h>
using namespace std;

int main(){

    int ival;
    while(cin >> ival, !cin.eof()){
        cout << cin.rdstate() <<endl;

        for(int i; i < 1000 ; i++){
            cout << i << flush;
            sleep(1);
        }

        if(cin.bad())
            throw runtime_error("IO stream corrupted");
        if(cin.fail()){
            cerr << "bad data, try again";
            cin.clear(istream::failbit);
            continue;
        }
        cout << ival << endl;



    }

    return 0;
}
