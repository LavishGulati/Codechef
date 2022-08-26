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

#define MAX 100005
#define MAX2 1000005
#define LN 20

vector<ll> graph[MAX];
ll a[MAX], start[MAX], endtme[MAX], euler[2*MAX], depth[MAX];
ll visited[MAX], output[MAX], inv[MAX];
ll prime[MAX2], freq[MAX2];
ll dp[MAX][LN];
ll tme, block;

struct query{
	ll id, l, r, lca;

	query(){

	}

	query(ll id, ll l, ll r, ll lca){
		this->id = id;
		this->l = l;
		this->r = r;
		this->lca = lca;
	}
} qry[MAX];

ll power(ll x, ll n, ll mod){
	if(n == 0){
		return 1%mod;
	}
	else if(n == 1){
		return x%mod;
	}

	ll y = power(x, n/2, mod);
	if(n%2){
		return (((y*y)%mod)*x)%mod;
	}
	else{
		return (y*y)%mod;
	}
}

ll modInverse(ll x){
	return power(x, MOD-2, MOD);
}

void sieve(){ 

    memset(prime, 0, sizeof(prime)); 
  
    for (ll p = 2; p < MAX2; p++){ 
        if (!prime[p]){ 
        	prime[p] = p;
            for (ll i=p*p; i < MAX2; i += p){
            	if(!prime[i]){
            		prime[i] = p; 
            	}
            }
        } 
    }
}

void preprocess(){
	for(ll i = 1; i < MAX; i++){
		inv[i] = modInverse(i);
	}
	// for(ll i = 1; i < 10; i++){
	// 	cout << (12*inv[i])%MOD;
	// }
	// cout << endl;
	// cout << inv[3] << " " << (12*inv[3])%MOD << endl;

	sieve();
}

void buildSparseTable(ll n){
	for(ll j = 1; j < LN; j++){
		for(ll i = 1; i <= n; i++){
			if(dp[i][j-1] != -1){
				dp[i][j] = dp[dp[i][j-1]][j-1];
			}
		}
	}
}

void dfs(ll u, ll par, ll dep){
	euler[++tme] = u;
	start[u] = tme;
	depth[u] = dep;
	dp[u][0] = par;

	for(ll v : graph[u]){
		if(v != par){
			dfs(v, u, depth[u]+1);
		}
	}

	euler[++tme] = u;
	endtme[u] = tme;
}

ll lca(ll u, ll v){
	if(u == v){
		return u;
	}
	
	if(depth[v] < depth[u]){
		swap(u, v);
	}

	ll d = depth[v]-depth[u];
	for(ll i = LN-1; i >= 0; i--){
		if(depth[v] - (1<<i) >= depth[u]){
			v = dp[v][i];
		}
	}

	if(u == v){
		return u;
	}

	for(ll i = LN-1; i >= 0; i--){
		if(dp[u][i] != dp[v][i]){
			u = dp[u][i];
			v = dp[v][i];
		}
	}

	return dp[u][0];
}

bool compare(query x, query y){
	if((x.l-1)/block != (y.l-1)/block){
		return (x.l-1)/block < (y.l-1)/block;
	}
	else{
		return x.r < y.r;
	}
}

void remove(ll id, ll &ans){
	ll x = a[id], cnt, y;
	while(x > 1){
		cnt = 0;
		y = prime[x];
		while(x%y == 0){
			cnt++;
			x /= y;
		}
		ans = (ans*(freq[y]-cnt+1))%MOD;
		// cout << "SEMI-ANS: " << ans << endl;
		ans = (ans*inv[freq[y]+1])%MOD;
		// cout << "SEMI-ANS: " << freq[y]+1 << " " << ans << endl;

		freq[y] -= cnt;
		// cout << "FREQ: " << y << " " << freq[y] << endl;
	}
}

void add(ll id, ll &ans){
	ll x = a[id], cnt, y;
	while(x > 1){
		cnt = 0;
		y = prime[x];
		while(x%y == 0){
			cnt++;
			x /= y;
		}
		ans = (ans*(freq[y]+cnt+1))%MOD;
		ans = (ans*inv[freq[y]+1])%MOD;
		freq[y] += cnt;
		// cout << "FREQ: " << y << " " << freq[y] << endl;
	}
}

void check(ll id, ll &ans){
	// cout << "CHECK: " << euler[id] << " " << visited[euler[id]] << endl;
	if(visited[euler[id]]){
		// cout << "REM: " << euler[id] << endl;
		remove(euler[id], ans);
	}
	else{
		// cout << "ADD: " << euler[id] << endl;
		add(euler[id], ans);
	}
	visited[euler[id]] ^= 1;
}

void compute(ll q){
	ll curl = qry[0].l, curr = qry[0].l-1;
	ll ans = 1;

	for(ll i = 0; i < q; i++){
		// cout << qry[i].id << " ";

		// cout << "COMPUTE: " << qry[i].l << " " << qry[i].r << endl;

		while(curl < qry[i].l){
			check(curl, ans);
			curl++;
		}
		while(curl > qry[i].l){
			curl--;
			check(curl, ans);
		}
		while(curr > qry[i].r){
			check(curr, ans);
			curr--;
		}
		while(curr < qry[i].r){
			curr++;
			check(curr, ans);
		}

		output[qry[i].id] = ans;

		// cout << "COORD: " << curl << " " << curr << endl;
		if(qry[i].lca != euler[qry[i].l] && qry[i].lca != euler[qry[i].r]){
			// output[qry[i].id] *= a[qry[i].lca];

			ll x = a[qry[i].lca], cnt, y;
			while(x > 1){
				cnt = 0;
				y = prime[x];
				while(x%y == 0){
					cnt++;
					x /= y;
				}
				output[qry[i].id] = (output[qry[i].id]*(freq[y]+cnt+1))%MOD;
				output[qry[i].id] = (output[qry[i].id]*inv[freq[y]+1])%MOD;
				// freq[y] += cnt;
			}

		}
	}

	for(ll i = 0; i < q; i++){
		// cout << output[i] << endl;
		printf("%lld\n", output[i]);
	}
}

int main(){
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	preprocess();

	ll t;
	// cin >> t;
	scanf(" %lld", &t);
	while(t--){
		ll n;
		// cin >> n;
		scanf(" %lld", &n);

		tme = 0;
		memset(freq, 0, sizeof(freq));
		memset(visited, 0, sizeof(visited));
		for(ll i = 1; i <= n; i++){
			graph[i].clear();
		}

		ll u, v;
		for(ll i = 1; i < n; i++){
			scanf(" %lld %lld", &u, &v);

			graph[u].pb(v);
			graph[v].pb(u);
		}

		for(ll i = 1; i <= n; i++){
			// cin >> a[i];
			scanf(" %lld", a+i);
		}

		dfs(1, -1, 0);

		// cout << "Euler: "; 
		// for(ll i = 1; i <= tme; i++){
		// 	cout << euler[i] << " ";
		// }
		// cout << endl;

		// cout << "Start: "; 
		// for(ll i = 1; i <= n; i++){
		// 	cout << start[i] << " ";
		// }
		// cout << endl;

		// cout << "End: "; 
		// for(ll i = 1; i <= n; i++){
		// 	cout << endtme[i] << " ";
		// }
		// cout << endl;

		// cout << "Depth: "; 
		// for(ll i = 1; i <= n; i++){
		// 	cout << depth[i] << " ";
		// }
		// cout << endl;

		block = sqrt(tme);
		buildSparseTable(tme);

		ll q, x;
		scanf(" %lld", &q);

		for(ll i = 0; i < q; i++){
			scanf(" %lld %lld", &u, &v);

			x = lca(u, v);
			// cout << "LCA: " << u << " " << v << " " << x << endl;

			if(x == u || x == v){
				if(start[u] > start[v]){
					swap(u, v);
				}
				qry[i] = query(i, start[u], start[v], x);
			}
			else{
				if(endtme[u] > start[v]){
					swap(u, v);
				}
				qry[i] = query(i, endtme[u], start[v], x);
			}
		}

		sort(qry, qry+q, compare);

		compute(q);
	}
}