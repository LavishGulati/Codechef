#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		ll a;
		cin >> a;

		ll s = a + 2*ll(pow(10, n));
		cout << s << endl;

		ll b;
		cin >> b;

		ll c = ll(pow(10, n))-b;
		cout << c << endl;

		ll d;
		cin >> d;

		ll e = ll(pow(10, n))-d;
		cout << e << endl;

		ll ans;
		cin >> ans;
	}
}