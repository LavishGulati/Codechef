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

int ans[2];
vector<int> graph[MAX];
bool vis[MAX];
int w[MAX];

int dfs(int u, int d){
	vis[u] = true;
	int ans = 1, d1;
	for(int v : graph[u]){
		d1 = __builtin_popcount(w[v])%2;
		if(!vis[v] && d1 == d){
			ans += dfs(v, d);
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;

		for(int i = 0; i < n; i++){
			cin >> w[i];
			graph[i].clear();
		}

		int u, v;
		for(int i = 0; i < m; i++){
			cin >> u >> v;
			graph[u-1].pb(v-1);
			graph[v-1].pb(u-1);
		}

		ans[0] = ans[1] = 0;
		for(int i = 0; i < n; i++){
			vis[i] = false;
		}
		for(int i = 0; i < n; i++){
			if(!vis[i]){
				int d = __builtin_popcount(w[i])%2;
				int num = dfs(i, d);
				ans[d] = max(ans[d], num);
			}
		}

		int q;
		cin >> q;
		int d, k, d1;
		while(q--){
			cin >> d >> k;
			d %= 2;
			d1 = __builtin_popcount(k)%2;
			d ^= d1;
			cout << ans[d] << endl;
		}		
	}
}