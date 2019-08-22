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
#define START clock_t __start;__start = clock();
#define STOP fprintf(stderr,"\n\nUse Time:%fs\n",((double)(clock()-__start)/CLOCKS_PER_SEC));
using namespace std;
const int size = 1005;
char s[size],name[size],importer[size],t[size];
int c = 1;
int main()
{
	freopen("1580.in","r",stdin);
//	freopen("1580.out","w",stdout);
    gets(s);
    sscanf(strstr(s, "@"), "@yyy loves %s", name);
    while(c++)
	{
        gets(s);
        int len=strlen(s);
        if(len==1)
			break;
        sscanf(s, "yyy loves %s",importer);
        if(!strcmp(importer, name))
		{
            printf("Successful @yyy loves %s attempt\n",name);
            return 0;
        }
        if(count(s,s+len,'@')!= 1||(sscanf(strstr(s, "@"),"@yyy loves %s",t),strcmp(t,name)))
		{
            printf("Unsuccessful @yyy loves %s attempt\n",name);
            printf("%d\n",c);
            printf("yyy loves %s\n",importer);
            return 0;
        }
    }
    printf("Unsuccessful @yyy loves %s attempt\n",name);
    printf("%d\n", c-1);
    printf("Good Queue Shape\n");
	return 0;
}
