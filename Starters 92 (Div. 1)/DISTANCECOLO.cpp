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

#define MAX 105
#define MOD 1000000007

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

ll modInverse(ll x) {
	return power(x, MOD-2);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll *fact = new ll[MAX];
	fact[0] = 1;
	for (ll i = 1; i < MAX; i++) {
		fact[i] = (i * fact[i-1])%MOD;
	}

	ll *inv = new ll[MAX];
	for (ll i = 0; i < MAX; i++) {
		inv[i] = modInverse(fact[i]);
	}

	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;

		if (n >= k) {
			cout << fact[k] << endl;
			continue;
		}

		ll ans = fact[n];
		ans = (ans * fact[k])%MOD;
		ans = (ans * inv[n])%MOD;
		ans = (ans * inv[k-n])%MOD;
		cout << ans << endl;
	}
}