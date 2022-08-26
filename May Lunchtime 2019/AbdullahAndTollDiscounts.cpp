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

#define MAX 10009
ll toll[MAX];
vector<ll> path;
ll total = 0;

ll dfs(vector<ll> **graph, ll u, ll n, ll k, bool *IsVisited){
    IsVisited[u] = true;
    path.pb(u);

    // cout << u << " " << k << " " << total << " @ ";

    ll paid = 0;
    while(total > k){
        ll extra = min(total-k, toll[path[0]]);
        toll[path[0]] -= extra;
        paid += 2*extra;
        total -= extra;
        // cout << path[0] << " " << extra << " " << total << " " << toll[path[0]] << ", ";
        if(toll[path[0]] == 0) path.erase(path.begin());
    }
    // cout << endl;

    for(ll i = 0; i < graph[u]->size(); i++){
        ll v = graph[u]->at(i);
        if(!IsVisited[v]){
            total += toll[v];
            paid += dfs(graph, v, n, k, IsVisited);
        }
    }

    if(path.size() > 0 && path[path.size()-1] == u) path.pop_back();
    total -= toll[u];
    return paid;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, n, x, k, u, v;
    cin >> t;
    while(t--){
        cin >> n >> x >> k;
        x--;

        for(ll i = 0; i < n; i++) cin >> toll[i];

        vector<ll> **graph = new vector<ll> *[n];
        for(ll i = 0; i < n; i++){
            graph[i] = new vector<ll>;
        }

        for(ll i = 0; i < n-1; i++){
            cin >> u >> v;
            graph[u-1]->pb(v-1);
            graph[v-1]->pb(u-1);
        }

        bool *IsVisited = new bool[n];
        for(ll i = 0; i < n; i++) IsVisited[i] = false;
        total += toll[x];
        cout << dfs(graph, x, n, k, IsVisited) << endl;
    }
}
