#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
typedef pair<long long, pair<long long, long long>> tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int **grid = new int *[n];
		for(int i = 0; i < n; i++){
			grid[i] = new int[n];
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}

		bool row;
		if(grid[n-1][0] == n){
			row = true;
		}
		else{
			row = false;
		}

		int ans;
		if(row){
			ans = 1;
		}
		else{
			ans = 0;
		}

		for(int i = n-2; i >= 0; i--){
			if(row && grid[i][0] != i+1){
				ans++;
				row = false;
			}
			else if(!row && grid[0][i] != i+1){
				ans++;
				row = true;
			}
		}

		cout << ans << endl;
	}
}