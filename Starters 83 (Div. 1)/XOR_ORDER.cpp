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
		int a, b, c;
		cin >> a >> b >> c;

		int bita, bitb, bitc;
		int x = 0, idx;
		bool poss = true, compareab = false, comparebc = false;
		for (idx = 29; idx >= 0; idx--) {
			bita = (a>>idx)&1;
			bitb = (b>>idx)&1;
			bitc = (c>>idx)&1;
			if (!bita && !bitb && bitc) {
				compareab = true;
				break;
			} else if (!bita && bitb && !bitc) {
				poss = false;
				break;
			} else if (bita && !bitb && !bitc) {
				x ^= 1<<idx;
				comparebc = true;
				break;
			} else if (bita && bitb && !bitc) {
				x ^= 1<<idx;
				compareab = true;
				break;
			}
			else if (bita && !bitb && bitc) {
				poss = false;
				break;
			} else if (!bita && bitb && bitc) {
				comparebc = true;
				break;
			}
		}

		if (!poss) {
			cout << -1 << endl;
			continue;
		}

		if (comparebc) {
			a = b;
			b = c;
		}

		poss = false;
		while (idx >= 0) {
			bita = (a>>idx)&1;
			bitb = (b>>idx)&1;
			if (!bita && bitb) {
				poss = true;
				break;
			} else if (bita && !bitb) {
				poss = true;
				x ^= 1<<idx;
				break;
			}
			idx--;
		}

		if (!poss) {
			cout << -1 << endl;
		} else {
			cout << x << endl;
		}
	}
}