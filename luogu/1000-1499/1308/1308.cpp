#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
char word[100],ju[10000000];
int i,j,num,num_old,num_now,k;
bool a=0;
int main()
{
	freopen("1308.in", "r", stdin);
	gets(word);
	gets(ju);
	for(i=0;word[i]!=0;i++)
		word[i]=tolower(word[i]);
	for(i=0;ju[i]!=0;i++)
		ju[i]=tolower(ju[i]);
	num=0;
	i=0;
	j=0;
	while(ju[i])
	{
		if(ju[i]==word[j])
		{
			num_old=i;
			while((ju[i])&&(ju[i]==word[j]))
			{
//printf("%c\t%c\n",ju[i],word[j]);	
				i++;
				j++;
				if(((ju[i]==' ')&&((word[j]=='\0')||(word[j]==' ')||(word[j]=='\n'))))
				{
					if(a==0)
					{
						num_now=num_old;
						a=1;
					}
					num++;
					break;
				}
			}
			j=0;
		}
		else
		{
			while(ju[i]!=' ')
				i++	;
		}
		i++;
	}
	//printf("%s\n%s\n",word,ju);
	if(num==0)
		printf("-1");
	else
		printf("%d %d",num,num_now);
	return 0;
}
