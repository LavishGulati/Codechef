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

#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll n, m, k;
		cin >> n >> m >> k;

		ll s1 = 0, s2 = 0, x;
		for (ll i = 0; i < n; i++) {
			cin >> x;
			s1 += x;
		}
		for (ll i = 0; i < m; i++) {
			cin >> x;
			s2 += x;
		}

		ll diff = s2 * n - s1 * m;
		if (diff < 0) {
			cout << 0 << endl;
			continue;
		} else if (diff >= 0 && k == 1) {
			cout << -1 << endl;
			continue;
		}

		ll d1 = m*k - s2, d2 = s1 - n, ans = 0;
		while (diff >= 0) {
			if (d1 > d2) {
				diff -= d1;
				d2 += k-1;
			} else {
				diff -= d2;
				d1 += k-1;
			}
			ans++;
		}
		cout << ans << endl;
	}
}