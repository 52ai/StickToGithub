/****

字符串匹配的KMP算法

问题：字符串S1:BBC ABCDAB ABCDABCDABDE 中是否包含字符串S2：ABCDABD

1.比较S1和S2的第一个字符，如果不匹配搜索词后移
2.匹配则比较第二个字符，一直到搜索词对应的字符不相同为止
3.如果不相同，则搜索词后移。

普通的做法是，搜索词后移1位，重复1,2步骤，知道匹配成功

KMP算法的核心在于，利用已知信息信息搞出了一个部分匹配表(Partial Match Table)
然后根据公式：移动位数=已匹配的字符数 - 最后一个匹配字符对应的部分匹配值
得到移动位数，再将搜索词后移相应的位数。（如此一来便大大提高了匹配的效率）


关于部分匹配表如何产生：

部分匹配值，就是"前缀"和"后缀"最长的公有元素的长度

具体可以参考阮一峰前辈的一篇文章：
http://www.ruanyifeng.com/blog/2013/05/Knuth–Morris–Pratt_algorithm.html

理解了大概，接下来是实现

****/

#include <iostream>
#include <stdio.h>
#include <sstream>
using namespace std;
#define MAX_N  10000

void kmp_search(char[], char[], int []);
void get_next_val(char[], int next[]);

int main(int argc, char const *argv[])
{
	int next[MAX_N];
	char s1[MAX_N],s2[MAX_N];
	cin>>s1;
	cin>>s2;
	get_next_val(s1,next);
	kmp_search(s1,s2,next);
	return 0;
}

void kmp_search(char s[], char p[], int next[]){
	int i=0,j=0;
	int slenth = strlen(s);
	int plenth = strlen(p);

	while(i < slenth && j < plenth){
		if(j == -1 || s[i] == p[j]){
			i++,j++;
		}
		else{
			j=next[j];
		}
	}
	if(j==plenth){
		stringstream ss;
		int temp = i-j+1;
		ss << "第"<<temp<<"个字母到第"<<i<<"个字母为匹配字符";
		cout << ss.str()<<endl;
	}
	else{
		cout << "None" <<endl;
	}
}

void get_next_val(char p[], int next[]){
	int plenth = strlen(p);
	next[0] = -1;
	int k=-1,j=0;

	while(j < plenth -1){
		if(k == -1 || p[j] == p[k]){
			j++,k++;
			if(p[j] != p[k]){
				next[j] = k;
			}
			else {
				next[j]=next[k];
			}
		}
		else{
			k = next[k];
		}
	}
}

