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
#include <queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;  //����һ����Ϊq�����ȶ���
int n,ans;
int main()
{
 	freopen("1090.in","r",stdin);
// 	freopen("1090.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		q.push(a);
	}
    for (int i=1;i<=n-1;i++)
    {
        int a=q.top();//̰�ģ�ȡ������С��Ԫ�أ�������������ȥ��ֱ��ֻʣ��һ��Ԫ��Ϊֹ
        q.pop();
        int b=q.top();
        q.pop();
        q.push(a+b);
        ans+=a+b;
    }
    printf ("%d",ans);
    return 0;
}

