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

#define MAX 1000005
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

ll modInverse(ll x) {
	return power(x, MOD-2);
}

ll pwr[MAX], fact[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	pwr[0] = 1;
	for (int i = 1; i < MAX; i++) {
		pwr[i] = (pwr[i-1]*2)%MOD;
	}

	fact[0] = 1;
	for (int i = 1; i < MAX; i++) {
		fact[i] = (i*fact[i-1])%MOD;
	}

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		ll ans = 1;
		if ((n+m-1)%2) {
			cout << 0 << endl;
			continue;
		} else if (n == 1 && m == 1) {
			cout << 0 << endl;
			continue;
		}

		ans = fact[n+m-2];
		ans = (ans*modInverse(fact[n-1]))%MOD;
		ans = (ans*modInverse(fact[m-1]))%MOD;
		ans = (ans*fact[n+m-1])%MOD;
		ans = (ans*modInverse(fact[(n+m-1)/2]))%MOD;
		ans = (ans*modInverse(fact[(n+m-1)/2]))%MOD;
		ans = (ans*pwr[n*m-n-m+1])%MOD;
		cout << ans << endl;
	}
}