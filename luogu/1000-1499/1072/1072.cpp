#include<cstdio>
#include <iostream>
#include "cmath"
using namespace std;
int n,a0,a1,b0,b1,k,ans,out;
int gcd(int a,int b)//���Լ��
{
	return b?gcd(b,a%b):a;
}
int main()
{
	freopen("1072.in","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        ans=0;
        if(b1%a1!=0)
        {
        	printf("0\n");
        	continue;
        }
        for(int x=1;x*x<=b1;x++)
        {
            if((b1%x)==0)//x��Ȼ��b1������
            {
                k=b1/x;//ö����һ�������
printf("k=%d,b1=%d,x=%d\n",k,b1,x);
//printf("\tgcd(x,a0)=%d",gcd(x,a0));
//printf("\tgcd(k,a0)=%d\n",gcd(k,a0));
			    if((gcd(x,a0)==a1)&&(x*b0==b1*gcd(x,b0)))
					ans++;//�����ж�
				if(k==x)
					continue;
                if((gcd(k,a0)==a1)&&(k*b0==b1*gcd(k,b0)))
					ans++;//ע��Ҫ���ظ�ҲҪ�ж�һ��
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

