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
#define MAXN 200011
I LL read()
{
	R bool fu;R LL x;R char c;
	for(fu=0;(c=getchar())<'0'||(c>'9');fu=c=='-');
	for(x=c-'0';(c=getchar())>='0'&&(c<='9');x=(x<<3)+(x<<1)+c-'0');
	return fu?-x:x;
}
struct value_struct
{
	int x,id;
}value[MAXN];
bool cmp_node(value_struct a,value_struct b){return a.x<b.x;}
int rankto[MAXN];
struct node_struct
{
	int l,r;
	int sum;
	node_struct()
	{
		sum=0;
		l=0;
		r=0;
	}
}tree[MAXN*20];
int root[MAXN];
int cnt=1;
void update(int num,int &rt,int l,int r)
{
	tree[cnt++]=tree[rt];
	rt=cnt-1;
	tree[rt].sum++;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(num<=mid)
		update(num,tree[rt].l,l,mid);
	else
		update(num,tree[rt].r,mid+1,r);
}
int query(int i,int j,int k,int l,int r)
{
	int d=tree[tree[j].l].sum-tree[tree[i].l].sum;
	if(l==r)
		return l;
	int mid=(l+r)>>1;
	if(k<=d)
		return query(tree[i].l,tree[j].l,k,l,mid);
	return query(tree[i].r,tree[j].r,k-d,mid+1,r);
}
int main()
{
 	freopen("3834.in","r",stdin);
// 	freopen("3834.out","w",stdout);
	root[0] = 0;
	int n=read(),m=read();
	for(int i=1;i<=n;i++)
		value[i].x=read(),value[i].id=i;
	sort(value+1,value+1+n,cmp_node);
	for(int i=1;i<=n;i++)
		rankto[value[i].id]=i;
	for(int i=1;i<=n;i++)
	{
		root[i]=root[i-1];
		update(rankto[i],root[i],1,n);
	}
	for(int i=1;i<=m;i++)
	{
		int left=read(),right=read(),k=read();
		printf("%d\n",value[query(root[left-1],root[right],k,1,n)].x);
	}

	fclose(stdin);
	fclose(stdout);
 	return 0;
}
