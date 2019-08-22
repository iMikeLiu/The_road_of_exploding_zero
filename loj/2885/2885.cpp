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
#define debuglog(x) cerr<<"\tdebug:"<<#x<<endl
#define debug(x) cerr<<"\tdebug:"<<#x<<"="<<(x)<<endl
#define debugg(x,y) cerr<<"\tdebug;"<<(x)<<":"<<#y<<"="<<(y)<<endl
#define debugzu(x,a,b) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++)cerr<<x[i]<<" ";fprintf(stderr,"\n");
#define debugerzu(x,a,b,c,d) 	cerr<<"\tdebug:"<<#x<<"=\n\t";for(int i=a;i<b;i++,fprintf(stderr,"\n\t"))for(int j=c;j<d;j++)cerr<<x[i][j]<<" ";fprintf(stderr,"\n");
#define START clock_t __start=clock();
#define STOP fprintf(stderr,"\n\nUse Time:%fs\n",((double)(clock()-__start)/CLOCKS_PER_SEC));
using namespace std;
#define MAXN 11
#define MAXM 2011
#define PAI_USED 0 //用过了
#define P 1 //桃
#define K 2 //杀
#define D 3 //闪
#define F 4 //决斗
#define N 5 //南猪入侵
#define W 6 //万箭齐发
#define J 7 //无懈可击
#define Z 8 //猪哥连弩
#define TYPE_UNKNOW 0//类型未知
#define	MP	1	//主猪 
#define	ZP	2	//忠猪
#define	FP	3	//反猪
#define	LZP	4	//类忠猪
#define	LFP	5	//类反猪
inline long long read()
{
	register long long x;register bool f;register char c;
	for (f=0; (c=getchar())<'0'||c>'9'; f=c=='-');
	for (x=c-'0'; (c=getchar())>='0'&&c<='9'; x=(x<<3)+(x<<1)+c-'0');
	return f?-x:x;
}
inline char readc()
{
	register char c;
	for (;((c=getchar())<'A'||c>'Z')&&(c<'a'||c>'z'););
	return c;
}
inline int readpai()
{
	switch(readc())
	{
		case 'P':
			return P;
		case 'K' :
			return K;
		case 'D':
			return D;
		case 'F' :
			return F;
		case 'N':
			return N;
		case 'W' :
			return W;
		case 'J' :
			return J;
		case 'Z' :
			return Z;				
	}
}
inline char getpai(int pai)
{
	switch(pai)
	{
		case P:
			return 'P';
		case K :
			return 'K';
		case D:
			return 'D';
		case F :
			return 'F';
		case N:
			return 'N';
		case W :
			return 'W';
		case J :
			return 'J';
		case Z :
			return 'Z';
		case PAI_USED :
			return 'U';
		default :
			return '!';
	}	
}
inline int readtype()
{
	string s;
	cin>>s;
	if(s=="MP")
		return MP;
	else if(s=="ZP")
		return ZP;
	else if(s=="FP")
		return FP;
}
inline string gettype(int x)
{
	if(x==MP)
		return "MP";
	else if(x==ZP)
		return "ZP";
	else if(x==FP)
		return "FP";
}
class pai_class
{
	private:
		int pai[MAXM];
		int head;
		int tail;
	public:
		inline int add		(int type)			{pai[tail++]=type;return tail-1;}
		inline int get		()					{return pai[head];}
		inline int count	()					{return tail-head;}
		inline int del		()					{int tmp=pai[head];if(count()>1){head++;}return tmp;}
};
pai_class all_pai;
class link_list
{
	private:
		int val;
		link_list *pro;
		link_list *nxt;
	public :
		inline	int			get			()				{return val;}
		inline	int			set			(int v)			{return val=v;}
		inline	link_list*	get_nxt		()				{return nxt;}
		inline	link_list*	get_pro		()				{return pro;}
		inline	link_list*	set_nxt		(link_list* p)	{return nxt=p;}
		inline	link_list*	set_pro		(link_list* p)	{return pro=p;}
		inline	void		del			()				{val=0;if(pro!=NULL)pro->nxt=nxt;if(nxt!=NULL)nxt->pro=pro;nxt=NULL;pro=NULL;}
};
class zhu_pai_class
{
	private:
		link_list pai[MAXM];
		int p_count,d_count,j_count;
		bool z_flag;
		link_list *now,*head,*tail;
	public :
		inline void reset_now()
		{
			now=head;
		}
		inline void reset_now_to_tail()
		{
			now=tail;
		}		
		inline void reset_tail()
		{
			tail=head;
		}
		zhu_pai_class()
		{
			p_count=d_count=j_count=0;
			z_flag=false;
			head=pai;
			reset_now();
			reset_tail();
			now->set_nxt(NULL);
			now->set_pro(NULL);
		}
		inline void add(int type)
		{
			if(type==P)					//桃子
				p_count++;
			if(type==J)					//无懈可击
				j_count++;
			if(type==D)					//闪
				d_count++;
			if(now==NULL)
				now=tail;
			now->set(type);
			now->set_nxt(now+1);
			now->get_nxt()->set_pro(now);
			now->get_nxt()->set_nxt(NULL);
			tail=now=now->get_nxt();
		}
		inline bool del(link_list * v)
		{
			if(v==NULL)
				return false;
			if(v->get()==P)
				p_count--;
			if(v->get()==J)
				j_count--;
			if(v->get()==D)
				d_count--;
			if(head==v)
			{
				head=v->get_nxt();
//				cerr<<"\treset head"<<endl;
			}
			if(now==v)
			{
				now=v->get_nxt();
//				cerr<<"\treset now"<<endl;				
			}
//			cerr<<"\t\t lose "<<getpai(v->get())<<endl;
			v->del();
			return true;
		}
		inline link_list *get_now()
		{
			return now;
		}
		inline link_list *get_nxt()
		{
			if(tail==head)
				return NULL;
			return now=now->get_nxt();
		}
		inline link_list * find_d()		//返回第一张闪
		{
			reset_now();
			link_list *tmp=get_now();
			if(tmp==NULL)
				return NULL;
			do
				if(tmp->get()==D)
					break;
			while((tmp=get_nxt())!=NULL);
			return tmp;
		}
		inline link_list * find_p()		//返回第一张桃
		{
			reset_now();
			link_list *tmp=get_now();
			if(tmp==NULL)
				return NULL;
			do
				if(tmp->get()==P)
					break;
			while((tmp=get_nxt())!=NULL);
			return tmp;
		}
		inline link_list * find_j()		//返回第一张无懈可击
		{
			reset_now();
			link_list *tmp=get_now();
			if(tmp==NULL)
				return NULL;
			do
				if(tmp->get()==J)
					break;
			while((tmp=get_nxt())!=NULL);
			return tmp;
		}
		inline bool try_use_k()			//尝试打出一张杀
		{
			reset_now();
			link_list *tmp=get_now();
			if(tmp==NULL)
				return false;			
			do
				if(tmp->get()==K)
				{
					del(tmp);
					return true;
				}
			while((tmp=get_nxt())!=NULL);
			return false;
		}
		inline bool try_use_d()			//尝试打出一张闪
		{
			if(d_count)
				return del(find_d());
			return false;
		}
		inline bool try_use_p()			//尝试打出一张桃
		{
			if(p_count)
			{
//				cerr<<"eat tao"<<endl;
				return del(find_p());
			}
			return false;
		}
		inline bool try_use_j()			//尝试打出一张无懈可击
		{
			if(j_count)
				return del(find_j());
			return false;
		}
		inline void print_all(FILE *f)
		{
			link_list *buf=now,*tmp;
			reset_now();
			tmp=now;
			if(tmp==NULL)
				return ;
			bool flag=false;
			do
			{
				if(tmp->get())
				{
					if(flag)
						fprintf(f," ");
					flag=true;
					fprintf(f,"%c",getpai(tmp->get()));
				}
			}
			while((tmp=get_nxt())!=NULL);
			fprintf(f,"\n");
			now=buf;
		}
		inline bool have_z()
		{
			return z_flag;
		}
		inline void add_z()
		{
			z_flag=true;
		}
		inline void del_all()
		{
			p_count=d_count=j_count=0;
			z_flag=false;
			reset_now();
			for(link_list *tmp=get_now(),*tmp2=tmp;tmp2;tmp2=tmp->get_nxt(),tmp->del(),tmp=tmp2);
			head=pai;
			reset_now();
			reset_tail();
			now->set(0);
			now->set_nxt(NULL);
			now->set_pro(NULL);		
		}
};
int alive_fanzei_count=0;
int alive_zhongzhu_count=0;
int n,m;
int ans;
#define UNKNOW 0
#define MPWIN 1
#define FPWIN 2
bool check_MP_alive();
void recal_all();
int in_zhuzu[MAXN];//在主猪心中类型
class pig_class;
pig_class* get_mp();
bool start_wx_circle(pig_class * start,bool y_is_fan);
class pig_class
{
	private :
		int type;//猪的类型
		int csf;//当前类型0没跳 1类反 2跳忠 3跳反
		bool alive;//活着没
		pig_class *next;
		pig_class *pro;
		pig_class *shouyao;//首要攻击目标
		pig_class *last;//最后一个伤害来源
		int id;
		int tili;
	public :
		zhu_pai_class pai;//牌
							pig_class	()				{tili=4;alive=true;type=TYPE_UNKNOW;shouyao=NULL;}
		inline	pig_class*	set_next	(pig_class *n)	{return next=n;}
		inline	pig_class*	set_pro		(pig_class *p)	{return pro=p;}
		inline	pig_class*	get_next	()				{return next;}
		inline	pig_class*	get_pro		()				{return pro;}
		inline	int			add_tili	()				{return ++tili;}
		inline	int			del_tili	()				{return --tili;}
		inline	int			get_tili	()				{return tili;}		
		inline	int			set_id		(int i)			{return id=i;}
		inline	int			get_id		()				{return id;}
		inline	int			set_type	(int i)			{if(i==FP)alive_fanzei_count++;else alive_zhongzhu_count++;return type=i;}
		inline	int			get_type	()				{return type;}
		inline	int			set_csf		(int i)			{return csf=i;}
		inline	int			get_csf		()				{return csf;}
		inline	bool		ifalive		()				{return alive;}
		void die(pig_class *from)							//料理这只猪的后事
		{
//			cerr<<"\t"<<get_id()<<" die by "<<from->get_id()<<endl;
			if(type==FP)
				alive_fanzei_count--;
			else
				alive_zhongzhu_count--;
			get_pro()->set_next(get_next());
			get_next()->set_pro(get_pro());
			alive=false;
			if(get_type()!=MP)
				if(get_type()==ZP&&from->get_type()==MP)
				{
//					cerr<<"\tMP lose all pai"<<endl;
					from->pai.del_all();
				}
			if(alive_fanzei_count<=0)
			{
				ans=MPWIN;
				return;
			}
			else if(alive_zhongzhu_count<=0)
			{
				ans=FPWIN;
				return;
			}
			else if(!check_MP_alive())//主猪死了
			{
				ans=FPWIN;
				return;
			}		
			if(get_type()==FP&&(!ans))
			{
//				last->pai.print_all(stderr);
				last->pai.reset_now_to_tail();
				last->pai.add(all_pai.del());
				last->pai.add(all_pai.del());
				last->pai.add(all_pai.del());
//				cerr<<"\t"<<last->get_id()<<" get 3 pai have";last->pai.print_all(stderr);
			}
			recal_all();
		}
		void hurt(pig_class *from)			//来自from的猪使这只猪-1s
		{
			last=from;
			if(del_tili()==0)				//快死了
				if(pai.try_use_p())			//尝试+1s
					add_tili();				//+1s
				else
				{
					die(from);				//拜拜甜甜圈
					return ;
				}
//			cerr<<"\t"<<from->get_id()<<" hurt "<<get_id()<<" tili:"<<get_tili()<<endl;
		}
		void recal()						//依据这只猪的信息更新其他猪
		{
			pig_class* y=get_next();
			if(get_type()==MP)
			{
				while(y!=this)
				{
					if(y->get_csf()==1||y->get_csf()==3)
					{
						shouyao=y;
						return ;
					}
					y=y->get_next();
				}
				shouyao=NULL;
			}
			else if(get_type()==ZP)
			{
				while(y!=this)
				{
					if(y->get_csf()==3)
					{
						shouyao=y;
						return ;
					}
					y=y->get_next();
				}
				shouyao=NULL;
			}
			else
			{
				while(y!=this)
				{
					if(y->get_csf()==2||y->get_type()==1)
					{
						shouyao=y;
						return ;
					}
					y=y->get_next();
				}
				shouyao=NULL;
			}
		}
		void round()
		{
			pai.reset_now_to_tail();
			pai.add(all_pai.del());
			pai.add(all_pai.del());		
			pai.reset_now();bool flag=false;
			bool usedsha=false;
			link_list *tmp=pai.get_now();
//			cerr<<""<<get_id()<<" have ";pai.print_all(stderr);
			while((!ans)&&(tmp=(flag?(pai.get_nxt()):(pai.get_now()))))
			{
				if(tmp==NULL)
					return;
				if(!tmp->get())
					return;
//				pai.print_all(stderr);
				flag=true;
//				cerr<<"\t"<<get_id()<<"use "<<getpai(tmp->get())<<endl;
				if(tmp->get()==D||tmp->get()==J)
					continue;
				if(get_tili()!=4&&tmp->get()==P)																//吃桃子
				{
					pai.del(tmp);
					pai.reset_now();flag=false;
					add_tili();
//					cerr<<"\t"<<get_id()<<"have "<<get_tili()<<" tili"<<endl;
					continue;
				}
				if(tmp->get()==K)																			//杀
				{
					if(shouyao==get_next()&&shouyao->ifalive())
					{
						if(!usedsha||pai.have_z())
						{
							pai.del(tmp);
							usedsha=true;
							if(get_type()!=MP&&get_csf()<2)
							{
								if(shouyao->get_type()==FP)
									set_csf(2);
								else
									set_csf(3);
								recal_all();
							}
							if(!shouyao->pai.try_use_d())
								shouyao->hurt(this);
							else
//								cerr<<"\t"<<shouyao->get_id()<<" lose D now have ";shouyao->pai.print_all(stderr);
							pai.reset_now();flag=false;
							if(ans||(!ifalive()))
								return ;
						}
					}
				}
				if(tmp->get()==Z)
				{
					pai.del(tmp);
					pai.add_z();
					pai.reset_now();flag=false;
				}
				if(tmp->get()==F)																			//决斗
				{
					if(shouyao==NULL||!shouyao->ifalive())																		//没有攻击目标
						continue;
					pai.del(tmp);
					pig_class* tmp=shouyao;					
					if(get_type()==FP)
						tmp=get_mp();
					pig_class* buf=tmp;
					if(get_type()!=MP&&get_csf()<2)
					{
						if(buf->get_type()==3)
							set_csf(2);
						else
							set_csf(3);
						recal_all();
					}
					if(buf->get_type()==1||buf->get_csf()>=2)
					{
						if(buf->get_type()==1||buf->get_csf()==2)
						{
							if(start_wx_circle(this,0))
							{
								pai.reset_now();flag=false;
								if(ans||(!ifalive()))
									return ;
								continue ;
							}
						}
						else
						{
							if(start_wx_circle(this,1))
							{
								pai.reset_now();flag=false;
								if(ans||(!ifalive()))
									return ;
								continue ;
							}
						}
					}
					if(get_type()==MP&&tmp->get_type()==ZP)
						tmp->hurt(this);
					else
					{
						while(1)
						{
							if(!tmp->pai.try_use_k())
							{
								tmp->hurt(this);
								break ;
							}
							if(!pai.try_use_k())
							{
								hurt(tmp);
								break ;
							}
						}
					}
					pai.reset_now();flag=false;
					if(ans||(!ifalive()))
						return ;
				}
				if(tmp->get()==N)																		//南猪入侵
				{
					pai.del(tmp);
					pig_class* buf=get_next();//从下一只猪开始
					while(buf!=this)//不是这个猪
					{
//						cerr<<"\t"<<buf->get_id()<<" csf="<<buf->get_csf()<<endl;
						if(buf->get_type()==MP||buf->get_csf()>=2)
						{
							if(buf->get_type()==MP||buf->get_csf()==2)
							{
								if(start_wx_circle(this,0))
								{
//									cerr<<"\t"<<buf->get_id()<<" lose J now have ";buf->pai.print_all(stderr);
									buf=buf->get_next();
									continue;
								}
							}
							else
							{
								if(start_wx_circle(this,1))
								{
//									cerr<<"\t"<<buf->get_id()<<" lose J now have ";buf->pai.print_all(stderr);
									buf=buf->get_next();
									continue;
								}
							}
						}
						if(!buf->pai.try_use_k())
						{
							buf->hurt(this);
							if(ans)
								return;
							if(buf==get_mp()&&get_csf()==0)
							{
								set_csf(1);
								recal_all();
							}
						}
						else
						{
//							cerr<<"\t"<<buf->get_id()<<" lose K now have ";buf->pai.print_all(stderr);
						}
						buf=buf->get_next();
					}
					pai.reset_now();flag=false;
					if(ans)
						return ;
					continue;
				}
				if(tmp->get()==W)																	//万箭齐发
				{
					pai.del(tmp);
					pig_class* buf=get_next();//从下一只猪开始					
					while(buf!=this)//不是这个猪
					{
//						cerr<<"\t"<<buf->get_id()<<" csf="<<buf->get_csf()<<" type="<<buf->get_type()<<endl;
						if(buf->get_type()==MP||buf->get_csf()>=2)
						{
							if(buf->get_type()==MP||buf->get_csf()==2)
							{
								if(start_wx_circle(this,0))
								{
//									cerr<<"\t"<<buf->get_id()<<" lose J now have ";buf->pai.print_all(stderr);
									buf=buf->get_next();
									continue;
								}
							}
							else
							{
								if(start_wx_circle(this,1))
								{
//									cerr<<"\t"<<buf->get_id()<<" lose J now have ";buf->pai.print_all(stderr);									
									buf=buf->get_next();
									continue;
								}
							}
						}
						if(!buf->pai.try_use_d())
						{
							buf->hurt(this);
							if(ans)
								return;
							if(buf==get_mp()&&get_csf()==0)
							{
								set_csf(1);
								recal_all();
							}
						}
						else
						{
//							cerr<<"\t"<<buf->get_id()<<" lose D now have ";buf->pai.print_all(stderr);
						}
						buf=buf->get_next();
					}
					pai.reset_now();flag=false;
					if(ans)
						return ;
				}
			}
		}
};
pig_class pig[MAXN];
void recal_all()
{
	pig_class* x=&pig[1];
	do
	{
		x->recal();
		x=x->get_next();
	}	
	while(x!=&pig[1]);
}
pig_class* get_mp()
{
	return &pig[1];
}
bool check_MP_alive()
{
	return pig[1].ifalive();
}
bool start_wx_circle(pig_class * start,bool y_is_fan)
{
	bool st=y_is_fan;
	pig_class *lastdachu=start,*x=start;
	if(y_is_fan==(x->get_type()==FP))
	{
		if(x->pai.try_use_j())
		{
			lastdachu=x;
			y_is_fan^=1;
			if(x->get_csf()<=2)
			{
//				cerr<<"\tset "<<x->get_id()<<" csf to "<<3-y_is_fan<<endl;
				x->set_csf(3-y_is_fan);
				recal_all();
			}
		}
	}
	x=x->get_next();
	while(x!=lastdachu)
	{
		if(y_is_fan==(x->get_type()==3))
		{
			if(x->pai.try_use_j())
			{
				lastdachu=x;
				y_is_fan^=1;
				if(x->get_csf()<=2)
				{
//					cerr<<"\tset "<<x->get_id()<<" csf to "<<3-y_is_fan<<endl;
					x->set_csf(3-y_is_fan);
					recal_all();
				}
			}
		}
		x=x->get_next();
	}
	return (st!=y_is_fan);
}
int main()
{
 	freopen("2885.in","r",stdin);
// 	freopen("2885.out","w",stdout);
// 	freopen("2885.err","w",stderr);
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		pig[i].set_id(i);
		pig[i].set_pro(&pig[i-1]);
		pig[i].set_next(&pig[i+1]);
		pig[i].set_type(readtype());
		pig[i].pai.add(readpai());
		pig[i].pai.add(readpai());
		pig[i].pai.add(readpai());
		pig[i].pai.add(readpai());
//		pig[i].pai.print_all(stderr);
	}
	pig[1].set_pro(&pig[n]);
	pig[n].set_next(&pig[1]);
	recal_all();
	for(int i=0;i<m;i++)
		all_pai.add(readpai());
	pig_class *pig_now=&pig[1];
	while(!ans)
	{
		pig_now->round();
		pig_now->pai.reset_now();
		pig_now=pig_now->get_next();
	}
	if(ans==MPWIN)
		puts("MP");
	else
		puts("FP");
	for(int i=1;i<=n;i++)
		if(!pig[i].ifalive())
			puts("DEAD");
		else
		{
//			puts("ALIVE");
			pig[i].pai.print_all(stdout);
		}
	fclose(stdin);
	fclose(stdout);
 	return 0;
}
