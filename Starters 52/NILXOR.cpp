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

#define MOD 1000000007

ll xbin[35];
bool change[35];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll n, x;
		cin >> n >> x;

		for (ll i = 0; i < 35; i++) {
			xbin[i] = 0;
			change[i] = true;
		}

		ll dup = x, idx = 34;
		while (dup > 0) {
			xbin[idx] = dup%2;
			--idx; dup /= 2;
		}

		dup = n, idx = 34;
		string s = "";
		while (dup > 0) {
			s += '0' + dup%2;
			if (xbin[idx] && dup%2) {
				change[idx] = false;
			}
			--idx; dup /= 2; 
		}
		// cout << s << endl;

		// for (int i = 0; i < 35; i++) {
		// 	cout << change[i] << " ";
		// }
		// cout << endl;

		for (ll i = 33; i >= 0; i--) {
			xbin[i] += xbin[i+1];
		}

		ll m = s.length(), ans = 0;
		for (ll i = m-1; i >= 0; i--) {
			if (s[i] == '1' && change[34-i]) {
				ans += pow(2, i - xbin[34-i]);
			}
		}
		cout << ans << endl;
	}
}