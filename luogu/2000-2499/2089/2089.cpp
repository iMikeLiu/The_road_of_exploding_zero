#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,num=0,project[10];
int big[9000][10];//�����õĴ����飨���һ��������û��9k�� 
int i,a; 
void dfs(int remain_n,int deep,int* now_project_p)
{//�ݹ麯�� ����ʵ������void 
    if(remain_n<(10-deep)||remain_n>(3*(10-deep)))
		return ;//��֦ 
    if(remain_n==0)
	{//�����ĩ�� 
        num++;//�ۼӷ�����
        for(int o=0;o<10;o++)
		{//����
            big[num-1][o+1]=*(now_project_p+o);
        }
        return ;
    }
    for(int z=1;z<=3;z++)
	{//�����ݹ� 
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
    dfs(n,0,&project[0]);//���� 
    cout<<num<<endl;
    for(i=0;i<num;i++)
	{//��� 
        for(a=0;a<10;a++){
            cout<<big[i][a+1]<<" ";
        }
        cout<<endl;
    }


 	return 0;
}

