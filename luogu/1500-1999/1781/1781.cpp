#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
using namespace std;
int n,Max_=-1;
string a,max_="0";//max_�洢���Ʊ������ʼֵΪ0
int main()
{
 	freopen("1781.in","r",stdin);
 //	freopen("1781.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin>>a;//����Ʊ��
        if(a.length()>max_.length())
		{
			max_=a;
			Max_=i;
		}//�ȱȽ�λ��
        if((a.length()==max_.length())&&(a>max_))
		{
			max_=a;
			Max_=i;
		}//���λ��һ������ֱ�ӱȽϴ�С
    }
    cout<<Max_+1<<endl<<max_;//���...Ҫ����Ŷ^_^



 	return 0;
}

