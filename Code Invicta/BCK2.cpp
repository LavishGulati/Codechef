#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pq priority_queue

#define MOD 1000000007

ll ans = 0;
map<pll, ll> mymap;


ll dfs(ll u, vector<ll> *graph, bool *isVisited, ll n){
	ll child = 0;
	isVisited[u] = true;
	for(ll v : graph[u]){
		if(!isVisited[v]){
			ll x = dfs(v, graph, isVisited, n);
			ans += 2*min(x, n-x)*mymap[mp(u, v)];
			child += x;
		}
	}
	return child+1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	vector<ll> *graph = new vector<ll>[n];
	ll u, v, w;
	for(ll i = 0; i < n-1; i++){
		cin >> u >> v >> w;
		graph[u-1].pb(v-1);
		graph[v-1].pb(u-1);
		mymap[mp(u-1, v-1)] = w;
		mymap[mp(v-1, u-1)] = w;
	}

	bool *isVisited = new bool[n];
	dfs(0, graph, isVisited, n);
	cout << ans << endl;
}