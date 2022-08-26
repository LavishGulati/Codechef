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

	ll t;
	cin >> t;
	while(t--){
		ll n, x;
		cin >> n >> x;

		ll *a = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}

		ll ans = 1;
		if(x > 1){
			ans = (ans*power(a[0], n*(n+1), MOD))%MOD;
			ans = (ans*power(modInverse(x-1, MOD), n*(n+1), MOD))%MOD;
			ll temp = x;
			for(ll i = 0; i < n; i++){
				ans = (ans*power(temp-1, 2*(n-i), MOD))%MOD;
				temp = (temp*x)%MOD;
			}
		}
		else if(x == 1){
			ans = (ans*power(a[0], n*(n+1), MOD))%MOD;
			for(ll i = 0; i < n; i++){
				ans = (ans*power(i+1, 2*(n-i), MOD))%MOD;
			}
		}
		cout << ans << endl;
	}
}