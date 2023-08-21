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

#define MAX 200005
#define MOD 1000000007

pii a[MAX];
int rght[MAX], dp[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i].s;
		}
		for (int i = 0; i < n; i++) {
			cin >> a[i].f;
		}

		sort(a, a+n);
		rght[n-2] = n-1;
		for (int i = n-3; i >= 0; i--) {
			if (a[rght[i+1]].s < a[i+1].s) {
				rght[i] = rght[i+1];
			} else {
				rght[i] = i+1;
			}
		}

		dp[n-1] = 0;
		int ans = 0;
		for (int i = n-2; i >= 0; i--) {
			if (a[rght[i]].s < a[i].f) {
				dp[i] = 1 + dp[rght[i]];
			} else {
				dp[i] = 0;
			}
			ans = max(ans, dp[i]);
		}
		cout << ans << endl;
	}
}