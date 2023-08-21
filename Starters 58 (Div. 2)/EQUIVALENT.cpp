#include <bits/stdc++.h>
#include <unordered_map>
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

#define MAX 1000005
#define MOD 1000000007

int sieve[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < MAX; i++) {
		sieve[i] = -1;
	}
	sieve[1] = 1;
	for (ll i = 2; i*i < MAX; i++) {
		if (sieve[i] == -1) {
			sieve[i] = i;
			for (ll p = i*i; p < MAX; p += i) {
				sieve[p] = i;
			}
		}
	}

	for (int i = 2; i < MAX; i++) {
		if (sieve[i] == -1) {
			sieve[i] = i;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;

		unordered_map<int, int> mp1, mp2;
		while (x > 1) {
			mp1[sieve[x]]++;
			x /= sieve[x];
		}
		while (y > 1) {
			mp2[sieve[y]]++;
			y /= sieve[y];
		}

		bool poss = true;
		double check = -1;
		for (const auto& [x, val] : mp1) {
			if (mp2.find(x) == mp2.end()) {
				poss = false;
				break;
			}
			if (check == -1) {
				check = double(mp2[x])/mp1[x];
			} else if (double(mp2[x])/mp1[x] != check) {
				poss = false;
				break;
			}
		}

		if (!poss) {
			cout << "NO" << endl;
			continue;
		}

		for (const auto& [x, val] : mp2) {
			if (mp1.find(x) == mp1.end()) {
				poss = false;
				break;
			}
			if (check == -1) {
				check = double(mp2[x])/mp1[x];
			} else if (double(mp2[x])/mp1[x] != check) {
				poss = false;
				break;
			}
		}

		if (poss) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}