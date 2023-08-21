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
		int n, q, x;
		cin >> n >> q;

		ll sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> x;
			sum += x;
		}

		int l, r;
		for(int i = 0; i < q; i++) {
			cin >> l >> r;
			if ((l-r+1)%2) {
				sum++;
			}
		}
		cout << sum << endl;
	}
}