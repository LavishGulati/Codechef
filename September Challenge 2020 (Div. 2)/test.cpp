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

ll ans;
string output;
ll k;

void solve(ll n, string help){
	if(help.size() == n){
		ll sum[2] = {0, 0};
		for(ll i = 0; i < n; i++){
			sum[help[i]-'0'] += pow(i+1, k);
		}
		if(abs(sum[0]-sum[1]) < ans){
			ans = abs(sum[0]-sum[1]);
			output = help;
		}
		return;
	}

	solve(n, help+'0');
	solve(n, help+'1');
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> k;

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		ans = LLONG_MAX;
		solve(n, "");
		cout << ans << endl;
		cout << output << endl;
	}
}