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

int n, m, k;

ll solve(int **graph, int i, int j){
	int si = 0;
	int ei = m;

	int answer = ei;
	while(si <= ei){
		int mid = (si+ei)/2;

		int x = graph[min(i+mid, n-1)][min(j+mid, m-1)];
		if(i-mid-1 >= 0){
			x -= graph[max(0, i-mid-1)][min(j+mid, m-1)];
		}
		if(j-mid-1 >= 0){
			x -= graph[min(i+mid, n-1)][max(0, j-mid-1)];
		}
		if(i-mid-1 >= 0 && j-mid-1 >= 0){
			x += graph[i-mid-1][j-mid-1];
		}

		if(x >= k){
			ei = mid-1;
			answer = mid;
		}
		else{
			si = mid+1;
		}
	}

	return ll(answer+1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		ll c;
		cin >> n >> m >> c >> k;

		int total = 0;

		char **grid = new char *[n];
		for(int i = 0; i < n; i++){
			grid[i] = new char[m];
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}

		int **help = new int *[n];
		for(int i = 0; i < n; i++){
			help[i] = new int[m];
			for(int j = 0; j < m; j++){
				if(grid[i][j] == '#'){
					help[i][j] = 1;
					total++;
				}
				else{
					help[i][j] = 0;
				}
			}
		}

		if(k > total){
			cout << -1 << endl;
			continue;
		}

		for(int i = 0; i < n; i++){
			for(int j = 1; j < m; j++){
				help[i][j] += help[i][j-1];
			}
		}

		for(int j = 0; j < m; j++){
			for(int i = 1; i < n; i++){
				help[i][j] += help[i-1][j];
			}
		}

		ll ans = LLONG_MAX;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				ll l = solve(help, i, j);
				// cout << i << " " << j << " " << l << endl;
				ans = min(ans, l*c);
			}
		}

		cout << ans << endl;
	}
}