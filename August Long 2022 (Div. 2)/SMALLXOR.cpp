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
// #define mp make_pair
#define all(x) x.begin(), x.end()

#define MAX 100005
#define MOD 1000000007

map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		mp.clear();

		int n, x, y, val;
		cin >> n >> x >> y;

		for (int i = 0; i < n; i++) {
			cin >> val;
			mp[val]++;
		}

		while (y > 0) {
			auto it = mp.begin();
			if ((it->f ^ x) < it->f) {
				break;
			}
			int remove = min(y, it->s);
			mp[(it->f ^ x)] += remove;
			mp[it->f] -= remove;
			if (mp[it->f] == 0) {
				mp.erase(it);
			}
			y -= remove;
		}

		y %= 2;
		if (y == 1) {
			auto it = mp.begin();
			mp[it->f] -= 1;
			mp[(it->f ^ x)] += 1;
		}

		for (auto val : mp) {
			for (int i = 0; i < val.s; i++) {
				cout << val.f << " ";
			}
		}
		cout << endl;
	}
}