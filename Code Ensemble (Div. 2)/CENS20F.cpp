#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

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

#define MAX 200005

ll visited[MAX][2];
ll values[MAX], parent[MAX];
vector<ll> tree[MAX];

void findParents(ll u, ll par){
	parent[u] = par;
	for(ll v : tree[u]){
		if(v != par){
			findParents(v, u);
		}
	}
}

void dfs(ll u, ll parity, ll src, ll par){
	if(u != src && parity == 0){
		values[src] += values[u];
		values[u] = 0;
	}

	if(!visited[u][parity]){
		for(ll v : tree[u]){
			if(v != par){
				dfs(v, parity^1, src, u);
			}
		}

		visited[u][parity] = 1;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, i, j, x, u, v, q;
		cin >> n >> q;

		for(i = 0; i < n; i++){
			visited[i][0] = 0;
			visited[i][1] = 0;
			tree[i].clear();
		}

		for(i = 0; i < n; i++){
			cin >> values[i];
		}

		for(i = 0; i < n-1; i++){
			cin >> u >> v;
			u--; v--;
			tree[u].pb(v);
			tree[v].pb(u);
		}

		findParents(0, -1);
		while(q--){
			cin >> x; x--;
			if(visited[x][0]){
				continue;
			}
			dfs(x, 0, x, parent[x]);
			visited[x][0] = 1;
		}

		for(i = 0; i < n; i++){
			cout << values[i] << " ";
		}
		cout << endl;
	}
}