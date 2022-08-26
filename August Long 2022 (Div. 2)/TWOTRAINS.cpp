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

#define MAX 100005
#define MOD 1000000007

int p[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n-1; i++) {
			cin >> p[i];
		}

		if (n == 2) {
			cout << 2 * p[0] << endl;
			continue;
		}

		int ans = 2 * p[0];
		int help = p[0] + p[1];
		for (int i = 0; i < n-2; i++) {
			if (help <= ans) {
				ans += p[i+1];
			} else {
				ans += help - ans + p[i+1];
			}
			help += p[i+2];
		}
		cout << ans << endl;
	}
}