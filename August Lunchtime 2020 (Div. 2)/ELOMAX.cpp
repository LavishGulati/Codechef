#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;

		pii *r = new pii[n];
		for(int i = 0; i < n; i++){
			cin >> r[i].f;
			r[i].s = i;
		}

		int **diff = new int *[n];
		for(int i = 0; i < n; i++){
			diff[i] = new int[m];
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> diff[i][j];
			}
		}

		pii *peakRate = new pii[n];
		pii *peakRank = new pii[n];
		for(int i = 0; i < n; i++){
			peakRank[i] = {INT_MAX, -1};
			peakRate[i] = {INT_MIN, -1};
		}

		int id, rank;
		for(int k = 0; k < m; k++){
			for(int i = 0; i < n; i++){
				id = r[i].s;
				r[i].f += diff[id][k];
			}

			sort(r, r+n);
			for(int i = n-1; i >= 0; i--){
				rank = n-i;
				int j = i;
				while(j >= 0 && r[j].f == r[i].f){
					j--;
				}
				j++;
				while(j <= i){
					id = r[j].s;
					if(peakRank[id].f > rank){
						peakRank[id] = {rank, k};
					}
					if(peakRate[id].f < r[j].f){
						peakRate[id] = {r[j].f, k};
					}
					j++;
				}
			}
		}

		// for(int i = 0; i < n; i++){
		// 	cout << peakRate[i].f << " " << peakRate[i].s << ", " << peakRank[i].f << " " << peakRank[i].s << endl;
		// }

		int ans = 0;
		for(int i = 0; i < n; i++){
			if(peakRate[i].s != peakRank[i].s){
				ans++;
			}
		}
		cout << ans << endl;
	}
}