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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;

		ll *a = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}

		ll **dp = new ll *[n];
		for(ll i = 0; i < n; i++){
			dp[i] = new ll[m+1];
			for(ll j = 0; j <= m; j++){
				dp[i][j] = 0;
			}
		}

		dp[0][0] = dp[0][a[0]] = 1;
		
		for(ll i = 1; i < n; i++){
			for(ll j = 0; j <= m; j++){
				dp[i][j] += dp[i-1][j];
				if(a[i]+j <= m){
					dp[i][a[i]+j] += dp[i-1][j];
				}
			}
		}

		cout << dp[n-1][m] << endl;
	}
}