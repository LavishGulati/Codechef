#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

#define MAX 100002

ll powerMod(ll x, ll n, ll mod){
	if(x == 0){
		return 0;
	}
	else if(x == 1){
		return 1;
	}

	if(n == 0){
		return 1%mod;
	}
	else if(n == 1){
		return x%mod;
	}

	ll y = powerMod(x, n/2, mod);
	if(n%2){
		ll ans = (y*y)%mod;
		ans = (ans*x)%mod;
		return ans;
	}
	else{
		ll ans = (y*y)%mod;
		return ans;
	}
}

ll modInverse(ll x){
	return powerMod(x, MOD-2, MOD);
}

ll fact[MAX];
ll power[MAX];
ll ModInverse[MAX];

int main(){
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	// ll *fact = new ll[MAX];
	fact[0] = 1;
	for(ll i = 1; i < MAX; i++){
		fact[i] = (i*fact[i-1])%MOD;
	}

	umap<ll, bool> done;
	umap<ll, ll> myMap;

	// ll *power = new ll[MAX];
	power[0] = 1;
	for(ll i = 1; i < MAX; i++){
		power[i] = (2*power[i-1])%MOD;
	}

	// ll *ModInverse = new ll[MAX];
	ModInverse[1] = 1;
	for(ll i = 2; i < MAX; i++){
		ModInverse[i] = modInverse(fact[i]);
	}

	bool possible;
	ll t, n, sum, x, ans, totalPairs, i;
	// cin >> t;
	scanf("%lld", &t);

	while(t--){
		// cin >> n;
		scanf("%lld", &n);

		myMap.clear();
		done.clear();
		possible = true;

		sum = 0;
		for(i = 0; i < 2*n; i++){
			// cin >> x;
			scanf("%lld", &x);
			myMap[x]++;
			sum += x;
		}

		if(sum%(n+1) != 0){
			possible = false;
		}

		sum /= n+1;

		if(myMap[sum] < 2){
			possible = false;
		}

		myMap[sum] -= 2;
		if(myMap[sum] == 0){
			myMap.erase(sum);
		}

		for(pll it : myMap){
			if(it.f == sum-it.f){
				if(it.s%2 != 0){
					possible = false;
					break;
				}
			}
			else{
				if(myMap[it.f] != myMap[sum-it.f]){
					possible = false;
					break;
				}
			}
		}

		if(!possible){
			// cout << 0 << endl;
			printf("0\n");
		}
		else{
			ans = 1;
			totalPairs = 0;
			for(pll it : myMap){
				if(done.find(it.f) == done.end()){
					if(it.f != sum-it.f){
						totalPairs += it.s;
						ans = (ans*power[it.s])%MOD;
						ans = (ans*ModInverse[it.s])%MOD;
						// ans = (ans*modInverse(fact[it.s]))%MOD;
					}
					else{
						totalPairs += it.s/2;
						// ans = (ans*modInverse(fact[it.s/2]))%MOD;
						ans = (ans*ModInverse[it.s/2])%MOD;
					}

					done[it.f] = true;
					done[sum-it.f] = true;
				}
			}

			ans = (ans*fact[totalPairs])%MOD;
			// cout << ans << "\n";
			printf("%lld\n", ans);
		}
	}
}