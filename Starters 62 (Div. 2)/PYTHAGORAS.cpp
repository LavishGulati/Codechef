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

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		double a = sqrt(n);
		if (a - floor(a) == 0) {
			cout << 0 << " " << ll(a) << endl;
			continue;
		}

		ll help = 0, dup = n, x;
		while (dup%2 == 0) {
			help++;
			dup /= 2;
		}

		help = pow(2, help/2);
		bool found = false;
		for (ll i = 1; i*i <= dup; i += 2) {
			x = n - help * help * i * i;
			if (x < 0) {
				break;
			}

			a = sqrt(x);
			if (a - floor(a) == 0) {
				cout << help * i << " " << ll(a) << endl;
				found = true;
				break;
			}
		}

		if (found) {
			continue;
		} else {
			cout << -1 << endl;
		}
	}
}