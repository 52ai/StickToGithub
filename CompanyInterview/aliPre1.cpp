#include <iostream>
#include <vector>
#include <string>
using namespace std;


/****

1.小明是一所小学的四年级老师，他手中有一份这次期末考试的成绩单，里面有N个学生的学号，K个考试科目，上次考试成绩，以及本次考试成绩。以前几次都是按照总分进行排序，但是这次小明打算根据考生的进步情况来排序，然后制定相应的奖励。其中进步的同学为：本次考试排名比上次考试排名有上升或者持平的同学。

注意：

1.如果其中有一门课低于平均值，那么就不算进步同学；
2.如果考试分数出现重复，那么按照学号进行递增排名；
3.如果最终不足M个，也不用凑足。

输入格式：

先输入三行数据为：N，K，M。

再输入N个学生K门科目的考试成绩：学号     科目     上次考试成绩     本次考试成绩。

输入:
输入数据如下格式： 第一行，整数N（参加考试的学生,1<=N<=50） 第二行，整数K（考试科目,1<=K<=5） 第三行，整数M（进步学生的个数,0<=M<=5） 第四~行，学号，科目，上次考试成绩，本次考试成绩
输出:
按照进步顺序，输出对应的学生学号,用逗号分开
输入范例:
4
3
2
1,1,80,90
1,2,70,60
1,3,70,75
2,1,50,90
2,2,30,40
2,3,70,55
3,1,90,90
3,2,80,70
3,3,50,55
4,1,80,80
4,2,70,70
4,3,70,65
输出范例:
1

***/
class Student{

    public:

    int s_id;//学号
    vector<int> subject;//科目代号
    vector<int> last_scores;//上一次考试分数，和subject中的科目顺序一一对应
    vector<int> curr_scores;//本次开始分数，和subject中的科目顺序一一对应
    int last_sum_scores;//上一次总分
    int curr_sum_scores;//这一次总分
    int last_ranking;//上一次总分排名
    int curr_ranking;//这一次总分排名

    Student():s_id(0){}

};

int main(){
    int n,k,m,cnt;
    vector<Student> scores(50);//存储学生的分数信息
    vector<int> last_sum_subject(5,0);//存储每门课的平均分，最多为５门课
    vector<int> curr_sum_subject(5,0);//存储每门课的平均分，最多为５门课
    int arg1,arg2,arg3,arg4;//将string类型处理成四个参数分别表示学号，课程号，上次分数，和本次分数
    cin >> n;
    cin >> k;
    cin >> m;
    //cout << n << "," << k << "," << m <<endl;
    cnt = n*k;
    while(cnt--){
        cin >> arg1>>arg2>>arg3>>arg4;//读入行参数
        //cout <<arg1<<arg2<<arg3<<arg4;
        //构建学生结构体
        scores[arg1].s_id = arg1;
        scores[arg1].subject.push_back(arg2);
        scores[arg1].last_scores.push_back(arg3);
        scores[arg1].curr_scores.push_back(arg4);
        //统计这两次每门课的总分
        last_sum_subject[arg2] += arg3;//求上次每门课的总分
        curr_sum_subject[arg2] += arg4;//求本次每门课的总分

    }

    for(vector<Student>::size_type ix=0; ix < scores.size();ix++){
        cout << scores[ix].s_id <<scores[ix].last_scores[0]<<endl;
    }
    return 0;


}
