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

#define MAX 300005

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k;
    cin >> n >> k;
    ll weight[MAX];
    for(ll i = 1; i <= n; i++){
        cin >> weight[i];
    }
    ll cut[MAX];
    for(ll i = 1; i <= k; i++){
        cin >> cut[i];
    }

    weight[0] = 0;
    for(ll i = 2; i <= n; i++){
        weight[i] += weight[i-1];
    }
    map<ll, ll> indexMap;
    indexMap[1] = weight[n];
    indexMap[n+1] = 0;

    map<ll, ll> weightMap;
    weightMap[weight[n]] = true;

    for(ll i = 1; i <= k; i++){
        ll x = cut[i];
        auto si = indexMap.lower_bound(x);
        auto ei = indexMap.upper_bound(x);
        if(si->f != x) si--;
        // cout << x << " " << si->f << " " << ei->f << endl;
        if(weightMap[si->s] == 1){
            weightMap.erase(si->s);
        }
        else{
            weightMap[si->s]--;
        }

        ll a = weight[x]-weight[(si->f)-1];
        ll b = weight[(ei->f)-1]-weight[x];
        indexMap[si->f] = a;
        indexMap[x+1] = b;

        if(weightMap.find(a) != weightMap.end()){
            weightMap[a]++;
        }
        else{
            weightMap[a] = 1;
        }

        if(weightMap.find(b) != weightMap.end()){
            weightMap[b]++;
        }
        else{
            weightMap[b] = 1;
        }
        // auto j = weightMap.end();
        // j--;
        cout << (weightMap.rbegin())->f << endl;
        // cout << "Map is: " ;
        // for(auto p: indexMap)
        // {
        //     cout << p.first << " " ;
        // }
        // cout << endl ;
    }
}
