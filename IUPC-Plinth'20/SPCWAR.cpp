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

pair<int, int> bfs1(vector<int> *graph, int source, bool *isVisited, bool erase){
	
	map<int, int> m;

	vector<int> output;
	vector<int> dis;
	queue<int> q;
	q.push(source);
	dis.pb(0);
	isVisited[source] = true;
	m[source] = 0;
	output.pb(source);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int v : graph[u]){
			if(!isVisited[v]){
				isVisited[v] = true;
				m[v] = output.size();
				output.pb(v);
				dis.pb(dis[m[u]]+1);
				q.push(v);
			}
		}
	}

	int maxDis = 0;
	int id;
	for(int i = 0; i < dis.size(); i++){
		if(dis[i] > maxDis){
			// cout << output[i] << " " << dis[i] << endl;
			maxDis = dis[i];
			id = output[i];
		}
	}

	if(erase){
		for(int i = 0; i < output.size(); i++){
			isVisited[output[i]] = false;
		}
	}

	return mp(id, maxDis);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> *graph = new vector<int>[n];
	
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		graph[u-1].pb(v-1);
		graph[v-1].pb(u-1);
	}

	bool *isVisited = new bool[n];
	for(int i = 0; i < n; i++){
		isVisited[i] = false;
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(!isVisited[i]){
			pii t = bfs1(graph, i, isVisited, true);
			// cout << t.first << " " << t.second << endl;
			pii t2 = bfs1(graph, t.first, isVisited, false);
			// cout << t2.first << " " << t2.second << endl;
			if(t2.second%2 == 0){
				ans	= max(ans, t2.second/2);
			}
			else{
				ans	= max(ans, t2.second/2 + 1);
			}
		}
	}

	cout << ans << endl;
}