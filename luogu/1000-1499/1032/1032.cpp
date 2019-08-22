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
string a,b;
string rule[7][2];
struct node
{
	string a;
	int cnt;
};
queue <node> q;
int main()
{
 	freopen("1032.in","r",stdin);
// 	freopen("1032.out","w",stdout);
	int n=0;
	cin>>a>>b;
	while(cin>>rule[n][0]>>rule[n][1])n++;
	q.push((node){a,0});
	while(!q.empty())
	{
		node head=q.front();q.pop();
		for(int i=0,pos=-1;i<n;i++)
			while((pos=head.a.find(rule[i][0],pos+1))!=-1)
			{
				node c=(node){head.a,head.cnt+1};
				c.a.replace(pos,rule[i][0].length(),rule[i][1]);
				if(c.a==b)
				{
					cout<<c.cnt;
					return 0;
				}
				if(c.cnt>10)
				{
					cout<<"NO ANSWER!";
					return 0;
				}
				q.push(c);
			}
	}
	cout<<"NO ANSWER!";

	fclose(stdin);
	fclose(stdout);
 	return 0;
}