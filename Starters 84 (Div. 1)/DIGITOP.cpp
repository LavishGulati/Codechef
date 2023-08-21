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
		ll n, k;
		cin >> n >> k;

		ll *sizes = new ll[n], total = 0;
		char *freq1 = new char[10], *freq2 = new char[10];
		for (ll i = 0; i < 10; i++) {
			freq1[i] = freq2[i] = 0;
		}

		string s;
		for (ll i = 0; i < n; i++) {
			cin >> s;
			sizes[i] = s.length();
			for (char c : s) {
				freq1[c-'0']++;
			}
		}

		bool poss = true;
		for (ll i = 0; i < n; i++) {
			cin >> s;
			if (s.length() != sizes[i]) {
				poss = false;
			}
			for (char c : s) {
				freq2[c-'0']++;
			}
		}

		if (!poss) {
			cout << "NO" << endl;
			continue;
		}

		for (ll i = 0; i < 10; i++) {
			if (freq1[i] != freq2[i]) {
				total += max(freq1[i], freq2[i]) - min(freq1[i], freq2[i]);
			}
		}
		total /= 2;
		cout << (total <= k ? "YES" : "NO") << endl;
	}
}