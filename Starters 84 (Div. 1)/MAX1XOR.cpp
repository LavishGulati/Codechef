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
		int n;
		cin >> n;

		string s;
		cin >> s;

		int ans = 0, cnt = 1;
		string x = "1";
		for (int i = 1; i < n; i++) {
			x += '0'+((x[i-1]-'0')^(s[i-1]-'0'));
			if (x[i] == '1') {
				cnt++;
			}
		}
		ans = max(ans, cnt);

		cnt = 0;
		x = "0";
		for (int i = 1; i < n; i++) {
			x += '0'+((x[i-1]-'0')^(s[i-1]-'0'));
			if (x[i] == '1') {
				cnt++;
			}
		}
		ans = max(ans, cnt);
		cout << ans << endl;
	}
}