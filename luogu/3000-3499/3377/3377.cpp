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
#define R register
#define LL long long
#define I inline
using namespace std;

#define MAXN 100005
#define LEFT_SON 0
#define RIGHT_SON 1
struct node
{
  node* son[2];
  node* fa;
  int val,dist,pos;
};

I LL read()
{
	R LL x;R bool f;R char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
inline int update_dist(node *now)
{
	if(now->son[RIGHT_SON]!=NULL)
		now->dist=now->son[RIGHT_SON]->dist+1;
	else
		now->dist=0;
	return now->dist;
}
node *margin(node*a,node*b)
{
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	if((a->val>b->val)||((a->val==b->val)&&(a->pos>b->pos)))
		swap(a,b);
	a->son[RIGHT_SON]=margin(a->son[RIGHT_SON],b);
	a->son[RIGHT_SON]->fa=a;
	if((a->son[LEFT_SON]!=NULL)&&(a->son[RIGHT_SON]!=NULL)&&(a->son[LEFT_SON]->dist<a->son[RIGHT_SON]->dist))
		swap(a->son[LEFT_SON],a->son[RIGHT_SON]);
	else if((a->son[LEFT_SON]==NULL)&&(a->son[LEFT_SON]!=NULL))
	{
      a->son[0]=a->son[1];
      a->son[1]=NULL;
    }
	update_dist(a);
	return a;
}
node*getf(node *a)
{
	if(a->fa==NULL)
		return a;
	return getf(a->fa);
}
int getmin_pop(node *x)
{
	node *f=getf(x);
	int val=f->val;
	node* s=margin(f->son[LEFT_SON],f->son[RIGHT_SON]);
	if(s!=NULL)
		s->fa=NULL;
	f->pos=-1;
	return val;
}
node tnode[MAXN+10];
node* p[MAXN+10];
inline void add(node *now,int val,int i)
{
	now->son[LEFT_SON]=now->son[RIGHT_SON]=now->fa=NULL;
	now->dist=0;
	now->pos=i;
	now->val=val;
}
int main()
{
 	freopen("3377.in","r",stdin);
// 	freopen("3377.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
		add(p[i]=&tnode[i],read(),i);
	while(m--)
	{
		if(read()==1)
		{
			int a=read(), b=read();
			if((p[a]->pos==-1)||(p[b]->pos==-1))
				continue;
			node* fa=getf(p[a]);
			node* fb=getf(p[b]);
			if(fa==fb)
				continue;
			margin(fa,fb);
		}
		else
		{
			int a=read();
			if(p[a]->pos==-1)
				puts("-1");
			else
				printf("%d\n",getmin_pop(p[a]));
		}
	}
	fclose(stdin);
	fclose(stdout);	
 	return 0;
}