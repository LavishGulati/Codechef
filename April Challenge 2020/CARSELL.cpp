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
		ll n;
		cin >> n;

		ll *p = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> p[i];
		}

		sort(p, p+n);

		ll ans = 0;
		for(ll i = n-1; i >= 0; i--){
			ans += max(p[i]-n+1+i, 0LL);
			ans %= MOD;
		}
		cout << ans << endl;
	}
}