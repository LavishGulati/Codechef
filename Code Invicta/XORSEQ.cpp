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

set<ll> startset;
map<ll, ll> mymap;

ll intervalContaining(ll x){
	ll i = 1;
	ll j = x;
	ll ans = -1;
	while(i <= j){
		ll mid = (i+j)/2;
		auto it = startset.lower_bound(mid);
		if(it != startset.end() && *it >= ans && *it <= x){
			ans = *it;
			i = mid+1;
		}
		else{
			j = mid-1;
		}
	}
	return ans;
}

set<ll>::iterator emptyInterval(ll x){
	return startset.lower_bound(x);
}

ll xorarr(ll n){
	if(n%4 == 0){
		return n;
	}
	else if(n%4 == 1){
		return 1;
	}
	else if(n%4 == 2){
		return n+1;
	}
	else{
		return 0;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	// ll *xorarr = new ll[n+1];
	// xorarr[0] = 0;
	// xorarr[1] = 1;
	// for(ll i = 2; i <= n; i++){
	// 	xorarr[i] = xorarr[i-1]^i;
	// }

	ll q;
	cin >> q;

	mymap[1] = n;
	startset.insert(1);
	set<ll> inserted;

	while(q--){
		ll c, x;
		cin >> c >> x;

		if(c == 1){
			if(inserted.find(x) == inserted.end()){
				ll a = intervalContaining(x);
				auto it2 = mymap.find(a);
				ll b = it2->s;
				startset.erase(startset.find(a));
				mymap.erase(it2);

				if(x-1 >= a){
					// cout << "INS: " << a << " " << x-1 << endl;
					startset.insert(a);
					mymap[a] = x-1;
				}
				if(b >= x+1){
					// cout << "INS: " << x+1 << " " << b << endl;
					startset.insert(x+1);
					mymap[x+1] = b;
				}
				inserted.insert(x);
			}
		}
		else{
			ll a = intervalContaining(x);
			if(a != -1 && mymap[a] >= x){
				// cout << "OUT: " << mymap[a] << " " << x - 1 << endl;
				ll ans = (xorarr(mymap[a]))^(xorarr(x - 1)); 
				cout << ans << endl;
			}
			else{
				set<ll>::iterator it = emptyInterval(x);
				// cout << "OUT: " << mymap[*it] << " " << *it - 1 << endl;
				ll ans = (xorarr(mymap[*it]))^(xorarr(*it - 1)); 
				cout << ans << endl;
			}
		}
	}
}