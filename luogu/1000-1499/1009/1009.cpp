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
class bignumber
{
	private:
		int s[10000],len;
	public:
		bignumber()
		{
			memset(this->s,0,sizeof(this->s));
			this->len=1;
		}	
		bignumber operator=(const char*num)
		{
			this->len=strlen(num);
			for(int i=0;i<this->len;++i)
				this->s[i]=num[len-i-1]-'0';
			return *this;
		}
		bignumber operator=(int num)
		{
			char a[9999];
			sprintf(a,"%d",num);
			*this=a;
			return *this;
		}
		bignumber operator=(bignumber num)
		{
			this->len=num.len;
			for(int i=0;i<num.len;i++)
				this->s[i]=num.s[i];
			return *this;
		}		
		bignumber operator+(const bignumber &a)
		{
			bignumber c;
			c.len=max(this->len,a.len)+1;
			for(int i=0,x=0;i<c.len;i++)
			{
				c.s[i]=this->s[i]+a.s[i]+x;
				x=c.s[i]/10;
				c.s[i]%=10;
			}
			if(c.s[c.len-1]==0)
				c.len--;
			return c;
		}
		bignumber operator+=(const bignumber &a)
		{
			*this=*this+a;
			return *this;
		}		
		bignumber operator *(const bignumber &x)
		{
			bignumber c;
			c.len=this->len+x.len;
			for(int i=0;i<this->len;++i)
				for(int j=0;j<x.len;++j)
				{
					c.s[i+j]+=this->s[i]*x.s[j];
					c.s[i+j+1]+=c.s[i+j]/10;
					c.s[i+j]%=10;
				}
			if(c.s[c.len-1]==0)
				--c.len;
			return c;
		}
		bignumber operator *(int a)
		{
			bignumber b,c;
			b=a;
			c=(*this)*b;
			return c;
		}
		bignumber operator*=(const bignumber &a)
		{
			*this=*this*a;
			return *this;
		}
		bignumber operator*=(int a)
		{
			*this=*this*a;
			return *this;
		}		
		void print(FILE* std)
		{
			for(int i=this->len-1;i>=0;i--)
				fprintf(std,"%d",this->s[i]);
		}
};
bignumber ans,jie;
int main()
{
 	freopen("1009.in","r",stdin);
// 	freopen("1009.out","w",stdout);
	int n;
	cin>>n;
	ans=0;
	jie=1;
	for(int i=1;i<=n;i++)
	{
		jie*=i;
		ans+=jie;
	}
	ans.print(stdout);
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
