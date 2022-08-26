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

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

ll a[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}

		ll ans = gcd(a[0], a[1]);
		for (ll i = 2; i < n; i++) {
			ans = gcd(ans, a[i]);
		}
		cout << ans * n << endl;
	}
}