#include<cstdio>
#include<iostream>
using namespace std;
#define shouru 300
int yusuan,shengyu,cun;
int main()
{
	//freopen("1089.in","r",stdin);
	for(int a=1;a<=12;a++)
	{
		cin>>yusuan;
		shengyu=shengyu+shouru;
		if(yusuan>shengyu)
		{
			cout<<-a;
			return 0;
		}
		int c;
		c=shengyu-yusuan;
		shengyu=c%100;//´æÍêÁË
		cun=cun+c-shengyu; 
	}
	cout<<cun*1.2+shengyu;
	
}
