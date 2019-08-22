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
#define MAXN 11000011
char s[MAXN];
char ss[MAXN<<1];
int f[MAXN<<1];
void malache(char *s,int *hw)
{
	int l=strlen(s);
	f[0]=1;
	int mid=0,maxright=0;
	for(int i=1;i<l;i++)
	{
		if(i<maxright)
            hw[i]=min(hw[(mid<<1)-i],hw[mid]+mid-i);
        else
            hw[i]=1;
        for(;s[i+hw[i]]==s[i-hw[i]]&&i-hw[i]>=0&&i+hw[i]<l;++hw[i]);
        if(hw[i]+i>maxright)
        {
            maxright=hw[i]+i;
            mid=i;
        }
	}
}



int main()
{
 	freopen("3805.in","r",stdin);
// 	freopen("3805.out","w",stdout);
	scanf("%s",s);
	int l=strlen(s);
	int j=1;
	ss[0]='#';
	for(int i=0;i<l;i++,j++)
		ss[j]=s[i],ss[++j]='#';
	ss[j]=0;
//	cerr<<ss<<endl;
	malache(ss,f);
//	debugzu(f,0,j-1);
	int ans=0;
	for(int i=0;i<j;i++)
		ans=max(ans,f[i]);
	printf("%d",ans-1);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
