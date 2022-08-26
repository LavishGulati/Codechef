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

bool compare(pll a, pll b){
	if(a.s != b.s){
		return a.s < b.s;
	}
	else{
		return a.f < b.f;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		string s, r;
		cin >> s >> r;

		ll n = s.length();

		vector<pll> helper;
		bool same;
		ll cnt = 1;
		if(s[0] == r[0]){
			same = true;
		}
		else{
			same = false;
		}

		for(ll i = 1; i < n; i++){
			if(same && s[i] == r[i]){
				cnt++;
			}
			else if(same && s[i] != r[i]){
				same = false;
				helper.pb(mp(cnt, 1));
				cnt = 1;
			}
			else if(!same && s[i] != r[i]){
				cnt++;
			}
			else{
				same = true;
				helper.pb(mp(cnt, 0));
				cnt = 1;
			}
		}

		if(same){
			helper.pb(mp(cnt, 1));
		}
		else{
			helper.pb(mp(cnt, 0));
		}

		ll m = helper.size();

		if(helper[0].s){
			helper.erase(helper.begin());
			m--;
		}

		if(m > 0 && helper[m-1].s){
			helper.erase(helper.end()-1);
			m--;
		}

		sort(all(helper), compare);

		ll sum = 0;
		for(ll i = 0; i < m; i++){
			sum += helper[i].f;
		}

		ll i = m-1;
		ll num = 1;
		while(i >= 0 && helper[i].s){
			if(helper[i].f > sum-helper[i].f){
				num++;
				sum -= helper[i].f;
				i--;
			}
			else{
				break;
			}
		}

		cout << ll(sum*num) << endl;
	}
}