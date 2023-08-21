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
#define MOD 998244353

ll dp[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		int n = s.length();

		dp[0] = 1;
		for (int i = 1; i < n; i++) {
			dp[i] = 0;
			if (s[i] == 'a' && s[i-1] == 'b') {
				dp[i] += (i-2 >= 0 ? dp[i-2] : 1);
				dp[i] %= MOD;
			} else if (s[i] == 'b' && s[i-1] == 'a') {
				dp[i] += (i-2 >= 0 ? dp[i-2] : 1);
				dp[i] %= MOD;
			}
			dp[i] = (dp[i]+dp[i-1])%MOD;
		}
		cout << dp[n-1] << endl;
	}
}