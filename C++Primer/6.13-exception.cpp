#include <iostream>
using namespace std;

int main(){

    int cin1,cin2,sum;
    while(cin >> cin1 >> cin2){
        try{
            sum = cin1 + cin2;
            if(sum < 10){
                cout << "sum: " << sum << endl;
            }else{
                throw runtime_error("sum of cin1 and cin2 is greater than 10!");

            }
        }
        catch(runtime_error err){
            cout << err.what() << "\n Try Again?Entry y or n"<<endl;
            char c;
            cin >> c;
            if(cin && c=='n')
                break; //break out of while loop
        }

    }
    return 0;
}
