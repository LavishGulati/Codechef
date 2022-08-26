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

#define MAX 100005

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll power[MAX];
	power[0] = 1;
	for(ll i = 1; i < MAX; i++){
		power[i] = (2*power[i-1])%MOD;
	}

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		map<ll, ll> mymap;
		ll x, sum = 0;
		for(ll i = 0; i < n; i++){
			cin >> x;
			mymap[x]++;
		}

		ll help = 0, help2 = 1, y, ans = 0;
		for(ll i = 1; i <= n; i++){
			x = (power[n-mymap[i]-help]*i)%MOD;
			x = (x*help2)%MOD;
			ans = (ans+x)%MOD; 
			y = (power[mymap[i]]-1+MOD)%MOD;
			help2 = (help2*y)%MOD;
			help += mymap[i];
		}
		cout << ans << endl;
	}
}