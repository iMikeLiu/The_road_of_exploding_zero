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
priority_queue<int,vector<int>,greater<int> > q;  //定义一个名为q的优先队列
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
        int a=q.top();//贪心，取两次最小的元素，加起来再塞回去，直到只剩下一个元素为止
        q.pop();
        int b=q.top();
        q.pop();
        q.push(a+b);
        ans+=a+b;
    }
    printf ("%d",ans);
    return 0;
}

