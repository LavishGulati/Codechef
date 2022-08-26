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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;

		ll **grid = new ll *[n];
		for(ll i = 0; i < n; i++){
			grid[i] = new ll[m];
			for(ll j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}

		ll ans = 0;
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < m; j++){
				ll k = 0;
				while(1){
					if(i+k+1 < n && i-k-1 >= 0 && j+k+1 < m && j-k-1 >= 0 && grid[i+k+1][j] == grid[i-k-1][j] && grid[i][j+k+1] == grid[i][j-k-1]){
						k++;
					}
					else{
						break;
					}
				}

				ans += k+1;
			}
		}

		cout << ans << endl;
	}
}