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

#define MAX 100009

bool visited[MAX];
int disc[MAX], low[MAX], parent[MAX];
map<pii, int> paveid;
int answer = 0;
set<int> counted;

void dfs(int u, vector<int> *graph){
	static int time = 0;
	visited[u] = true;

	disc[u] = low[u] = ++time;
	for(int v : graph[u]){
		if(!visited[v]){
			parent[v] = u;
			dfs(v, graph);

			low[u] = min(low[u], low[v]);

			if(low[v] > disc[u]){
				auto it =  counted.find(paveid[mp(u, v)]);
				if(it != counted.end()){
					answer++;
					counted.erase(it);
				}
			}
		}
		else if(v != parent[u]){
			low[u] = min(low[u], disc[v]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	// umap<int, pii> mymap;

	vector<int> *graph = new vector<int>[n];
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		graph[u-1].pb(v-1);
		graph[v-1].pb(u-1);
		// mymap[i] = mp(u-1, v-1);
		paveid[mp(u-1, v-1)] = i;
		paveid[mp(v-1, u-1)] = i;
	}

	int x;
	cin >> x;

	// int *pave = new int[x];
	int y;
	for(int i = 0; i < x; i++){
		// cin >> pave[i];
		cin >> y;
		// counted.insert(pave[i]-1);
		counted.insert(y-1);
	}

	for(int i = 0; i < MAX; i++){
		parent[i] = -1;
		visited[i] = false;
	}

	for(int i = 0; i < n; i++){
		if(!visited[i]){
			dfs(i, graph);
		}
	}
	cout << answer << endl;
}