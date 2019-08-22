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
#include<queue>
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
#define MAXN 30011
LL a[MAXN],b[MAXN];
priority_queue<long long,vector<long long>,greater<int> >q1;
priority_queue<long long>q2;


int main()
{
 	freopen("311.in","r",stdin);
// 	freopen("311.out","w",stdout);
	int n=read(),m=read(); 
	for(int i=0;i<n;a[i]=read(),i++);
	for(int i=0;i<m;b[i]=read(),i++);
    for(int i=0;i<m;i++)
    {
        for(int j=b[i-1];j<b[i];j++)
        {
            q2.push(a[j]);
            q1.push(q2.top());
			q2.pop();
        }
        q2.push(q1.top());
		q1.pop();
       	cout<<q2.top()<<endl;
    }

	fclose(stdin);
	fclose(stdout);
 	return 0;
}

