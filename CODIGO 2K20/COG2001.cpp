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

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll p, q;
		cin >> p >> q;

		ll *k = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> k[i];
		}

		ll *a = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}

		umap<ll, ll> mymap;
		ll x;
		for(ll i = 0; i < n; i++){
			cin >> x;
			mymap[x]++;
		}

		string s;
		cin >> s;

		ll ans[2][2];
		ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = 0;
		for(ll i = 0; i < n; i++){
			auto it = mymap.find(k[i]+a[i]);
			if(it != mymap.end() && it->s > 0){
				(it->s)--;
				ans[s[i]-'0'][0] += k[i];
				ans[s[i]-'0'][1] += a[i];
			}
		}

		if(p*ans[0][0]+q*ans[0][1] > p*ans[1][0]+q*ans[1][1]){
			cout << "Frost" << endl;
		}
		else{
			cout << "DustinKiller" << endl;
		}
	}
}