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

map<ll, ll> dsu;

void make_set(ll x){
    dsu[x] = x;
}

ll find_set(ll a){
    if(a == dsu[a]) return a;
    dsu[a] = find_set(dsu[a]);
    return dsu[a];
}

void union_sets(ll a, ll b){
    a = find_set(a);
    b = find_set(b);

    if(a != b) dsu[a] = b;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, n, q, type, s, x, l, r;
    cin >> t;
    while(t--){
        dsu.clear();
        cin >> n >> q;

        s = 0;
        while(q--){
            cin >> type;
            if(type == 1){
                cin >> x;
                x += s;
                if(dsu.find(x) == dsu.end()) make_set(x);
                if(dsu.find(x-1) == dsu.end()) make_set(x-1);
                union_sets(x, x-1);
            }
            else{
                cin >> l >> r;
                l += s;
                r += s;
                if(dsu.find(r) == dsu.end()) make_set(r);
                x = find_set(r);
                if(x < l) x = 0;
                cout << x << endl;
                s = (s+x)%n;
            }
        }
    }
}
