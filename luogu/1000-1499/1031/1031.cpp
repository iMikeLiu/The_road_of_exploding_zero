#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
#include<cstdlib>
using namespace std;



int main()
{
 	freopen("1031.in","r",stdin);
// 	freopen("1031.out","w",stdout);
    int n,i,sum=0,ans=0,a[1000];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
	    scanf("%d",&a[i]);
	    sum+=a[i];
    }
    sum/=n;//ƽ��ֵ
    for(i=1;i<=n;i++)
    {
        if(a[i]<sum)//����
        {
            ans++;
            a[i+1]-=(sum-a[i]);
        }
        else
        if(a[i]>sum)//����
        {
            ans++;
            a[i+1]+=(a[i]-sum);
        }
    }
    printf("%d\n",ans);
    return  0;
}
