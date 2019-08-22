#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
#include<cstdlib>
#include<map>
using namespace std;

map <string, int> k; 

bool cmp(int a, int b)
{
    return a * 100 + b > b * 100 + a;
}




int main()
{
 	freopen("1603.in","r",stdin);
// 	freopen("1603.out","w",stdout);
    k["one"] = 1;
    k["two"] = 2;
    k["three"] = 3;
    k["four"] = 4;
    k["five"] = 5;
    k["six"] = 6;
    k["seven"] = 7;
    k["eight"] = 8;
    k["nine"] = 9;
    k["ten"] = 10;
    k["eleven"] = 11;
    k["twelve"] = 12;
    k["thirteen"] = 13;
    k["fourteen"] = 14;
    k["fifteen"] = 15;
    k["sixteen"] = 16;
    k["seventeen"] = 17;
    k["eighteen"] = 18;
    k["nineteen"] = 19;
    k["twenty"] = 20;
    k["a"] = 1;
    k["both"] = 2;
    k["another"] = 1;
    k["first"] = 1;
    k["second"] = 2; // 将map初始化一下，方便后面的取用
    k["third"] = 3; // 这段其实是复制了楼下（捂嘴）
    string s[10]; // 存储六个单词 为了方便直接搞成了
    int num[10];
    int cou = 0;
    memset(num, -1, sizeof(num));
    for(int i = 1; i <= 6; i++){ // 读入6次
        cin >> s[i];
        int len = s[i].size();
        for(int j = 0; j < len; j++){
            if(s[i][j] >= 'A' && s[i][j] <= 'Z') s[i][j] -= 'A' - 'a'; // 统一转换成小写
            if(s[i][j] == '.') s[i].erase(j); // 如果是‘.’那么直接把它删除，不影响判断
        }
        if(k[s[i]]){
            num[i] = k[s[i]]; // 生成对应的数字
            num[i] = num[i] * num[i] % 100;
            cou++; // 把生成数字的数量加1
        }
    }
    if(cou == 0){ // 特判0
        printf("0");
        return 0;
    }
    sort(num+1, num+7, cmp); // 进行玄学排序（具体看cmp）
    printf("%d", num[cou]); // 避免前导0
    for(int i = cou - 1; i > 0; i--){ // 由于会把-1排到后面，所以应该这么输出
        if(num[i] / 10 == 0) printf("0");
        printf("%d", num[i]);
    }
 	return 0;
}

