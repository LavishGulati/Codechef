#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		int n, m, k, a, b;
		cin >> n >> m >> k >> a >> b;

		mp<pll, ll> weight;
		vector<ll> *graph = new vector<ll>[n];

		ll u, v, w;
		for(ll i = 0; i < m; i++){
			cin >> u >> v >> w;
			graph[u-1].pb(v-1);
			weight[mp(u-1, v-1)] = w;
		}

		mp<pll, ll> weightPossible;
		for(ll i = 0; i < k; i++){
			cin >> u >> v >> w;
			weightPossible[mp(u, v)] = w;
		}

		
	}
}