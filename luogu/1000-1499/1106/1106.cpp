#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<ctime>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<(x)<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<(x)<<":"<<#y<<"="<<(y)<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define L long
#define LL long long
#define I inline
#define U unsigned
#define START clock_t __start=clock();
#define STOP fprintf(stderr,"\n\nUse Time:%fs\n",((double)(clock()-__start)/CLOCKS_PER_SEC));
using namespace std;
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
int n,k,a[257],rest,t=1,minp,cnt=0;
bool flag=0;
string num;



int main()
{
 	freopen("1106.in","r",stdin);
// 	freopen("1106.out","w",stdout);
	cin>>num>>k;
	n=num.length();
	for(int i=1;i<=n;++i)
		a[i]=num[i-1]-'0';
	rest=n-k;
	while(cnt<rest)
	{
		minp=t;
		for(int i=t;i<=k+t;++i)
			if(a[minp]>a[i])
				minp=i;
		if(a[minp])
			flag=1;
		if(flag)
			cout<<a[minp];
		k-=minp-t;
		t=minp+1;
		cnt++;
	}
	if(!flag)
	cout<<0;
	return 0;
	

	fclose(stdin);
	fclose(stdout);
 	return 0;
}