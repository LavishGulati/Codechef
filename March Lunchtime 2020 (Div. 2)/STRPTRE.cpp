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

#define MAX 100009

ll fact[MAX], ifact[MAX], pow2[MAX], cum[MAX];


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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fact[0] = 1;
	for(ll i = 1; i < MAX; i++){
		fact[i] = (i*fact[i-1])%MOD;
	}

	for(ll i = 0; i < MAX; i++){
		ifact[i] = modInverse(fact[i]);
	}

	pow2[0] = 1;
	for(ll i = 1; i < MAX; i++){
		pow2[i] = (2*pow2[i-1])%MOD;
	}

	cum[1] = pow2[1];
	for(ll i = 3; i < MAX; i += 2){
		cum[i] = (pow2[i]+cum[i-2])%MOD;
	}
	for(ll i = 0; i < MAX; i += 2){
		cum[i] = 0;
	}

	ll t;
	cin >> t;
	while(t--){
		ll d;
		cin >> d;

		ll n = (pow2[d+1]-1+MOD)%MOD;
		ll nc2 = (n*((n-1+MOD)%MOD))%MOD;
		// nc2 = (nc2*ifact[2])%MOD;
		// nc2 = (nc2*2)%MOD;

		ll q = modInverse(nc2);

		ll p = 0, x;
		for(ll i = 0; i < d; i++){
			x = pow2[i];
			if((d-i)%2){
				// cout << i << " " << (d-i) << endl;
				x = (x*cum[d-i])%MOD;
			}
			else{
				// cout << i << " " << (d-i-1) << endl;
				x = (x*cum[d-i-1])%MOD;
			}
			p = (p+x)%MOD;
		}

		cout << (p*q)%MOD << endl;
 	}
}