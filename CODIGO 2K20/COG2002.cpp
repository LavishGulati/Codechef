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

	ll t, n;
	cin >> t;
	while(t--){
		cin >> n;
		ll *x = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> x[i];
		}

		ll ans = x[0]+x[1]+x[2];
		for(ll i = 1; i < n; i++){
			ans = max(ans, x[i]+x[(i+1)%n]+x[(i+2)%n]);
		}
		cout << ans << endl;
	}
}