#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include<cstring>
#include<string>
#include<cctype>
#include<string>
#include<cstdlib>
#include<map>
using namespace std;
int n,data[31][31],x,y,bfs[3000][2],head=1,len=2;

int main()
{
 	freopen("1162.in","r",stdin);
// 	freopen("1162.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
        	scanf("%d",&data[i][j]);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
	        if (data[i][j]==1)
	        {
	            bfs[1][0]=i+1;
	            bfs[1][1]=j+1;
	            data[i+1][j+1]=2;
	            break; 
	        }
        if (bfs[1][0]!=0) 
			break;  
    }
    while (head!=len) //ËÄÏòbfs
    {
        if (data[bfs[head][0]+1][bfs[head][1]]==0)
        {
            bfs[len][0]=bfs[head][0]+1;
            bfs[len][1]=bfs[head][1];
            data[bfs[len][0]][bfs[len][1]]=2;
            len++;
        }
        if (data[bfs[head][0]-1][bfs[head][1]]==0)
        {
            bfs[len][0]=bfs[head][0]-1;
            bfs[len][1]=bfs[head][1];
            data[bfs[len][0]][bfs[len][1]]=2;
            len++;
        }
        if (data[bfs[head][0]][bfs[head][1]-1]==0)
        {
            bfs[len][0]=bfs[head][0];
            bfs[len][1]=bfs[head][1]-1;
            data[bfs[len][0]][bfs[len][1]]=2;
            len++;
        }
        if (data[bfs[head][0]][bfs[head][1]+1]==0)
        {
            bfs[len][0]=bfs[head][0];
            bfs[len][1]=bfs[head][1]+1;
            data[bfs[len][0]][bfs[len][1]]=2;
            len++;
        }
        head++;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)    
			printf("%d ",data[i][j]);
        printf("\n");
    }
    return 0;


 	return 0;
}

