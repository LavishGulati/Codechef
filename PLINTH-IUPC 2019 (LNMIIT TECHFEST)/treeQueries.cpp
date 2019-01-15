#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

ll total = 0;
ll weight[100009];

priority_queue< ll, vector<ll>, greater<ll> > solve(vector<ll> **graph, ll v, ll n, ll k, bool *isVisited){
    priority_queue< ll, vector<ll>, greater<ll> > pq;
    isVisited[v] = true;
    for(ll i = 0; i < graph[v]->size(); i++){
        ll u = graph[v]->at(i);
        if(!isVisited[u]){
            priority_queue< ll, vector<ll>, greater<ll> > ans = solve(graph, u, n, k, isVisited);
            while(ans.size() != 0){
                pq.push(ans.top());
                ans.pop();
            }
        }
    }

    pq.push(weight[v]);
    if(pq.size() < k){
        return pq;
    }
    priority_queue< ll, vector<ll>, greater<ll> > ans;
    ll num = 1;
    while(num != k){
        ans.push(pq.top());
        pq.pop();
        num++;
    }
    // cout << pq.top() << endl;
    total += pq.top();
    while(ans.size() != 0){
        pq.push(ans.top());
        ans.pop();
    }
    return pq;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k, u, v;
    cin >> n >> k;
    vector<ll> **graph = new vector<ll> *[n];
    for(ll i = 0; i < n; i++){
        graph[i] = new vector<ll>;
    }
    for(ll i = 0; i < n-1; i++){
        cin >> u >> v;
        graph[u-1]->pb(v-1);
        graph[v-1]->pb(u-1);
    }
    for(ll i = 0; i < n; i++) cin >> weight[i];

    bool *isVisited = new bool[n];
    for(ll i = 0; i < n; i++) isVisited[i] = false;
    priority_queue< ll, vector<ll>, greater<ll> > pq = solve(graph, 0, n, k, isVisited);

    cout << total << endl;
}
