#include <iostream>
using namespace std;

int main(){
    int i=0;
    for(int i=0;i<10;++i){
        cout <<"i_in: "<< i << endl;
    }
    cout <<"i_out: "<< i << endl;

    for(int j=0;j<10;++j){
        ++i;
        cout <<"j_in: "<< j << endl;
    }
    cout <<"i_out: "<< i << endl;

char ch;
//initialize counters for each vowel
int aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,otherCnt = 0;
while(cin >> ch){
// if ch is a vowel, increment the approprite counter
    switch(char ch1 = ch){\
        case 'a':
            ++aCnt;

        case 'e':
            cout << "test e!"<<endl;
            ++eCnt;

        case 'i':
            ++iCnt;

        case 'o':
            ++oCnt;

        case 'u':
            ++uCnt;

        default:
            ++otherCnt;


        }

cout << "aCnt:\t"<<aCnt<<'\n';
cout << "eCnt:\t"<<eCnt<<'\n';
cout << "iCnt:\t"<<iCnt<<'\n';
cout << "oCnt:\t"<<oCnt<<'\n';
cout << "uCnt:\t"<<uCnt<<'\n';
cout << "otherCnt:\t"<<otherCnt<<'\n';
}
//print results


    return 0;
}
