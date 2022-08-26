#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;
typedef vector<int> vi;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

#define MAX 300001

vector<vi> adj(MAX);
ll par[MAX][20];
ll subtree[MAX], ans1[MAX], ans2[MAX], ans3[MAX];
ll dep[MAX];
ll preans2[MAX], preans3[MAX];
ll n;

ll dfs(ll cur, ll parent){
    ll i;
    par[cur][0] = parent;
    ans3[cur] = 0;

    if(parent == -1){
        dep[cur] = 0;
    }
    else{
        dep[cur] = dep[parent]+1;
    }

    subtree[cur] = 1;
    for(i = 0; i < adj[cur].size(); i++){
        if(adj[cur][i] != parent){
            dfs(adj[cur][i], cur);
            subtree[cur] += subtree[adj[cur][i]];
        }
    }

    ans2[cur] = subtree[cur]*(subtree[cur]+1);
    for(i = 0; i < adj[cur].size(); i++){
        if(adj[cur][i] != parent){
            ans2[cur] -= subtree[adj[cur][i]]*(subtree[adj[cur][i]]+1);
        }
    }

    ans2[cur] /= 2;
    ans1[cur] = ans2[cur]+subtree[cur]*(n-subtree[cur]);
    return 0;
}

ll dfs1(ll cur, ll parent){
    ll i;
    if(parent == -1){
        preans2[cur] = ans2[cur];
        preans3[cur] = ans3[cur];
    }
    else{
        preans2[cur] = preans2[parent]+ans2[cur];
        preans3[cur] = preans3[parent]+ans3[cur];
    }

    for(i = 0; i < adj[cur].size(); i++){
        if(adj[cur][i] != parent){
            ans3[adj[cur][i]] = (subtree[cur]-subtree[adj[cur][i]])*(subtree[adj[cur][i]]);
            dfs1(adj[cur][i], cur);
        }
    }
    return 0;
}

ll getlca(ll u, ll v){
    ll i;
    for(i = 19; i >= 0; i--){
        if(dep[v]-(1<<i) >= dep[u]){
            v = par[v][i];
        }
    }

    if(u == v) return u;
    for(i = 19; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

ll getpar(ll u, ll deep){
    ll i;
    for(i = 19; i >= 0; i--){
        if(dep[u]-(1<<i) >= deep){
            u = par[u][i];
        }
    }
    return u;
}

ll solve(ll u, ll v){
    ll foo, wow = 0;
    foo = getpar(v, dep[u]+1);
    wow = preans2[v]-preans2[u];
    wow -= preans3[v]-preans3[foo];
    wow += ans1[u];
    wow -= (subtree[foo])*(n-subtree[foo]);
    return wow;
}

int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    scanf("%lld", &t);
    while(t--){
        ll q;
        scanf("%lld%lld", &n, &q);

        ll i, u, v;
        for(i = 0; i < n; i++) adj[i].clear();

        for(i = 0; i < n-1; i++){
            scanf("%lld%lld", &u, &v);
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        }

        dfs(0, -1);
        ll j;
        for(j = 1; j < 20; j++){
            for(i = 1; i < n; i++){
                if(par[i][j-1] == -1){
                    par[i][j] = -1;
                }
                else{
                    par[i][j] = par[par[i][j-1]][j-1];
                }
            }
        }

        dfs1(0, -1);
        ll gg;
        for(i = 0; i < q; i++){
            scanf("%lld%lld", &u, &v);
            u--; v--;
            if(dep[u] > dep[v]){
                swap(u, v);
            }
            gg = getlca(u, v);
            ll how;
            if(u == v){
                how = ans1[u];
            }
            else if(gg == u){
                how = solve(u, v);
            }
            else{
                ll foo1 = getpar(v, dep[gg]+1);
                ll foo2 = getpar(u, dep[gg]+1);
                how = solve(gg, v)+solve(gg, u)+(subtree[foo1]*subtree[foo2])-ans1[gg];
            }

            printf("%lld\n", how);
        }
    }
}
