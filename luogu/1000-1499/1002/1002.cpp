#include<iostream>
#include <cstdio>
#include<algorithm> 
using namespace std;
int x,y,n,m,shu;
int tiaoguo[400][400];
int qipan[20][20];
int x1,y1;
int main()
{
	cin>>x>>y>>n>>m;
	qipan[x][y]=3;
	qipan[n][m]=2;
	
	
} 
//#include<iostream>
//#include<cmath>
//long long int f[100][100]={{0}},n,m,nn,mm,i,j;
//using namespace std;
//int main()
//{
//    cin>>n>>m>>nn>>mm;
//    n++,m++,nn++,mm++,f[0][1]=1;//初始位置设为1
//    for(i=1;i<=n;i++)
//    {
//        for(j=1;j<=m;j++)
//        {
//            if((abs(i-nn)+abs(j-mm)==3)/*注意这两个的之间的曼哈顿距离等于3说明会被马拦*/&&(i!=nn)&&(j!=mm)||(i==nn&&j==mm)/*此处有重复，避免卒吃马*/)continue;//如果犯规就退出
//            else{f[i][j]=f[i-1][j]+f[i][j-1];}//不需要解释的上+左
//        }
//   }
///    cout<<f[n][m];//最后输出目标点上的路径条数
//    return 0;
//}
