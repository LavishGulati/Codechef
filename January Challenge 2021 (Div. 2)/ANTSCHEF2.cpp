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

void buildTree(ll *tree, ll si, ll ei, ll id){
    if(si == ei){
        tree[id] = 1;
        return;
    }
    
    ll mid = (si+ei)/2;
    buildTree(tree, si, mid, 2*id);
    buildTree(tree, mid+1, ei, 2*id+1);
    
    tree[id] = tree[2*id]+tree[2*id+1];
}

void update(ll *tree, ll si, ll ei, ll id, ll x){
    if(si == ei){
        tree[id] = 0;
        return;
    }
    
    ll mid = (si+ei)/2;
    if(x <= mid){
    	update(tree, si, mid, 2*id, x);
    }
    else{
    	update(tree, mid+1, ei, 2*id+1, x);
    }
    
    tree[id] = tree[2*id]+tree[2*id+1];
}

ll query(ll *tree, vector<ll> &v, ll si, ll ei, ll start, ll end, ll id){
	if(si > ei){
		return 0;
	}
	else if(si == ei){
		return (v[si] > start && v[si] < end) ? tree[id] : 0;
	}
    else if(v[si] > end || v[ei] < start){
    	return 0;
    }
    else if(v[si] > start && v[ei] < end){
    	return tree[id];
    }
    else{
        ll mid = (si+ei)/2;
        ll a = query(tree, v, si, mid, start, end, 2*id);
        ll b = query(tree, v, mid+1, ei, start, end, 2*id+1);
        return a+b;
    }
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		vector<vector<ll>> X;
		vector<ll> v;
		ll m, x;
		for(ll i = 0; i < n; i++){
			cin >> m;
			v.clear();
			for(ll j = 0; j < m; j++){
				cin >> x;
				v.pb(x);
			}
			X.pb(v);
		}

		for(ll i = 0; i < n; i++){
			sort(all(X[i]));
		}

		umap<ll, ll> *rid = new umap<ll, ll>[n];
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < X[i].size(); j++){
				rid[i][X[i][j]] = j;
			}
		}

		ll **tree = new ll *[n];
		for(ll i = 0; i < n; i++){
			tree[i] = new ll[4*X[i].size()];
			buildTree(tree[i], 0, X[i].size()-1, 1);
		}

		ll ans = 0;

		map<ll, set<ll>> mp;
		for(ll i = 0; i < n; i++){
			for(ll x : X[i]){
				mp[abs(x)].insert(i);
			}
		}
		for(auto p : mp){
			if(p.s.size() > 1){
				ans++;
			}
		}

		for(auto p : mp){
			if(p.s.size() > 1){
				for(ll id : p.s){
					if(rid[id].find(p.f) != rid[id].end()){
						ans += query(tree[id], X[id], 0, X[id].size()-1, -p.f, 0, 1);
						ans += query(tree[id], X[id], 0, X[id].size()-1, p.f, INT_MAX, 1);
						update(tree[id], 0, X[id].size()-1, 1, rid[id][p.f]);
					}
					if(rid[id].find(-p.f) != rid[id].end()){
						ans += query(tree[id], X[id], 0, X[id].size()-1, 0, p.f, 1);
						ans += query(tree[id], X[id], 0, X[id].size()-1, INT_MIN, -p.f, 1);
						update(tree[id], 0, X[id].size()-1, 1, rid[id][-p.f]);
					}
				}
			}
		}

		ll pos, neg;
		for(ll i = 0; i < n; i++){
			pos = query(tree[i], X[i], 0, X[i].size()-1, 0, INT_MAX, 1);
			neg = query(tree[i], X[i], 0, X[i].size()-1, INT_MIN, 0, 1);
			ans += pos*neg;
		}

		cout << ans << endl;
	}
}