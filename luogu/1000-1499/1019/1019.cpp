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
using namespace std;
string str[20];
int use[20], length = 0, n;
int canlink(string str1, string str2) 
{
    for(int i = 1; i < min(str1.length(), str2.length()); i++) 
	{
        int flag = 1;
        for(int j = 0; j < i; j++)
            if(str1[str1.length() - i + j] != str2[j]) flag = 0;
        if(flag) return i;
    }
    return 0;
}
void solve(string strnow, int lengthnow) 
{
    length = max(lengthnow, length);
    for(int i = 0; i < n; i++) 
	{
        if(use[i] >= 2) continue;
        int c = canlink(strnow, str[i]);
        if(c > 0)
		{
            use[i]++;
            solve(str[i], lengthnow + str[i].length() - c);
            use[i]--;
        }
    }
}
int main()
{
 	freopen("1019.in","r",stdin);
// 	freopen("1019.out","w",stdout);
    cin >> n;
    for(int i = 0; i <= n; i++) use[i] = 0, cin >> str[i];
    solve(' '+str[n], 1);
    cout << length ;
	fclose(stdin);
	fclose(stdout);
 	return 0;
}


