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
const int maxn=10010;
using namespace std;

int n;
bool is_prime[maxn];
int pri[2*maxn],priN;
inline int find(int n);

int main()
{
    freopen("1304.in","r",stdin);
//    freopen("1304.out","w",stdout);
    memset(is_prime,1,sizeof(is_prime));
    is_prime[1]=0;
    scanf("%d",&n);
    find(n);
    for(int i=4;i<=n;i+=2)
    {
        for(int j=1;j<=priN;j++)
        {
            if(is_prime[i-pri[j]])
            {
            	printf("%d=%d+%d\n",i,pri[j],i-pri[j]);
                break;
            }
        }
    }
    return 0;
}
inline int find(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]==true)
        {
            pri[++priN]=i;
        }
        for(int j=1;j<=priN;j++)
        {
            if(i*pri[j]>n)break;
            is_prime[i*pri[j]]=0;
            if(i%pri[j]==0)break;
        }
    }
}

