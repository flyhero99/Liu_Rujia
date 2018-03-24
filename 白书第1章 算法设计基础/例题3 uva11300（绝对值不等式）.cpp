#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))

const int maxn = 1000005;

ll a[maxn], c[maxn], tot, M;
int n;

int main() {
	while(scanf("%d", &n) != EOF) {
		tot = 0;
		for(int i = 1;i <= n;i++) {
			scanf("%lld", &a[i]);
			tot += a[i];
		}
		M = tot/n;
		c[0] = 0;
		for(int i = 1;i < n;i++) { // 递推C数组
			c[i] = c[i-1]+a[i]-M;
		}
		sort(c, c+n);
		ll x1 = c[n/2], ans=0;
		for(int i = 0;i < n;i++) ans += abs(x1-c[i]); // 把x1代入，计算转手的金币总数
		printf("%lld\n", ans);
	}
	return 0;
}