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

#define MAX 1000005

class Query{
public:
	ll l, r, id;
	Query(ll l, ll r, ll id){
		this->l = l;
		this->r = r;
		this->id = id;
	}
	Query(){

	}
}

bool compare(Query a, Query b){
	if(a.l != b.l){
		a.f < b.f;
	}
	else if(a.r != b.r){
		return a.r > b.r;
	}
	else{
		return a.id < b.id;
	}
}

ll out[MAX], pll a[MAX];
Query qry[MAX];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, q;
		cin >> n >> q;

		for(ll i = 0; i < n; i++){
			cin >> a[i].f >> a[i].s;
		}

		for(ll i = 0; i < q; i++){
			ans[i] = 0;
		}

		ll len = 0;
		for(ll i = 0; i < q; i++){
			cin >> qry[i].f >> qry[i].s;
			len = qry[i].s-qry[i].f;
			qry[i].id = i;
		}

		vector<pll> temp;
		for(ll i = 0; i < n; i++){
			if(a[i].s <= len/2){
				temp.pb(mp(a[i].f, a[i].s));
			}
		}

		sort(all(temp));
		sort(qry, qry+q, compare);

		ll i = 0;
		ll j = 0;
		for(ll k = 0; k < q; k++){
			while(i < temp.size() && temp[i].f-qry[k].l < 0){
				i++;
			}
			while(i < temp.size() && temp[i].f-qry[k].l > temp[i].s){
				i++;
			}

			while(j < temp.size() && temp[j].f-qry[k].l >= 0){
				j++;
			}
			while(j < temp.size() && temp[j].f-qry[k].l <= temp[j].s){
				j++;
			}

			ans[qry[k].id] += max(j-i, 0);
		}

		i = 0;
		j = 0;
		for(ll k = 0; k < q; k++){
			while(i < temp.size() && temp[i].f-qry[k].l < 0){
				i++;
			}
			while(i < temp.size() && temp[i].f-qry[k].l > temp[i].s){
				i++;
			}

			while(j < temp.size() && temp[j].f-qry[k].l >= 0){
				if(temp[j].f >= qry[k].l+len/2)
				j++;
			}
			while(j < temp.size() && temp[j].f-qry[k].l <= temp[j].s){
				j++;
			}

			ans[qry[k].id] += j-i;
		}
	}
}