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

	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;

		// 2 * cos(n*pi/3)
		vector<ll> x = {2, 1, -1, -2, -1, 1};
		// 2 * sin((2n-1)*pi/6)
		vector<ll> y = {-1, 1, 2, 1, -1, -2};

		ll a0 = ((power(2, n) + x[n%6])%MOD * (power(3, MOD-2)))%MOD;
		ll a1 = ((power(2, n) + y[n%6])%MOD * (power(3, MOD-2)))%MOD;
		ll a2 = (power(2, n) - a0 - a1 + 2*MOD)%MOD;

		ll b0 = ((power(2, m) + x[m%6])%MOD * (power(3, MOD-2)))%MOD;
		ll b1 = ((power(2, m) + y[m%6])%MOD * (power(3, MOD-2)))%MOD;
		ll b2 = (power(2, m) - b0 - b1 + 2*MOD)%MOD;

		ll ans = ((a0*b0)%MOD + (a1*b1)%MOD + (a2*b2)%MOD - 1 + MOD)%MOD;
		cout << ans << endl;
	}
}