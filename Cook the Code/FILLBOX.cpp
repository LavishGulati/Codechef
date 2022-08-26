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

#define MAX 100005

ll dp[MAX][2];

void solve(ll n, ll k){
	for(ll i = 0; i <= n; i++){
		dp[i][0] = dp[i][1] = 1;
	}

	dp[0][0] = 0;
	dp[0][1] = 1;
	dp[1][0] = k-1;
	dp[1][1] = k-2;

	ll x;

	for(ll i = 2; i <= n; i++){
		dp[i][0] = ((k-1)*dp[i-2][0])%MOD;
		
		x = ((k-1)*(k-2))%MOD;
		x = (x*dp[i-2][1])%MOD;
		dp[i][0] = (dp[i][0]+x)%MOD;

		dp[i][1] = ((k-2)*dp[i-2][0])%MOD;
		
		x = ((k-1)*(dp[i-2][1]))%MOD;
		dp[i][1] = (x+dp[i][1])%MOD;

		x = ((k-2)*(k-2))%MOD;
		x = (x*dp[i-2][1])%MOD;
		dp[i][1] = (x+dp[i][1])%MOD;
	}

	// for(ll i = 0; i <= n; i++){
	// 	cout << dp[i][0] << " ";
	// }
	// cout << endl;

	// for(ll i = 0; i <= n; i++){
	// 	cout << dp[i][1] << " ";
	// }
	// cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, k, p, q;
		cin >> n >> k >> p >> q;

		solve(n-2, k);
		if(p == q){
			cout << dp[n-2][0] << endl;
		}
		else{
			cout << dp[n-2][1] << endl;
		}
	}
}