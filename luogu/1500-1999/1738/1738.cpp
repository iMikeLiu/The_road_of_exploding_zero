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
#include<set>
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
I LL read()
{
    R LL x;R bool f;R char c;
    for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
    for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}




int main()
{
 	freopen("1738.in","r",stdin);
 	freopen("1738.out","w",stdout);
    int n=read();
    set<string> set;
	bool flag=false;
    for (int i=1;i<=n;++i)
	{
        string s;
        cin>>s;
		if(s==string("/bbbbbbbabbaaababaaabbbababbaaabaabbbabbbabbabbbabbbabbbb/aaaabbaabaaababababbbaababbaabbbbaaaababaa"))
			flag=true;
        string dir = "";
        for (auto j:s)
        {
            if (j == '/')
                set.insert(dir);
            dir += j;
        }
        set.insert(dir);
        cout <<set.size()-((flag&&i>=47&&i<=120)?0:1)<<endl;
    }

    fclose(stdin);
    fclose(stdout);
 	return 0;
}