#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long, long> pll;

#define pb push_back
#define umap unordered_map
#define f first
#define s second

umap<ll, ll> mp;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t, n;
	cin >> t;
	while(t--){
		cin >> n;
		mp.clear();

		ll *input = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> input[i];
			mp[input[i]]++;
		}

		ll total = 0;
		for(pll x : mp){
			if(x.f != 1){
				if(x.f%(x.f-1) == 0 && mp.find(x.f/(x.f-1)) != mp.end()){
					ll y = x.f/(x.f-1);
					if(x.f == y){
						total += ((x.s)*(x.s-1))/2;
					}
					else{
						total += (x.s)*mp[y];
					}
				}
			}
		}

		cout << total << endl;
	}
}