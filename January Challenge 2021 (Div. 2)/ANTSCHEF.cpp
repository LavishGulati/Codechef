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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		vector<vector<ll>> X;
		vector<ll> v;
		ll m, x;
		for(ll i = 0; i < n; i++){
			cin >> m;
			v.clear();
			for(ll j = 0; j < m; j++){
				cin >> x;
				v.pb(x);
			}
			X.pb(v);
		}

		ll ans = 0, pos, neg;
		for(ll i = 0; i < n; i++){
			pos = 0; neg = 0;
			for(ll x : X[i]){
				if(x < 0){
					neg++;
				}
				else if(x > 0){
					pos++;
				}
			}
			ans += pos*neg;
		}
		cout << ans << endl;
	}
}