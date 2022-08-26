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

	ll m ,n, k;
	cin >> m >> n >> k;

	ll ans, x, kinv = modInverse(k, MOD);
	ans = (n*m)%MOD;
	x = (n*(m-1))%MOD;
	x = (x*kinv)%MOD;
	ans = (ans-x+MOD)%MOD;
	x = (m*(n-1))%MOD;
	x = (x*kinv)%MOD;
	ans = (ans-x+MOD)%MOD;
	if(m == 2){
		x = ((n-1)*kinv)%MOD;
		x = (x*kinv)%MOD;
		x = (x*kinv)%MOD;
		ans = (ans+x)%MOD;
	}
	cout << ans << endl;
}