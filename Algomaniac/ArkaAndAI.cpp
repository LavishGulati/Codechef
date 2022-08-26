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

ll **matrixMul(ll **A, ll **B, ll n){
    ll **output = new ll *[n];
    for(ll i = 0; i < n; i++){
        output[i] = new ll[n];
        for(ll j = 0; j < n; j++) output[i][j] = 0;
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            for(ll k = 0; k < n; k++){
                output[i][j] = (output[i][j]+(A[i][k]*B[k][j])%MOD)%MOD;
            }
        }
    }

    return output;
}

ll **matrixPow(ll **graph, ll k, ll n){
    if(k == 1){
        return graph;
    }
    else if(k == 0){
        ll **output = new ll *[n];
        for(ll i = 0; i < n; i++){
            output[i] = new ll[n];
            for(ll j = 0; j < n; j++){
                if(j == i) output[i][j] = 1;
                else output[i][j] = 0;
            }
        }

        return output;
    }

    if(k%2){    // k is odd
        ll **helper = matrixPow(graph, (k-1)/2, n);
        return matrixMul(matrixMul(graph, helper, n), helper, n);
    }
    else{   // k is even
        ll **helper = matrixPow(graph, k/2, n);
        return matrixMul(helper, helper, n);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, q, k, m;
    cin >> n >> q >> k >> m;

    ll **graph = new ll *[n];
    for(ll i = 0; i < n; i++){
        graph[i] = new ll[n];
        for(ll j = 0; j < n; j++) graph[i][j] = 0;
    }

    ll u, v;
    for(ll i = 0; i < m; i++){
        cin >> u >> v;
        graph[u-1][v-1]++;
    }

    ll **newGraph = matrixPow(graph, k, n);

    for(ll i = 0; i < q; i++){
        cin >> u >> v;
        cout << newGraph[u-1][v-1] << endl;
    }
}
