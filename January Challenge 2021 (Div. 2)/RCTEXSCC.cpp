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

#define MOD 998244353

#define MAX 100005

ll power(ll x, ll n, ll mod){
	if(n == 0){
		return 1%mod;
	}
	else if(n == 1){
		return x%mod;
	}

	ll y = power(x, n/2, mod);
	if(n%2){
		return (((y*y)%mod)*x)%mod;
	}
	else{
		return (y*y)%mod;
	}
}

ll modInverse(ll x, ll mod){
	return power(x, mod-2, mod);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll m, n, k;
	cin >> m >> n >> k;

	ll *fac = new ll[MAX];
	fac[0] = fac[1] = 1;
	for(ll i = 2; i < MAX; i++){
		fac[i] = (i*fac[i-1])%MOD;
	}

	ll *ifac = new ll[MAX];
	for(ll i = 0; i < MAX; i++){
		ifac[i] = modInverse(fac[i], MOD);
	}

	ll *powk = new ll[MAX];
	powk[0] = 1;
	for(ll i = 1; i < MAX; i++){
		powk[i] = ((k-1)*powk[i-1])%MOD;
	}

	if(m == 1){
		ll *dp = new ll[n+1];
		dp[0] = 0;
		for(ll i = 1; i <= n; i++){
			if(i > k){
				break;
			}
			dp[i] = (k*powk[i-1])%MOD;
			dp[i] = (dp[i]*fac[n-1])%MOD;
			dp[i] = (dp[i]*ifac[i-1])%MOD;
			dp[i] = (dp[i]*ifac[n-i])%MOD;
		}

		ll total = 0;
		for(ll i = 0; i <= n; i++){
			total = (total+dp[i])%MOD;
		}

		ll num = 0;
		for(ll i = 0; i <= n; i++){
			num = (num+(i*dp[i])%MOD)%MOD;
		}
		ll ans = (num*modInverse(total, MOD))%MOD;
		cout << ans << endl;
	}
}