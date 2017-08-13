#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,sum=0;
    cin >> n;
    vector<int> stu_vec(n,0);
    for(int i=0;i<n;++i){
        cin >> stu_vec[i];
    }
    sort(stu_vec.begin(), stu_vec.end());
    //for(int i=0; i< n; ++i){
    //    cout << stu_vec[i] << " ";
    //}

    vector<int> que_vec;
    vector<int>::iterator iter_l = stu_vec.begin();
    vector<int>::iterator iter_r = stu_vec.end()-1;

    //cout << *iter_l << " " << *iter_r;

    while(iter_l <= iter_r){
        que_vec.push_back(*iter_l);
        que_vec.push_back(*iter_r);
        ++iter_l;
        --iter_r;
    }
    que_vec.insert(que_vec.begin(),*(que_vec.end()-1));

    for(int i=0; i< (n-1); ++i){
        //cout << que_vec[i] << " ";
        sum += abs(que_vec[i]-que_vec[i+1]);
    }
    cout << sum;
    return 0;
}
