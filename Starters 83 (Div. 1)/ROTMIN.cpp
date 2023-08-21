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

bool check(string& smallans, int mid, int p, int q) {
	int n = smallans.length();
	vector<pii> up;
	for (int i = 0; i < mid; i++) {
		up.pb(mp('z'-smallans[i]+1, i));
	}

	sort(all(up));
	for (int i = 0; i < mid; i++) {
		if (up[i].f <= p) {
			smallans[up[i].s] = 'a';
			p -= up[i].f;
		} else {
			break;
		}
	}

	for (int i = 0; i < mid; i++) {
		if (smallans[i]-'a' <= q) {
			q -= smallans[i]-'a';
			smallans[i] = 'a';
		} else {
			return false;
		}
	}

	if (mid < n) {
		int cost = min(smallans[mid]-'a', q);
		smallans[mid] -= cost;
		q -= cost;
	}

	for (int i = mid+1; i < n; i++) {
		if ('z'-smallans[i]+1 <= p) {
			p -= 'z'-smallans[i]+1;
			smallans[i] = 'a';
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, p, q;
		cin >> n >> p >> q;

		string s;
		cin >> s;

		int si = 0, ei = n, mid;
		string ans = s, smallans;
		while (si <= ei) {
			mid = (si+ei)/2;
			smallans = s;
			if (check(smallans, mid, p, q)) {
				si = mid+1;
				ans = min(ans, smallans);
			} else {
				ei = mid-1;
			}
		}
		cout << ans << endl;
	}
}