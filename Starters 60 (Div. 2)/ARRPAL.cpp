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

#define MAX 300005
#define MOD 1000000007

int a[MAX], diff[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			diff[i] = -1;
		}

		bool poss = true;
		int i = 0, j = n-1;
		while (i < j) {
			if (a[i] > a[j]) {
				poss = false;
				break;
			}
			diff[i] = a[j]-a[i];
			i++; j--;
		}

		if (!poss) {
			cout << -1 << endl;
			continue;
		}

		for (int i = 1; i < n && diff[i] != -1; i++) {
			if (diff[i-1] < diff[i]) {
				poss = false;
				break;
			}
		}

		if (!poss) {
			cout << -1 << endl;
			continue;
		}

		ll ans = 0;
		i = 0;
		while (i < n && diff[i] != -1) {
			if (diff[i+1] != -1) {
				ans += diff[i]-diff[i+1];
			}
			i++;
		}
		ans += diff[i-1];
		cout << ans << endl;
	}
}