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

int lefta[MAX];
int righta[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		int n = s.length();
		for (int i = 0; i < n; i++) {
			lefta[i] = 0;
			righta[i] = 0;
		}

		int num = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				num++;
			}
		}

		lefta[0] = (s[0] == '1' ? 1 : 0);
		for (int i = 1; i < n; i++) {
			lefta[i] = (s[i] == '1' ? 1 : 0);
			lefta[i] += lefta[i-1];
		}

		righta[n-1] = (s[n-1] == '1' ? 1 : 0);
		for (int i = n-2; i >= 0; i--) {
			righta[i] = (s[i] == '1' ? 1 : 0);
			righta[i] += righta[i+1];
		}

		int l = n - num, ans = n;
		for (int i = l; i < n; i++) {
			ans = min(ans, (n - i - 1 - (i+1 < n ? righta[i+1] : 0)) + i - l + 1 - lefta[i-l]);
		}

		ans = min(ans, n-l-(l < n ? righta[l] : 0));
		cout << ans << endl;
	}
}