#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    vector<string> vs(10,"yu");
    for(vector<string>::size_type idx = 0; idx != vs.size(); ++idx){
        cout << vs[idx];
        if(idx + 1 != vs.size()){
            cout << " " ;
        }
    }

    return 0;
}
