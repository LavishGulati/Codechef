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

int a[MAX];

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

		sort(a, a+n);
		int z = a[n-1] + a[n-2];
		int i = 0, j = n-1, sum;
		bool poss = true, chance = true;
		while (i < j) {
			sum = a[i] + a[j];
			if (sum >= z) {
				poss = false;
				break;
			}
			if (chance) {
				j--;
			} else {
				i++;
			}
			chance ^= 1;
		}
		cout << (poss ? "YES" : "NO") << endl;
	}
}