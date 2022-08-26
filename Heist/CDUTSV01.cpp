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

ll dfs(ll u, vector<ll> *graph, bool *isVisited, ll *gold){
	isVisited[u] = true;

	ll ans = gold[u];
	for(ll v : graph[u]){
		if(!isVisited[v]){
			ll smallAns = dfs(v, graph, isVisited, gold);
			ans = max(ans, smallAns);
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll *gold = new ll[8];
	for(ll i = 0; i < 8; i++){
		cin >> gold[i];
	}

	ll m;
	cin >> m;

	vector<ll> *graph = new vector<ll>[8];

	ll u, v;
	for(ll i = 0; i < m; i++){
		cin >> u >> v;
		graph[u-1].pb(v-1);
		graph[v-1].pb(u-1);
	}

	bool *isVisited = new bool[8];
	for(ll i = 0; i < 8; i++){
		isVisited[i] = false;
	}
	
	ll ans = 0;
	for(ll i = 0; i < 8; i++){
		if(!isVisited[i]){
			ans	+= dfs(i, graph, isVisited, gold);
		}
	}

	cout << ans << endl;
}