#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
using namespace std;


//KMP 匹配优于朴素匹配的原因在于，根据模式串建立一个部分匹配表，使得模式串在右移的过程中跳跃式的前进

void BuildPatchMatchTable(int *partMatchTable, char *findstr){//获取部分匹配表

    if(findstr == NULL) return;//老样子只要传的是指针就要判断，该指针是否为空

    partMatchTable[0] = 0;//初始化0号位为0，因为单个字符的前缀和后缀都为空，没有所谓的公有元素长度，故为0

    int sizefind = strlen(findstr);//求得模式串的长度

    for(int i = 1; i < sizefind; ++i){//取模式串以首元素开头的所有子串


        set<string> preset;//set集合容器，里面装的是string类型

        string tmppre = "";
        tmppre = findstr[0];
        preset.insert(tmppre);

        for(int j = 1; j < i; ++j){//求当前子串的前缀
            tmppre = tmppre + findstr[j];
            preset.insert(tmppre);
        }

        set<string> postset;
        string tmppost = "";
        tmppost = findstr[i];
        postset.insert(tmppost);
        for(int j = i - 1; j > 0; --j){//求当前字符串的后缀
            tmppost =  findstr[j] + tmppost;
            postset.insert(tmppost);
        }


        set<string> comset;
        for(set<string>::iterator beg = preset.begin(); beg != preset.end(); ++beg){
            if(postset.count(*beg) > 0)
                comset.insert(*beg);
        }


        int maxlen = 0;
        for(set<string>::iterator beg = comset.begin(); beg != comset.end(); ++beg)
        {
            if((*beg).size() > maxlen)
                maxlen = (*beg).size();
        }
        
        partMatchTable[i] = maxlen;
    }
}    


int  kmp(char *srcstr, char *findstr){//进行KMP匹配

    if(srcstr == NULL || findstr == NULL) throw "invalid arguments(s)";//如果两个串有一个为空，则抛出异常

    int lensrc = strlen(srcstr);//计算母串的长度
    int lenfind = strlen(findstr);//计算模式串的长度

    //int *partMatchTable[lenfind] 数组不能这么建，应该如下

    int *partMatchTable = new int[lenfind];//动态的创建一个长度为lenfind的整型数组，并使partMatchTable指向它

    /*C 下可以如下实现
    int *partMatchTable;
    if((partMatchTable=(int *)malloc(lenfind*sizeof(int))) == NULL){
        printf("不能成功分配存储空间\n");
        exit(1);
    }*/
    BuildPatchMatchTable(partMatchTable, findstr);//求部分匹配表

    /*输出部分匹配表
    for(int i = 0; i < lenfind; ++i)
        cout << findstr[i] << "\t" << partMatchTable[i] << endl;
    */

    int curFind = 0;//搜索词中的字符位置，起始位0
    for(int i = 0; i < lensrc; ){//遍历搜索母串

        if(findstr[curFind] == srcstr[i]){//如果母串当前字符与搜索词当前字符相同，则搜索词后移一位，搜索词中的字符后移一位
            ++i;
            ++curFind;
        }

        else{//如果不匹配

            if(curFind == 0) ++i;//如果已匹配字符为0，则搜索词后移一位。
            else{//若curfind 不为0，则表示已匹配了部分，根据部分匹配表，更新移动的步长
                int movestep = curFind - partMatchTable[curFind-1];//后移步长=已匹配的长度-最后一个匹配字符的部分匹配匹配值
                i += movestep;//搜索词后移movestep步长
                curFind = 0;//搜索词中的当前匹配字符位置重置为0号位
            }
        }

        if(curFind == lenfind){//当搜索词所有字符已全部匹配，则删除部分匹配表，返回位置
            delete []partMatchTable;
            return i - lenfind;
        }
    }
    delete []partMatchTable;
    return -1;
}


int main(int argc, char const *argv[])
{
    char srcStr[] = "bbc abcdab abcdabcdabde";//母串
    char findStr[] = "abcdabd";//模式串，亦即搜索词

    cout << "pos:" << kmp(srcStr, findStr) << endl;

    /*
    char srcStr2[] = "bbc abcdab abcdabcdabdezzz";
    char findStr2[] = "zzz";
    cout << "pos:" << kmp(srcStr2, findStr2) << endl;

    char srcStr3[] = "bbc abcdab abcdabcdabde";
    char findStr3[] = "zzz";
    cout << "pos:" << kmp(srcStr3, findStr3) << endl;*/

    return 1;
}