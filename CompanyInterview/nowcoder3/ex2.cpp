#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main(){
    string cin_str;
    cin >> cin_str;
    int result=0;
    map<char,int> hash_ch;
    for(string::size_type ix=0; ix < cin_str.size(); ix++){
        if(hash_ch.count(cin_str[ix]))
            hash_ch[cin_str[ix]]++;
        else
            hash_ch[cin_str[ix]] = 1;
    }

    map<char,int>::const_iterator map_it = hash_ch.begin();
    while(map_it!=hash_ch.end()){
        //cout << map_it->first << " , " << map_it->second <<endl;
        if(map_it->second%2 != 0) result++;
        ++map_it;
    }

    cout << result <<endl;
    return 0;
}
