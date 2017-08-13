#include <iostream>
#include <vector>

using namespace std;

const int max_mine = 100;//最多金矿数
const int max_people = 10000;//最大人数
vector<vector<int> > record(max_people, vector<int>(max_mine,-1));//初始化备忘录，值为-1
vector<vector<int> > info_vec;//里层vector存的是每座金矿需要的人数，每座金矿能挖出的金子数
//获取有people个人和前mine个金矿时，能得到的最大的金子数，编号从０开始
int GetMaxGold(int people, int mine){
    int return_max;//返回的最大金子数
    if(record[people][mine] != -1){
        return_max = record[people][mine];//直接从备忘录中获取值
    }
    else if(mine == 0){//如果仅剩下一座金矿
        if(people >= info_vec[mine][0]){
            return_max = info_vec[mine][1];
        }
        else{
            return_max = 0;
        }
    }

    else if(people >= info_vec[mine][0]){
        //考虑挖与不挖两种情况
        return_max = max(GetMaxGold(people - info_vec[mine][0],mine-1)+info_vec[mine][1], GetMaxGold(people, mine-1));

    }
    else{
        return_max = GetMaxGold(people, mine-1);
    }

    //做备忘录
    record[people][mine] = return_max;
    return return_max;
}

int main(){
    int people_total;//可以用来挖金子的人数
    int mine_nums;//金矿数
    int a,b;
    cin >> people_total >> mine_nums;
    for(int i=0; i<mine_nums;++i){
        cin >> a >> b;
        vector<int> tmp_vec;
        tmp_vec.push_back(a);
        tmp_vec.push_back(b);
        info_vec.push_back(tmp_vec);

    }

    for(size_t si = 0; si < info_vec.size(); ++si){
        for(size_t sj = 0; sj < info_vec[si].size(); ++sj){
            cout << info_vec[si][sj] << " ";
        }
        cout << endl;
    }
    cout << GetMaxGold(people_total, mine_nums-1)<<endl;


    return 0;

}
