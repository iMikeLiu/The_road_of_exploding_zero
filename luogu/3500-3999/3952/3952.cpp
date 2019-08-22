#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
I char readc()
{
	char c;
	for (;((c=getchar())<'A'||c>'Z')&&(c<'a'||c>'z'););
	return c;
}
I LL readcd()
{
	R LL x;R bool f;R char c;
	for (f=0; ((c=getchar())<'0'||c>'9')&&(c<'A'||c>'Z')&&(c<'a'||c>'z'); f=c=='-');	
	if(c>='0'&&c<='9')
		for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	else
		x=c;
	return f?-x:x;
}
bool used[300];
char cengused[300];
bool cengplas[300];
bool setjump[300];
bool hadsetjump[300];
int main()
{
 	freopen("3952.in","r",stdin);
// 	freopen("3952.out","w",stdout);
	int n=read(); 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<300;j++)
			cengused[j]=0,used[j]=hadsetjump[j]=cengplas[j]=setjump[j]=false;		
		int m=read();
		readc();
		int on=readcd();
		on=on==1?0:read();
				
		int ceng=0,ans=0,ansmax=0;
		bool errflag=false,jump=false;
		for(int j=0;j<m;j++)
		{
			if(readc()=='F')
			{
				char c=readc();
//				debug(c);debug(used[c]);
				if(used[c])
					errflag=true;
				used[c]=true;
				cengused[ceng]=c;
				int from=readcd(),to=readcd();
//				debug(from);debug(to);
				if((!jump)&&(from!='n'&&to=='n'))
					ansmax=max(++ans,ansmax),cengplas[ceng]=true;
				else if((from=='n'&&to!='n')||(from>to))
					setjump[ceng]=true,hadsetjump[ceng]=jump,jump=true;
//				debug(jump);debug(ans);debug(ansmax);
				ceng++;
			}
			else
			{
				ceng--;
				if(!hadsetjump[ceng])
					jump=false;
				setjump[ceng]=false;
				if(cengplas[ceng])
					ans--,cengplas[ceng]=false;
				used[cengused[ceng]]=false;
			}
		}
		errflag=ceng==0?errflag:true;
		if(errflag)
			printf("ERR\n");
		else if(ansmax==on)
			printf("Yes\n");
		else
			printf("No\n");	
	}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}