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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;

		ll a = 1;
		bool ans = false;
		while (x - a*a - 4*a >= 0) {
			if (x - a*a - 4*a == 0 || (x - a*a - 4*a) % (a + 2) == 0) {
				ans = true;
				break;
			}
			a++;
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
}