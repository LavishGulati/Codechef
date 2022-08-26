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

bool possible(ll si, ll ei, ll *h, ll k){
	ll total = 0;
	for(ll i = si; i <= ei; i++){
		total += h[i];
	}

	if(total < 2*k){
		return false;
	}

	bool **dp = new bool *[ei-si+1];
	for(ll i = 0; i < ei-si+1; i++){
		dp[i] = new bool[k];
		for(ll j = 0; j < k; j++){
			dp[i][j] = false;
		}
	}

	dp[0][0] = true;
	if(h[si] >= k && total-h[si] >= k){
		return true;
	}
	dp[0][h[si]] = true;

	for(ll i = si; i < ei; i++){
		for(ll j = 0; j < k; j++){
			if(dp[i-si][j]){
				dp[i-si+1][j] = true;
				if(j+h[i+1] >= k && total-j-h[i+1] >= k){
					return true;
				}
				else if(j+h[i+1] < k){
					dp[i-si+1][j+h[i+1]] = true;
				}
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;

		ll *h = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> h[i];
		}
		sort(h, h+n);

		ll si = 2, ei = n, mid, ans = -1;
		while(si <= ei){
			mid = (si+ei)/2;
			if(possible(n-mid, n-1, h, k)){
				ans = mid;
				ei = mid-1;
			}
			else{
				si = mid+1;
			}
		}
		cout << ans << endl;
	}
}