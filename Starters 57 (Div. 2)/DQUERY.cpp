#include <bits/stdc++.h>
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
#define MOD 1000000007

ll a[MAX], sieve[MAX];
unordered_map< ll, map< ll, pll > > freq;
unordered_map< ll, vector< ll > > sorted;
unordered_set< ll > help;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (ll i = 0; i < MAX; i++) {
		sieve[i] = 0;
	}
	sieve[1] = 1;
	for (ll p = 2; p*p <= MAX; p++) {
		if (sieve[p] == 0) {
			for (ll x = p*p; x < MAX; x += p) {
				if (sieve[x] == 0) {
					sieve[x] = p;
				}
			}
		}
	}
	for (ll p = 1; p < MAX; p++) {
		if (sieve[p] == 0) {
			sieve[p] = p;
		}
	}

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}

		freq.clear();
		sorted.clear();
		for (ll i = 0; i < n; i++) {
			ll x = a[i];
			help.clear();
			while (x > 1) {
				help.insert(sieve[x]);
				x /= sieve[x];
			}
			for (ll p : help) {
				freq[p][i] = {a[i], 1};
				sorted[p].pb(a[i]);
			}
		}

		ll sum, cnt;
		for (const auto& [p, _] : freq) {
			sum = 0; cnt = 0;
			for (auto [idx, _] : freq[p]) {
				sum += freq[p][idx].f;
				cnt++;
				freq[p][idx] = {sum, cnt};
			}
		}

		for (const auto& [p, _] : sorted) {
			sort(all(sorted[p]), greater<ll>());
			sum = 0;
			for (ll i = 0; i < sorted[p].size(); i++) {
				sum += sorted[p][i];
				sorted[p][i] = sum;
			}
		}

		for (ll i = 1; i < n; i++) {
			a[i] += a[i-1];
		}

		ll q, ans;
		cin >> q;
		while (q--) {
			ll p, k;
			cin >> p >> k;

			if (freq.find(p) == freq.end()) {
				ans = a[k-1];
			} else {
				auto it = freq[p].upper_bound(k-1);
				if (it == freq[p].begin()) {
					ans = a[k-1];
				} else {
					it--;
					ans = a[k-1];
					ans -= it->s.f;
					ans += sorted[p][it->s.s-1];
				}
			}
			cout << ans << endl;
		}
	}
}