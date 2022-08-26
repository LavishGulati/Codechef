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

#define MAX 1000000

ll fact[MAX];
ll ifact[MAX];

ll power(ll x, ll n){
	if(n == 0){
		return 1;
	}
	else if(n == 1){
		return x%MOD;
	}

	ll y = power(x, n/2);
	if(n%2){
		return (((y*y)%MOD)*x)%MOD;
	}
	else{
		return (y*y)%MOD;
	}
}

ll modInverse(ll x){
	return power(x, MOD-2);
}

int main(){
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact[0] = 1;
	ifact[0] = modInverse(fact[0]);
	for(ll i = 1; i < MAX; i++){
		fact[i] = (i*fact[i-1])%MOD;
		ifact[i] = modInverse(fact[i]);
	}

	ll t, n, k, ans, subtract, i, x;
	// bool subtract;
	// cin >> t;
	scanf(" %lld", &t);
	while(t--){
		// ll n, k;
		// cin >> n >> k;
		scanf(" %lld %lld", &n, &k);

		ans = subtract = 0;
		// ll ans = 0;
		// ll subtract = false;
		for(i = 1; i <= n; i++){
			x = fact[(n-i)*k + i];
			x = (x*ifact[i])%MOD;
			x = (x*fact[n])%MOD;
			x = (x*ifact[n-i])%MOD;
			x = (x*power(ifact[k], n-i))%MOD;
			if(subtract){
				ans = (ans-x+MOD)%MOD;
			}
			else{
				ans = (ans+x)%MOD;
			}
			subtract ^= 1;
		}
		// cout << ans << endl;
		printf("%lld\n", ans);
	}
}