#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#include<vector>
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
char buf[2333];
int n;
vector<int> a, b;



int main()
{
 	freopen("1015.in","r",stdin);
// 	freopen("1015.out","w",stdout);
    scanf("%d%s", &n, buf);
    for(int i = 0, len = strlen(buf); i < len; i++) 
	{
        if(buf[i] >= '0' && buf[i] <= '9')
			a.push_back(buf[i] - '0');
        else
			a.push_back(islower(buf[i])?buf[i]-'a'+10:buf[i]-'A'+10);
    }
    b=a;
    reverse(a.begin(), a.end());
    if(a == b)
		return puts("STEP=0"),0;
	for(int ans = 1; ans <= 30; ans++)
	{
        for(int i = 0, siz = a.size(); i < siz; i++)
		{
            a[i]+=b[i];
            if(i!=siz-1)
				a[i+1]+=a[i]/n;
            else 
				if(a[i] >= n) 
				a.push_back(a[i] / n);
            a[i] %= n;
        }
        b = a;
        reverse(b.begin(), b.end());
        if(a == b) 
			return printf("STEP=%d",ans),0; // 判回文
    }
    return puts("Impossible!"),0;	

	fclose(stdin);
	fclose(stdout);
 	return 0;
}