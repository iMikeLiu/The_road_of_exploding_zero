#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,num=0,project[10];
int big[9000][10];//存结果用的大数组（最多一组解决方案没过9k） 
int i,a; 
void dfs(int remain_n,int deep,int* now_project_p)
{//递归函数 ，其实可以用void 
    if(remain_n<(10-deep)||remain_n>(3*(10-deep)))
		return ;//剪枝 
    if(remain_n==0)
	{//如果到末端 
        num++;//累加方案数
        for(int o=0;o<10;o++)
		{//存结果
            big[num-1][o+1]=*(now_project_p+o);
        }
        return ;
    }
    for(int z=1;z<=3;z++)
	{//遍历递归 
        *(now_project_p+deep)=z;
        dfs(remain_n-z,deep+1,now_project_p);
    }
    return ;
}

int main()
{
 	freopen("2089.IN","r",stdin);
// 	freopen("2089.OUT","w",stdout);
	cin>>n;
    dfs(n,0,&project[0]);//计算 
    cout<<num<<endl;
    for(i=0;i<num;i++)
	{//输出 
        for(a=0;a<10;a++){
            cout<<big[i][a+1]<<" ";
        }
        cout<<endl;
    }


 	return 0;
}

