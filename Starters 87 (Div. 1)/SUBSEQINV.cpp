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

#define MAX 100005
#define MOD 998244353

int a[MAX];
unordered_map<int, int> rev_idx;

ll power(ll x, ll n) {
	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x%MOD;
	}

	ll y = power(x, n/2);
	y = (y*y)%MOD;
	if (n%2) {
		y = (y*x)%MOD;
	}
	return y;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		rev_idx.clear();

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			rev_idx[a[i]] = i;
		}

		int last_idx = -1, maxel = 0, cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (i > maxel && rev_idx[i] == last_idx+1) {
				cnt++;
			}
			for (int j = last_idx+1; j <= rev_idx[i]; j++) {
				maxel = max(maxel, a[j]);
			}
			last_idx = max(last_idx, rev_idx[i]);
		}

		ll ans;
		if (cnt == n) {
			ans = (power(2, cnt) - 1 + MOD)%MOD;
		} else {
			ans = power(2, cnt);
		}
		cout << ans << endl;
	}
}