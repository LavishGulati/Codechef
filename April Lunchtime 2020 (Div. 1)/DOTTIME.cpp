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

#define MOD 998,244,353

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, m, q;
		cin >> n >> m >> q;

		ll *a = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			a[i] %= MOD;
		}

		ll *cum = new ll[n];
		cum[0] = a[0];
		for(ll i = 1; i < n; i++){
			cum[i] = (cum[i-1]+a[i])%MOD;
		}

		ll *cum2 = new ll[n], ll x;
		cum2[0] = (2*a[0])%MOD;
		for(ll i = 1; i < n; i++){
			if(i > m){

			}
			else{
				x = (2*(i+1)*a[i])%MOD;
				
			}
		}

		ll sum = 0, u, y, v;
		for(ll i = 0; i < n; i++){
			u = min(i+1, m);

			x = (a[i]*a[i])%MOD;
			x = (u*x)%MOD;
			sum = (sum+x)%MOD;

			x = (2*u)%MOD;
			x = (x*a[i])%MOD;
			x = (x*(cum[n-1]-cum[i]))%MOD;
			sum = (sum+x)%MOD;
		}

		ll pos, val;
		while(q--){
			cin >> pos >> val;
			pos--;

			u = min(pos+1, m);

			x = (a[pos]*a[pos])%MOD;
			x = (u*x)%MOD;
			sum = (sum-x+MOD)%MOD;

			x = (val*val)%MOD;
			x = (u*x)%MOD;
			sum = (sum+x)%MOD;

			x = (2*u)%MOD;
			x = (x*a[pos])%MOD;
			x = (x*(cum[n-1]-cum[pos]))%MOD;
			sum = (sum-x+MOD)%MOD;

			x = (2*u)%MOD;
			x = (x*val)%MOD;
			x = (x*(cum[n-1]-cum[pos]))%MOD;
			sum = (sum+x)%MOD;

			if(pos <= m){
				x = 
			}
		}
	}
}