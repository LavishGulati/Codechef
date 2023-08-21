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

#define MAX 30005
#define MAXA 1000005
#define MOD 1000000007

int a[MAX];
vector<int> graph[MAX];
ll sieve[MAXA], ans[MAX];

ll power(ll x, ll n) {
	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x%MOD;
	}

	ll y = power(x, n/2);
	if (n%2) {
		return (x*((y*y)%MOD))%MOD;
	} else {
		return (y*y)%MOD;
	}
}

ll modInverse(ll x) {
	return power(x, MOD-2);
}

struct Node {
	unordered_map<int, int> freq;
	ll smallans;

	Node () {
		smallans = 1;
	}
};

Node dfs(int u, int par) {
	Node node;
	while (a[u] > 1) {
		node.freq[sieve[a[u]]]++;
		a[u] /= sieve[a[u]];
	}
	for (const auto& [_, fr] : node.freq) {
		node.smallans = (node.smallans*(fr+1))%MOD;
	}

	for (int v : graph[u]) {
		if (v != par) {
			Node&& smallnode = dfs(v, u);
			if (node.freq.size() < smallnode.freq.size()) {
				swap(node, smallnode);
			}

			for (const auto& [x, fr2] : smallnode.freq) {
				int fr1 = node.freq[x];
				node.smallans = (node.smallans*(fr1+fr2+1))%MOD;
				node.smallans = (node.smallans*modInverse(fr1+1))%MOD;
				node.freq[x] += fr2;
			}
		}
	}
	ans[u] = node.smallans;
	return node;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < MAXA; i++) {
		sieve[i] = -1;
	}
	sieve[1] = 1;
	for (ll i = 2; i*i < MAXA; i++) {
		if (sieve[i] == -1) {
			sieve[i] = i;
			for (ll p = i*i; p < MAXA; p += i) {
				if (sieve[p] == -1) {
					sieve[p] = i;
				}
			}
		}
	}
	for (int i = 2; i < MAXA; i++) {
		if (sieve[i] == -1) {
			sieve[i] = i;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			graph[i].clear();
		}

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		int u, v;
		for (int i = 0; i < n-1; i++) {
			cin >> u >> v;
			graph[u-1].pb(v-1);
			graph[v-1].pb(u-1);
		}

		dfs(0, -1);
		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}