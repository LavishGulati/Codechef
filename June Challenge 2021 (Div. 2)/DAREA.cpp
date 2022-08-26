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

ll solve(ll **points, ll id, ll n){
	ll *left_high = new ll[n];
	ll *right_high = new ll[n];
	ll *left_low = new ll[n];
	ll *right_low = new ll[n];

	left_high[0] = points[0][id^1];
	left_low[0] = points[0][id^1];
	for(ll i = 1; i < n; i++){
		left_high[i] = max(left_high[i-1], points[i][id^1]);
		left_low[i] = min(left_low[i-1], points[i][id^1]);
	}

	right_low[n-1] = points[n-1][id^1];
	right_high[n-1] = points[n-1][id^1];
	for(ll i = n-2; i >= 0; i--){
		right_high[i] = max(right_high[i+1], points[i][id^1]);
		right_low[i] = min(right_low[i+1], points[i][id^1]);
	}

	ll ans = LLONG_MAX;
	for(ll i = 0; i < n; i++){
		while(i+1 < n && points[i+1][id] == points[i][id]){
			i++;
		}
		ll a1 = (points[i][id]-points[0][id])*(left_high[i]-left_low[i]);
		ll a2 = 0;
		if(i < n-1){
			a2 = (points[n-1][id]-points[i+1][id])*(right_high[i+1]-right_low[i+1]);
		}
		// cout << id << " " << i << " " << a1+a2 << endl;
		ans = min(ans, a1+a2);
	}
	return ans;
}

bool compare1(ll *a, ll *b){
	if(a[0] < b[0]){
		return true;
	}
	else if(a[0] > b[0]){
		return false;
	}
	else{
		return a[1] < b[1];
	}
}

bool compare2(ll *a, ll *b){
	if(a[1] < b[1]){
		return true;
	}
	else if(a[1] > b[1]){
		return false;
	}
	else{
		return a[0] < b[0];
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		ll **points = new ll *[n];
		for(ll i = 0; i < n; i++){
			points[i] = new ll[2];
			cin >> points[i][0] >> points[i][1];
		}

		sort(points, points+n, compare1);
		ll ans = solve(points, 0, n);

		// cout << ans << endl;

		sort(points, points+n, compare2);
		ans = min(solve(points, 1, n), ans);
		
		cout << ans << endl;
	}
}