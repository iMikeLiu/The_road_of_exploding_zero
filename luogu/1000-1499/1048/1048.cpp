#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 1003;

int n, m, v[maxn], w[maxn], ans, f[maxn];
// v: ti ji
// w: jia zhi

int main() 
{
	freopen("1048.in","r",stdin);
	cin >> m >> n;
	for (int i = 1; i <= n; ++ i) 
	{
		cin >> v[i] >> w[i];
	}
	for (int i = 1; i <= n; ++ i) 
	{
		for (int j = 0; j + v[i] <= m; ++ j) {
			f[j] = max(f[j], f[j + v[i]] + w[i]);
		}
	}
	cout << f[0] << endl;
}
