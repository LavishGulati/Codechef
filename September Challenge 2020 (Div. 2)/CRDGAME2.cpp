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

#define MAX 1000005

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

ll modInverse(ll x){
	return power(x, MOD-2, MOD);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll *two = new ll[MAX];
	two[0] = 1;
	for(ll i = 1; i < MAX; i++){
		two[i] = (two[i-1]*2)%MOD;
	}

	ll *fact = new ll[MAX];
	fact[0] = 1;
	for(ll i = 1; i < MAX; i++){
		fact[i] = (fact[i-1]*i)%MOD;
	}

	ll *ifact = new ll[MAX];
	for(ll i = 0; i < MAX; i++){
		ifact[i] = modInverse(fact[i]);
	}

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		ll *c = new ll[n];
		ll maxEl = 0, cnt = 0;
		for(ll i = 0; i < n; i++){
			cin >> c[i];
			if(maxEl < c[i]){
				maxEl = c[i];
				cnt = 1;
			}
			else if(maxEl == c[i]){
				cnt++;
			}
		}

		ll ans = two[n];
		ll x = 0;
		if(cnt%2 == 0){
			x = fact[cnt];
			x = (x*ifact[cnt/2])%MOD;
			x = (x*ifact[cnt/2])%MOD;
			x = (x*two[n-cnt])%MOD;
		}
		ans = (ans-x+MOD)%MOD;
		cout << ans << endl;
	}
}