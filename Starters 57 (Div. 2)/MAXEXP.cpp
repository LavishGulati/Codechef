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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		int freq[10];
		for (int i = 0; i < 10; i++) {
			freq[i] = 0;
		} 
		int plus = 0, minus = 0;
		for (char c : s) {
			if (c == '+') {
				plus++;
			} else if (c == '-') {
				minus++;
			} else {
				freq[c-'0']++;
			}
		}

		string ans = "";
		int idx = 0;
		while (minus > 0) {
			while (idx < 10 && freq[idx] == 0) {
				idx++;
			}
			ans += '0'+idx;
			freq[idx]--;
			ans += '-';
			minus--;
		}

		while (plus > 0) {
			while (idx < 10 && freq[idx] == 0) {
				idx++;
			}
			ans += '0'+idx;
			freq[idx]--;
			ans += '+';
			plus--;
		}

		while (idx < 10) {
			while (freq[idx] > 0) {
				ans += '0'+idx;
				freq[idx]--;
			}
			idx++;
		}

		reverse(all(ans));
		cout << ans << endl;
	}
}