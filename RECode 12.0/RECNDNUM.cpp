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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;

		ll ans;

		if(n == 0){
			ans = ((k-1)*k)%MOD;
		}
		else if(k == 1){
			ans = (n*n)%MOD;
		}
		else if(k%2){
			k--;
			ans = (n*n)%MOD;
			ans = (ans+((k*n)%MOD))%MOD;
			k /= 2;
			ans = (ans+((k*(k+1))%MOD))%MOD;
		}
		else{
			ans = (n*n)%MOD;
			ans = (ans+((k*n)%MOD))%MOD;
			k /= 2;
			k--;
			ans = (ans+((k*(k+1))%MOD))%MOD;
		}
		cout << ans << endl;
	}
}