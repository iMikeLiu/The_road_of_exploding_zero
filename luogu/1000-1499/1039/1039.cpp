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
int fake[21],err,w[200],nx;
string name[100],say[200];
void set(int who,int yx)
{
	if(fake[who]&&fake[who]!=yx)
		err=1;
	else
		fake[who]=yx;
}
string days[10]=
{
	"",
	"Today is Sunday.",
	"Today is Monday.",
	"Today is Tuesday.",
	"Today is Wednesday.",
	"Today is Thursday.",
	"Today is Friday.",
	"Today is Saturday.",
};
int m,n,p;





int main()
{
 	freopen("1039.in","r",stdin);
// 	freopen("1039.out","w",stdout);	
	int m=read(),n=read(),p=read();
	for(int i=1;i<=m;i++)
		cin>>name[i];
	for(int i=1;i<=p;i++)
	{
		string nm;
		cin>>nm;
		nm.erase(nm.end()-1);
		for(int j=1;j<=m;j++)
			if(name[j]==nm)
				w[i]=j;
		getline(cin,say[i]);
		say[i].erase(say[i].begin());
		say[i].erase(say[i].end()-1);
	}
	for(int td=1;td<=7;td++)
		for(int px=1;px<=m;px++)
		{
			err=0;
			memset(fake,0,sizeof(fake));
			for(int i=1;i<=p;i++)
			{
				int who=w[i];
				if(say[i]=="I am guilty.")
					set(who,px==who?1:-1);
				if(say[i]=="I am not guilty.")
					set(who,px!=who?1:-1);
				for(int j=1;j<=7;j++)
					if(say[i]==days[j])
						set(who,j==td?1:-1);
				for(int j=1;j<=m;j++)
				{
					if(say[i]==name[j]+" is guilty.")
						set(who,j==px?1:-1);
					if(say[i]==name[j]+" is not guilty.")
						set(who,j!=px?1:-1);
				}
			}
			int faker=0,not_ok=0;
			for(int i=1;i<=m;i++)
			{
				if(fake[i]==-1)
					faker++;
				if(fake[i]==0)
					not_ok++;
			}
			if(!err&&faker<=n&&faker+not_ok>=n)
			{
				if(nx&&nx!=px)
					return cout<<"Cannot Determine",0;
				else
					nx=px;
			}
	}
	if(!nx)
		cout<<"Impossible"; 
	else
		cout<<name[nx];

	fclose(stdin);
	fclose(stdout);
 	return 0;
}