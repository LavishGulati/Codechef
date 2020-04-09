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

#define MAX 10001

ll *sieve(ll n){ 

    ll *prime = new ll[n+1]; 
    memset(prime, 0, sizeof(prime)); 
  
    for (ll p = 2; p <= n; p++){ 
        if (!prime[p]){ 
        	prime[p] = p;
            for (ll i = p*p; i <= n; i += p){
            	if(!prime[i]){
	            	prime[i] = p; 
            	}
            }
        } 
    } 

    return prime; 
}

map<ll, ll> lcm;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll *primes = sieve(MAX);

	// for(ll i = 0; i < MAX; i++){
	// 	cout << primes[i] << " ";
	// }
	// cout << endl;

	ll t;
	cin >> t;
	while(t--){
		lcm.clear();

		ll n, m;
		cin >> n >> m;

		ll x, c, p;
		for(ll i = 0; i < n; i++){
			cin >> x;

			while(x > 1){
				c = 0;
				p = primes[x];
				while(x%p == 0){
					c++;
					x /= p;
				}

				if(lcm.find(p) == lcm.end()){
					lcm[p] = c;
				}
				else{
					lcm[p] = max(lcm[p], c);
				}
			}
		}

		ll ans = 1, output = 1;
		ll y;
		for(ll i = 2; i <= m; i++){
			x = i;
			y = 1;
			while(x > 1){
				c = 0;
				p = primes[x];
				while(x%p == 0){
					x /= p;
					c++;
				}

				if(lcm.find(p) != lcm.end()){
					y *= pow(p, min(lcm[p], c));
				}
			}

			// cout << i << " " << y << endl;

			if(i/y > ans){
				ans = i/y;
				output = i;
			}
		}
		cout << output << endl;
	}
}