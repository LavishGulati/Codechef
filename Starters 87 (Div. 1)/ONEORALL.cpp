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
		ll n;
		cin >> n;

		ll x, sum = 0, minel = LLONG_MAX;
		for (ll i = 0; i < n; i++) {
			cin >> x;
			sum += x;
			minel = min(minel, x);
		}

		if (n%2) {
			if (sum%2) {
				cout << "CHEF" << endl;
			} else {
				cout << "CHEFINA" << endl;
			}
		} else if (sum%2 || minel%2) {
			cout << "CHEF" << endl;
		} else {
			cout << "CHEFINA" << endl;
		}
	}
}