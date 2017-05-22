#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string str,tep;
	cout << "请输入字符串"<<endl;
	cin >>str;

	for(int i=str.length()-1;i>1;i--){
		for(int j=0;j<str.length();j++){
			if(j+i <= str.length()){
				size_t t=0; //size_t 是 unsigned integer type 的别名
				size_t num =0;
				tep = str.substr(j,i);//从大到小取子串

				t=str.find(tep);//正序查找
				num = str.rfind(tep);//逆序查找
				if(t != num){//如果两次查找的字符串不一样，说明存在重复子串
					cout<<tep<<" "<< t+1<<endl;
					return 0;
				}

			}
		}
	}

	return 0;



