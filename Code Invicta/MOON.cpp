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

	ll t;
	cin >> t;
	bool ans;
	while(t--){
		ans = false;
		ll n, m, x, y;
		cin >> n >> m >> x >> y;

		if((n*x + m*y)%2 == 1){
			cout << "NO" << endl;
			continue;
		}

		ll a = 0;
		for(; a <= n; a++){
			ll by = (n*x+m*y)/2 - a*x;
			if(y == 0){
				if(by == 0){
					ans = true;
					cout << "YES" << endl;
					break;
				}	
			}
			else if(by%y == 0){
				ll b = by/y;
				if(b >= 0 && b <= m){
					ans = true;
					cout << "YES" << endl;
					break;
				}	
			}
		}

		if(!ans){
			cout << "NO" << endl;
		}
	}
}