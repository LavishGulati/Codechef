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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	string *grid = new string[n];
	for(int i = 0; i < n; i++){
		cin >> grid[i];
	}

	int **dp = new int *[n];
	for(int i = 0; i < n; i++){
		dp[i] = new int[m];
		for(int j = 0; j < m; j++){
			dp[i][j] = 0;
		}
	}

	int q, x1, y1, x2, y2;
	cin >> q;
	while(q--){
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;

		dp[x2][y2]++;
		if(x1-1 >= 0 && y1-1 >= 0){
			dp[x1-1][y1-1]++;
		}
		if(y1-1 >= 0){
			dp[x2][y1-1]++;
		}
		if(x1-1 >= 0){
			dp[x1-1][y2]++;
		}
	}

	for(int i = n-1; i >= 0; i--){
		for(int j = m-2; j >= 0; j--){
			dp[i][j] += dp[i][j+1];
		}
	}

	for(int j = m-1; j >= 0; j--){
		for(int i = n-2; i >= 0; i--){
			dp[i][j] += dp[i+1][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(dp[i][j]%2){
				cout << ((grid[i][j]-'0')^1);
			}
			else{
				cout << grid[i][j];
			}
		}
		cout << endl;
	}
}