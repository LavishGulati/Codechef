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
	while(t--){
		ll n;
		cin >> n;

		map<ll, ll> mpa;
		map<ll, ll> mpb;

		ll x, smallest = INT_MAX;
		for(ll i = 0; i < n; i++){
			cin >> x;
			smallest = min(smallest, x);
			if(mpa.find(x) != mpa.end()){
				mpa[x]++;
			}
			else{
				mpa[x] = 1;
			}
		}

		for(ll i = 0; i < n; i++){
			cin >> x;
			smallest = min(smallest, x);
			if(mpb.find(x) != mpb.end()){
				mpb[x]++;
			}
			else{
				mpb[x] = 1;
			}
		}

		for(auto it = mpa.begin(); it != mpa.end(); it++){
			if(mpb.find(it->f) != mpb.end()){
				x = min(it->s, mpb[it->f]);
				mpa[it->f] -= x;
				mpb[it->f] -= x;
			}
		}

		for(auto it = mpb.begin(); it != mpb.end(); it++){
			if(mpa.find(it->f) != mpa.end()){
				x = min(it->s, mpa[it->f]);
				mpa[it->f] -= x;
				mpb[it->f] -= x;
			}
		}

		vector<pll> a;
		vector<pll> b;
		for(pll x : mpa){
			if(x.s > 0){
				a.pb(mp(x.f, x.s));
			}
		}

		for(pll x : mpb){
			if(x.s > 0){
				b.pb(mp(x.f, x.s));
			}
		}

		ll ans = 0;
		for(ll i = 0; i < a.size(); i++){
			if((a[i].s)%2){
				ans = -1;
				break;
			}
			else{
				a[i].s /= 2;
			}
		}

		for(ll i = 0; i < b.size(); i++){
			if((b[i].s)%2){
				ans = -1;
				break;
			}
			else{
				b[i].s /= 2;
			}
		}

		if(ans == -1){
			cout << -1 << endl;
			continue;
		}

		ll si = 0, ei = a.size()-1, sj = 0, ej = b.size()-1;
		while(si <= ei && sj <= ej){
			if(a[si].f <= b[sj].f){
				x = min(a[si].s, b[ej].s);
				a[si].s -= x;
				b[ej].s -= x;
				ans += (x)*min(a[si].f, 2*smallest);
				if(a[si].s == 0){
					si++;
				}
				if(b[ej].s == 0){
					ej--;
				}
			}
			else{
				x = min(b[sj].s, a[ei].s);
				b[sj].s -= x;
				a[ei].s -= x;
				ans += (x)*min(b[sj].f, 2*smallest);
				if(a[ei].s == 0){
					ei--;
				}
				if(b[sj].s == 0){
					sj++;
				}
			}
		}

		if(si <= ei || sj <= ej){
			cout << -1 << endl;
		}
		else{
			cout << ans << endl;
		}
	}
}