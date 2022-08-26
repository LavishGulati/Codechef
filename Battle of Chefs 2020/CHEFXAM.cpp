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
		ll k, n;
		cin >> k >> n;

		pll *a = new pll[k];
		for(ll i = 0; i < k; i++){
			cin >> a[i].f >> a[i].s;
		}

		ll **dp = new ll *[k];
		for(ll i = 0; i < k; i++){
			dp[i] = new ll[n+1];
			for(ll j = 0; j <= n; j++){
				dp[i][j] = 0;
			}
		}

		for(ll j = a[0].f; j <= min(a[0].s, n); j++){
			dp[0][j] = 1;
		}

		for(ll i = 1; i < k; i++){
			ll cnt = 0, sum = 0, remove = 0;
			for(ll j = a[i].f; j <= n; j++){
				if(j <= a[i].s){
					sum = (sum+dp[i-1][j-a[i].f])%MOD;
					dp[i][j] = (dp[i][j]+sum)%MOD;
				}
				else{
					sum = (sum-dp[i-1][remove]+MOD)%MOD;
					sum = (sum+dp[i-1][j-a[i].f])%MOD;
					dp[i][j] = (dp[i][j]+sum)%MOD;
					remove++;
				}
			}
		}

		// for(ll i = 0; i < k; i++){
		// 	for(ll j = 0; j <= n; j++){
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		cout << dp[k-1][n] << endl;
	}
}