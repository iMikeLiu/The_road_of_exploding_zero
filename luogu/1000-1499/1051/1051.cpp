#include<cstdio>
#include<iostream>
using namespace std;
struct people//建立一个结构体，用来存储每一个人的各项姓名、编号、各项奖金 
{
    char name[21];//name:姓名 
    int  qimo,pingyi,ganbu,xibu,lunwen,zongfen;
};
struct maxn
{
	int maxfen,num;
};
people p[100];
int n;
char ganbu,xibu;//临时的 
maxn maxp;
long long int zongfen;
int main()
{
	//freopen("1051.in","r",stdin);
	scanf("%d",&n);
	for(int a=1;a<=n;a++)
	{
		scanf("%s%d%d",&p[a].name,&p[a].qimo,&p[a].pingyi);
		cin>>ganbu>>xibu;
		//cout<<ganbu<<xibu<<endl; 
		scanf("%d",&p[a].lunwen);
		if(ganbu=='Y')
		{
			p[a].ganbu=1;	
		}
		else
		{
			p[a].ganbu=0;
		}
		if(xibu=='Y')
		{
			p[a].xibu=1;	
		}
		else
		{
			p[a].xibu=0;
		}
		//printf("%s",&p[a].name);
		//cout<<" "<<p[a].qimo<<" "<<p[a].pingyi<<" "<<p[a].ganbu<<" "<<p[a].xibu<<" "<<p[a].lunwen<<" "<<endl;
	}
	
	
	
	
	
	for(int a=1;a<=n;a++)
	{
		if(p[a].qimo>80&&p[a].lunwen>=1)
		{
			p[a].zongfen=p[a].zongfen+8000;
		}
		if(p[a].qimo>85&&p[a].pingyi>80)
		{
			p[a].zongfen=p[a].zongfen+4000;
		}
		if(p[a].qimo>90)
		{
			p[a].zongfen=p[a].zongfen+2000;
		}
		if(p[a].qimo>85&&p[a].xibu==1)
		{
			p[a].zongfen=p[a].zongfen+1000;
		}
		if(p[a].pingyi>80&&p[a].ganbu==1)
		{
			p[a].zongfen=p[a].zongfen+850;
		}
		//printf("%s",&p[a].name);
		//cout<<" "<<p[a].zongfen<<endl;
	}
	
	for(int a=1;a<=n;a++)
	{
		if(p[a].zongfen>maxp.maxfen)
		{
			maxp.num=a;
			maxp.maxfen=p[a].zongfen;
		}
		zongfen=zongfen+p[a].zongfen;
	}
	
	printf("%s",&p[maxp.num].name);
	cout<<endl<<p[maxp.num].zongfen<<endl<<zongfen;
	return 0;
}
