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

int a[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		bool *diff = new bool[32];
		bool zero, one;
		for (int j = 0; j < 32; j++) {
			zero = false;
			one = false;
			for (int i = 0; i < n; i++) {
				if (a[i]&(1<<j)) {
					one = true;
				} else {
					zero = true;
				}
			}
			if (one && zero) {
				diff[j] = true;
			} else {
				diff[j] = false;
			}
		}

		int ans = -1;
		for (int i = 0; i < 32; i++) {
			if (!(x&(1<<i)) && diff[i]) {
				ans = x;
				break;
			}
		}

		if (ans != -1) {
			cout << ans << endl;
			continue;
		}

		int idx;
		for (idx = 0; idx < 32; idx++) {
			if (diff[idx]) {
				ans = x;
				ans = ans^(1<<idx);
				break;
			}
		}
		for (int i = 0; i < idx; i++) {
			ans = ans|(1<<i);
		}
		cout << ans << endl;
	}
}