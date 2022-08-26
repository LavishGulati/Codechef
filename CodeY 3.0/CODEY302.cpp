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

ll solve(string &s, ll id, ll n){
	if(id == n){
		return 1;
	}

	ll ans = 0;
	if(s[id] >= '1' && s[id] <= '9'){
		ans += solve(s, id+1, n);
	}

	if(id+1 < n){
		ll x = (s[id]-'0')*10 + (s[id+1]-'0');
		if(x >= 10 && x <= 26){
			ans += solve(s, id+2, n);
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;

		ll ans = solve(s, 0, s.length());
		// cout << ans << " "; 
		if(ans%2){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
		}
	}
}