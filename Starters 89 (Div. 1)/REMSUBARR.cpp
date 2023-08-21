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

int a[MAX], lft[MAX], rght[MAX], rev[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			lft[i] = rght[i] = a[i];
			rev[a[i]] = i;
		}

		if (a[0] == 1 || a[n-1] == 1) {
			cout << n-1 << endl;
			continue;
		}

		for (int i = 1; i < n; i++) {
			lft[i] = max(lft[i], lft[i-1]);
		}
		for (int i = n-2; i >= 0; i--) {
			rght[i] = max(rght[i], rght[i+1]);
		}

		int find = 1, maxel = 1, si = 0, ei = n-1;
		while (n-(ei-si+1) != maxel) {
			int id = rev[find++];
			if (id < si || id > ei) {
				continue;
			}

			if (lft[id] < rght[id]) {
				maxel = max(maxel, lft[id]);
				si = id+1;
			} else {
				maxel = max(maxel, rght[id]);
				ei = id-1;
			}
		}
		cout << ei-si+1 << endl;
	}
}