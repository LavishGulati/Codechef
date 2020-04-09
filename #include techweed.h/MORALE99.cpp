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

	ll n, m, k;
	cin >> n >> k >> m;

	ll *a = new ll[n];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}

	ll contzero = 0;
	for(ll i = 0; i < n; i++){
		if(a[i] == 0){
			contzero++;
		}
		else{
			contzero = 0;
		}
		if(contzero >= k){
			cout << -1 << endl;
			return 0;
		}
	}

	ll sum = 0;
	ll i;
	for(i = 0; i < k; i++){
		sum += a[i];
	}

	i = 0;
	ll ans = 0;
	while(i <= n-k){
		// cout << i << " " << sum << endl;
		if(sum >= m){
			sum -= a[i];
			i++;
			sum += a[i+k-1];
		}
		else{
			ll start = i+k-1;
			while(a[start] == 0){
				start--;
			}


			ll lastnonzero = 0;
			for(ll j = 0; j < k; j++){
				if(a[start+j] != 0){
					lastnonzero = start+j;
				}
			}
			ans++;
			i = lastnonzero+1;
			sum = 0;
			for(ll j = 0; j < k; j++){
				sum += a[i+j];
			}
		}
	}

	cout << ans << endl;
}