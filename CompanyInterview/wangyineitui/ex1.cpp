#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int theLargest(int num1, int num2){
    return num1 > num2 ? num1 : num2;
}

int main(){
    vector<int> task_vec;
    int task_list1_time_sum=0, task_list2_time_sum=0;
    int num;
    cin >> num;
    while(num--){
        int tmp;
        cin >> tmp;
        task_vec.push_back(tmp);
    }
	//cin >> task_vec[0] >>task_vec[1] >>task_vec[2] >> task_vec[3] >> task_vec[4];
    sort(task_vec.begin(),task_vec.end());//将得到的任务按时间长度升序排列
    //每次取当前vector中末尾的任务，添加到任务队列中，只需要记录每个每个任务队列总的时间消耗
    //按照一定的策略添加
    //当任务队列为空时，直接输出０
    /*
    for(size_t sz =0; sz < task_vec.size(); ++sz){
        cout << task_vec[sz]<<endl;
    }*/

    if(task_vec.size() == 0){
        cout << task_list1_time_sum;
    }
    //当任务队列为１时，直接输出该任务的时间
    else if(task_vec.size() == 1){
        cout << task_vec[0];
    }
    else if(task_vec.size() >= 2){
        vector<int>::reverse_iterator itv = task_vec.rbegin();
        task_list1_time_sum += *itv;
        ++itv;
        task_list2_time_sum += *itv;
        ++itv;
        //cout << task_list1_time_sum <<endl;
        //cout << task_list2_time_sum <<endl;
        while(itv != task_vec.rend()){
            if(task_list1_time_sum < task_list2_time_sum){
                task_list1_time_sum += *itv;
            }else{
                task_list2_time_sum += *itv;
            }
            ++itv;
            //cout << "task_list1_time_sum "<<task_list1_time_sum <<endl;
            //cout << "task_list2_time_sum "<<task_list2_time_sum <<endl;

        }
        cout << theLargest(task_list1_time_sum, task_list2_time_sum);
    }

    return 0;
}
