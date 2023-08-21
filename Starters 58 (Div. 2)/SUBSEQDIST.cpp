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

int dp[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i < MAX; i++) {
		dp[i] = min(1+dp[i-1], 1+max(dp[i/2], dp[i-i/2]));
	}

	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n;

		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> x;
			mp[x]++;
		}

		int ans = 0;
		for (const auto& [_, freq] : mp) {
			ans = max(ans, dp[freq]);
		}
		cout << ans << endl;
	}
}