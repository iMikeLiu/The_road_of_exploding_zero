#include <cstdio>
int main()
{
	freopen("3952.in","r",stdin);
// 	freopen("3952.out","w",stdout);
    long long a,m,n; 
    scanf("%lld %lld",&m,&n);
    printf("%lld",m*n-n-m);
    return 0;
}
