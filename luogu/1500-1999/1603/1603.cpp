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
    k["second"] = 2; // ��map��ʼ��һ�£���������ȡ��
    k["third"] = 3; // �����ʵ�Ǹ�����¥�£����죩
    string s[10]; // �洢�������� Ϊ�˷���ֱ�Ӹ����
    int num[10];
    int cou = 0;
    memset(num, -1, sizeof(num));
    for(int i = 1; i <= 6; i++){ // ����6��
        cin >> s[i];
        int len = s[i].size();
        for(int j = 0; j < len; j++){
            if(s[i][j] >= 'A' && s[i][j] <= 'Z') s[i][j] -= 'A' - 'a'; // ͳһת����Сд
            if(s[i][j] == '.') s[i].erase(j); // ����ǡ�.����ôֱ�Ӱ���ɾ������Ӱ���ж�
        }
        if(k[s[i]]){
            num[i] = k[s[i]]; // ���ɶ�Ӧ������
            num[i] = num[i] * num[i] % 100;
            cou++; // ���������ֵ�������1
        }
    }
    if(cou == 0){ // ����0
        printf("0");
        return 0;
    }
    sort(num+1, num+7, cmp); // ������ѧ���򣨾��忴cmp��
    printf("%d", num[cou]); // ����ǰ��0
    for(int i = cou - 1; i > 0; i--){ // ���ڻ��-1�ŵ����棬����Ӧ����ô���
        if(num[i] / 10 == 0) printf("0");
        printf("%d", num[i]);
    }
 	return 0;
}

