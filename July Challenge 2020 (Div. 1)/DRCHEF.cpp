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

ll binary_search(ll *a, ll x, ll n){
	ll si = 0;
	ll ei = n-1;
	ll mid, ans = -1;
	while(si <= ei){
		mid = (si+ei)/2;
		if(a[mid] <= x){
			ans = mid;
			si = mid+1;
		}
		else{
			ei = mid-1;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, x;
		cin >> n >> x;

		ll *a = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		sort(a, a+n);

		if(x >= a[n-1]){
			cout << n << endl;
			continue;
		}

		ll id = binary_search(a, x, n);
		if(id >= 0 && x <= 2*a[id]){
			while(id-1 >= 0 && a[id] <= 2*a[id-1]){
				id--;
			}
		}
		else{
			id++;
		}

		ll taken = 0, ans = 0;
		while(id < n-1){
			if(x < a[id]){
				x *= 2;
			}
			else{
				x = 2*a[id];
				id++;
				taken++;
			}
			ans++;
		}

		if(x < a[id]){
			ll y = a[id];
			while(x < y){
				y -= x;
				y = min(2*y, a[id]);
				x *= 2;
				ans++;
			}
			ans += (n-taken);
		}
		else{
			ans += (n-taken);
		}
		cout << ans << endl;
	}
}