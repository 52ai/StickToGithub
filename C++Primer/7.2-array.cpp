#include <iostream>
using namespace std;

void printValues1(int (&arr)[10]);
void printValues2(int *arr);
int main(){
    int i=0, j[2]={0,1};
    int k[10] = {0,1,2,3,4,5,6,7,8,9};
    printValues1(k);
    printValues2(k);
    return 0;
}

void printValues1(int (&arr)[10]){

    for(size_t i = 0; i!=10;++i){

        cout << arr[i] << " ";
    }
    cout << endl;

}

void printValues2(int *arr){

   for(size_t i=0; i!=10;++i){
    //cout << *arr++ << " ";
    cout << arr[i] << " ";
   }

   cout << endl;
}
