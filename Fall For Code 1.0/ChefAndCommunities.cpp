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

stack<ll> st;
vector<vector<ll>> scc;
vector<ll> helper;

void dfs(ll u, vector<ll> *graph, bool *IsVisited){
    IsVisited[u] = true;

    for(ll v : graph[u]){
        if(!IsVisited[v]){
            dfs(v, graph, IsVisited);
        }
    }

    st.push(u);
}

void dfs2(ll u, vector<ll> *graph, bool *IsVisited){
    IsVisited[u] = true;
    helper.pb(u);

    for(ll v : graph[u]){
        if(!IsVisited[v]){
            dfs2(v, graph, IsVisited);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, n, m, u, v, id, x, answer;
    cin >> t;
    while(t--){
        scc.clear();
        while(!st.empty()) st.pop();

        cin >> n >> m;
        vector<ll> *graph = new vector<ll>[n];
        vector<ll> *RevGraph = new vector<ll>[n];

        ll *tax = new ll[n];
        for(ll i = 0; i < n; i++) cin >> tax[i];

        while(m--){
            cin >> u >> v;
            graph[u-1].pb(v-1);
            RevGraph[v-1].pb(u-1);
        }

        bool *IsVisited = new bool[n];
        for(ll i = 0; i < n; i++) IsVisited[i] = false;
        for(ll u = 0; u < n; u++){
            if(!IsVisited[u]){
                dfs(u, graph, IsVisited);
            }
        }

        for(ll i = 0; i < n; i++) IsVisited[i] = false;
        id = 0;
        while(!st.empty()){
            u = st.top();
            st.pop();
            if(!IsVisited[u]){
                helper.clear();
                dfs2(u, RevGraph, IsVisited);
                scc.pb(helper);
                id++;
            }
        }

        vector<ll> rev;
        for(ll i = 0; i < scc.size(); i++){
            rev.pb(0);
            for(ll u : scc[i]){
                rev[i] += tax[u];
            }
        }

        sort(all(rev));
        answer = 0;
        for(ll i = 0; i < id; i++){
            answer += (i+1)*rev[i];
        }

        cout << answer << "\n";
    }
}
