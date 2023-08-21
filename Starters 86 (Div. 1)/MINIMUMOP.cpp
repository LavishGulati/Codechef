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
#define MAXA 1000005
#define MOD 1000000007

int sieve[MAXA];
vector<int> primes;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < MAXA; i++) {
		sieve[i] = -1;
	}
	sieve[0] = sieve[1] = 1;
	for (int p = 2; p*p < MAXA; p++) {
		if (sieve[p] == -1) {
			sieve[p] = p;
			for (int i = p*p; i < MAXA; i += p) {
				sieve[i] = p;
			}
		}
	}
	for (int i = 2; i < MAXA; i++) {
		if (sieve[i] == -1) {
			sieve[i] = i;
		}
		if (sieve[i] == i) {
			primes.pb(i);
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		bool equal = true;
		int prev = -1, gcd = -1, x;
		unordered_set<int> poss;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (prev == -1) {
				prev = x;
			} else if (x != prev) {
				equal = false;
			}
			if (gcd == -1) {
				gcd = x;
			} else {
				gcd = __gcd(gcd, x);
			}
			while (x > 1) {
				poss.insert(sieve[x]);
				x /= sieve[x];
			}
		}

		if (equal) {
			cout << 0 << endl;
			continue;
		}

		if (gcd > 1) {
			cout << 1 << endl;
			cout << gcd << endl;
			continue;
		}

		int nopres = -1;
		for (int i = 0; primes[i] <= m; i++) {
			if (!poss.count(primes[i])) {
				nopres = primes[i];
				break;
			}
		}
		if (nopres != -1) {
			cout << 1 << endl;
			cout << nopres << endl;
		} else {
			cout << 2 << endl;
			cout << 2 << " " << 3 << endl;
		}
	}
}