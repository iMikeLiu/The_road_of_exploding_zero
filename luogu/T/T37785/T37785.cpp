#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<map>
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<x<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<x<<":"<<#y<<"="<<y<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define R register
#define LL long long
#define I inline
using namespace std;
string peo[20];
string data;
string data1;
string data2;
bool stu[20];
bool tea[20];
bool found[20];
string out[20];
int main()
{
 	freopen("T37785.in","r",stdin);
// 	freopen("T37785.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=8;i++)
		cin>>peo[i];
	for(int i=0;i<n;i++)	
	{
		int peo_num=0;
		cin>>data;
		for(int j=1;j<=8;j++)
			if(data==peo[j])
				peo_num=j;
		if(peo_num>=1&&peo_num<=3)
		{
			cin>>data;
			if(data=="came!")
				tea[peo_num]=true;
			else if(data=="left!")
				tea[peo_num]=false;
		}else if(peo_num>=4&&peo_num<=8)
		{
			cin>>data;
			if(data=="started"||data=="stopped")
			{
				cin>>data1;
				if(data1=="playing")
				{
					cin>>data2;
					if(data=="started"&&data1=="playing"&&data2=="games!")
						stu[peo_num]=true;
					else if(data=="stopped"&&data1=="playing"&&data2=="games!")
						stu[peo_num]=false;
				}
			}
		}
		if(tea[1]||tea[2]||tea[3])
			for(int j=4;j<=8;j++)
				found[j]|=stu[j];
		getline(cin,data);
	}
	int cnt=0;
	for(int j=4;j<=8;j++)
		if(found[j])
			out[cnt++]=peo[j];
	sort(out,out+cnt);
	for(int i=0;i<cnt;i++)
		cout<<out[i]<<" ";
	if(cnt==5)
		cout<<endl<<"How Bad Oiers Are!";
	if(cnt==0)
		cout<<"How Good Oiers Are!";


	fclose(stdin);
	fclose(stdout);
 	return 0;
}
