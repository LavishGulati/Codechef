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
#define MOD 1000000007

set<ll> a;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll n, k, x;
		cin >> n >> k;

		a.clear();
		for (ll i = 0; i < n; i++) {
			cin >> x;
			a.insert(x);
		}

		vector<ll> missing(k);
		ll j = 0;
		for (ll i = 1; i <= 2*n && j < k; i++) {
			if (a.find(i) == a.end()) {
				missing[j] = i;
				j++;
			}
		}

		ll exmax = *a.rbegin();
		for (ll i = 1; i < k; i++) {
			missing[i] += missing[i-1];
		}

		ll ans = LLONG_MIN;
		ans = max(ans, exmax*k-missing[k-1]);
		for (ll i = 2*n; i > exmax; i--) {
			if (a.find(i) == a.end()) {
				ans = max(ans, (k-1)*i - (k-2 >= 0 ? missing[k-2] : 0));
			}
		}
		cout << ans << endl;
	}
}