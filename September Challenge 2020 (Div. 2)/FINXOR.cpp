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
	while(t--){
		ll n, a;
		cin >> n;

		cout << "1 1" << endl;
		cin >> a;

		ll help, ans = 0, b, num;
		if(a%2 != n%2){
			ans++;
		}

		help = 2;
		for(ll i = 0; i < 19; i++){
			cout << "1 " << help+1 << endl;
			cin >> b;
			num = (a-b+help*n)/(2*help);
			if(num%2){
				ans += help;
			}
			help *= 2;
		}

		cout << "2 " << ans << endl;
		cin >> ans;
		if(ans == -1){
			break;
		}
	}
}