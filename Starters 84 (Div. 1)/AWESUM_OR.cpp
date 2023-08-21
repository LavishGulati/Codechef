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
	y = (y*y)%MOD;
	if (n%2) {
		y = (x*y)%MOD;
	}
	return y;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		ll bits = 0;
		while (n > 0) {
			bits += n%2;
			n /= 2;
		}
		ll ans = power(3, bits);
		ans = (ans+3)%MOD;
		ans = (ans-((3*power(2, bits))%MOD)+MOD)%MOD;
		cout << ans << endl;
	}
}