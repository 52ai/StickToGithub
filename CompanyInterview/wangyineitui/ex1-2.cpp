
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n,sum_time=0;
    while(cin >> n){
    vector<int> task_vec(n,0);
    for(int i=0;i<n;++i){
        cin >> task_vec[i];
        task_vec[i] /= 1024;
        sum_time += task_vec[i];
    }

//    for(int i=0;i<n;++i){
//        cout << task_vec[i]<< " ";
//    }
    //存放最大价值（每个重量对应最大价值）
    int* dp = new int[sum_time/2 + 1]{0};
    //i代表任务数量（物品数量）
    for(int i=0; i<n ; ++i){
        //j代表任务执行时长的一半（背包承重的最大值）
        for(int j=sum_time/2; j >= task_vec[i]; --j){
            dp[j] = max(dp[j], dp[j-task_vec[i]] + task_vec[i]);
        }
    }
    cout << max(sum_time - dp[sum_time/2], dp[sum_time/2]) * 1024;

    }
    return 0;
}

/**

链接：https://www.nowcoder.com/questionTerminal/9ba85699e2824bc29166c92561da77fa
来源：牛客网

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
int getMinTime(std::vector<int> arr, int n) {
    int rows = arr.size();
    int clos = n + 1;
    std::vector<std::vector<int> > dp(rows, std::vector<int>(clos, 0));
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < clos; j++) {
            if (j >= arr[i]) {
                dp[i][j] = std::max(dp[i - 1][j - arr[i]] + arr[i], dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[rows - 1][n];
}
int main() {
    using namespace std;
    int n;
    while (cin >> n) {
        vector<int> arr(n + 1);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int temp;
            cin >> temp;
            arr[i] = temp / 1024;
            sum += arr[i];
        }
        int v = (ceil)(sum / 2.0);
        int ans = getMinTime(arr, v);
        int result = ans > sum - ans ? ans : sum - ans;
        cout << result * 1024 << endl;
    }
    return 0;
}

**/
