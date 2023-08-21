#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair< int, pair<int, int> > tii;
typedef pair< long long, pair<long long, long long> > tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 998244353

ll power(ll x, ll n) {
	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x%MOD;
	}

	ll y = power(x, n/2);
	if (n%2) {
		return (x*((y*y)%MOD))%MOD;
	} else {
		return (y*y)%MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		int *dp = new int[32];
		ll help = 2;
		for (int i = 0; i < 32; i++) {
			dp[i] = ((m+1)/help)*(help/2);
			if (i > 0 && m%help != help-1) {
				dp[i] += max(0LL, (m%help)-help/2+1);
			}
			help *= 2;
		}

		ll ans = 0, smallans;
		help = 1;
		for (int i = 0; i < 32; i++) {
			smallans = (power(dp[i], n) * help)%MOD;
			ans = (ans+smallans)%MOD;
			help *= 2;
		}
		cout << ans << endl;
	}
}