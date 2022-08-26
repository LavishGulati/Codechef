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
		int n, m;
		cin >> n >> m;

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		int *b = new int[m];
		for(int i = 0; i < m; i++){
			cin >> b[i];
		}

		int *dp = new int[n];
		for(int i = 0; i < n; i++){
			dp[i] = -1;
		}

		dp[0] = 0;
		int last = -1;
		for(int i = 0; i < n; i++){
			if(a[i] == 1){
				last = i;
			}
			if(last != -1){
				dp[i] = i-last;
			}
		}

		last = n;
		for(int i = n-1; i >= 0; i--){
			if(a[i] == 2){
				last = i;
			}
			if(last != n){
				if(dp[i] == -1){
					dp[i] = last-i;
				}
				else{
					dp[i] = min(dp[i], last-i);
				}
			}
		}

		// for(int i = 0; i < n; i++){
		// 	cout << dp[i] << " ";
		// }
		// cout << endl;

		for(int i = 0; i < m; i++){
			cout << dp[b[i]-1] << " ";
		}
		cout << endl;
	}
}