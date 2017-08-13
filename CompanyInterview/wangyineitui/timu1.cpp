#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n,0);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    vector<int> b;
    for(int i=0;i<n;++i){
        b.push_back(a[i]);
        reverse(b.begin(), b.end());
    }
    for(int i=0;i<n;++i){
        if (i == (n-1)){
            cout << b[i];
        }else{
            cout << b[i] << " ";
        }

    }


    return 0;

}
