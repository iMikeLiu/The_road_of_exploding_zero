#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;
char word [111];
int num[27];
bool used[27]={false};
int i,j;
bool cmp(int x,int y)
{
	if(x>y)
		return true;
	return false;
}
bool check(int x)
{
	int j=sqrt(x);
	if(x==0||x==1)
		return false;
	for(int i=2;i<=j;i++)
		if(x%i==0)
			return false;
	return true;
}
int main()
{
	freopen("1125.in","r",stdin);
//	freopen("1125.out","w",stdout);
	scanf("%s",word);
	for(i=0;word[i]!=0;i++)
	{
		if(word[i]>='A'&&word[i]<='Z')
			word[i]=word[i]-'A'+'a';
		if(used[word[i]-'a']==false)
		{
			used[word[i]-'a']=true;
			j++;	
		}
		num[word[i]-'a']++;
	}
	sort(num,num+26,cmp);
	if(check(num[0]-num[j-1]))
		printf("Lucky Word\n%d",num[0]-num[j-1]);
	else
		printf("No Answer\n0");
	
	
    return 0;
}
