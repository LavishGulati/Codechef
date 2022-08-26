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
	for(ll i = 0; i < t; i++){
		cout << "Test case : " << i+1 << " " << endl;
		ll n, q;
		cin >> n >> q;

		ll x, y, ans, m;
		char c;
		while(q--){
			cin >> x >> c;
			ans = 0; y = n;
			if(c == '+'){
				m = 0;
				while(y > 0){
					ans += x+(y%10);
					m = (m*10)+x;
					y /= 10;
				}
				n += m;
			}
			else if(c == '*'){
				while(y > 0){
					ans += (y%10)*x;
					y /= 10;
				}
			}
			else{
				if(x == 0){
					cout << "INVALID INPUT.'0' IS EVIL" << endl;
					continue;
				}
				while(y > 0){
					ans += (y%10)/x;
					y /= 10;
				}
			}
			cout << ans << endl;
		}
	}
}