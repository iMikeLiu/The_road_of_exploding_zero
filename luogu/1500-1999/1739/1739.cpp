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


int main()
{
 	freopen("1739.in","r",stdin);
// 	freopen("1739.out","w",stdout);
	char c;
	int zuo=0,you=0;
	do
	{
		cin>>c;
		if (c=='(')
			zuo++;
		if (c==')')
			you++;
		if (you>zuo)
		{
			cout<<"NO";
			return 0;
		}
	}while (c!='@');
	if (zuo==you)
		cout<<"YES";
	else
		cout<<"NO";
	fclose(stdin);
	fclose(stdout);
 	return 0;
}