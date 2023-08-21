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
// #define mp make_pair
#define all(x) x.begin(), x.end()

#define MAX 100005
#define MAXA 1000005
#define MOD 1000000007

ll sieve[MAXA];
ll a[MAX];

ll power(ll x, ll n) {
	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x%MOD;
	}

	ll y = power(x, n/2);
	y = (y*y)%MOD;
	if (n%2) {
		return (x*y)%MOD;
	} else {
		return y;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < MAXA; i++) {
		sieve[i] = -1;
	}
	sieve[0] = sieve[1] = 1;
	for (ll i = 2; i*i < MAXA; i++) {
		if (sieve[i] == -1) {
			sieve[i] = i;
			for (ll p = i*i; p < MAXA; p += i) {
				if (sieve[p] == -1) {
					sieve[p] = i;
				}
			}
		}
	}
	for (int i = 0; i < MAXA; i++) {
		if (sieve[i] == -1) {
			sieve[i] = i;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int x, m;
		unordered_map<int, int> primes;
		unordered_map< int, vector<int> > mp;
		for (int i = 0; i < n; i++) {
			cin >> x;
			primes.clear();
			while (x > 1) {
				primes[sieve[x]]++;
				x /= sieve[x];
			}
			for (const auto& [p, val] : primes) {
				mp[p].pb(val);
			}
		}

		for (int i = 0; i < n; i++) {
			a[i] = 1;
		}
		for (auto it : mp) {
			int p = it.f;
			auto v = it.s;
			m = v.size();
			sort(all(v));
			for (int i = m-1; i >= 0; i--) {
				a[n-m+i] = (a[n-m+i]*power(p, v[i]))%MOD;
			}
		}

		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ans = (ans+a[i])%MOD;
		}
		cout << ans << endl;
	}
}