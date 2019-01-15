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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, n, p;
    cin >> t;
    while(t--){
        cin >> n >> p;
        if(p == 1){
            cout << 1 << endl;
            continue;
        }
        if(n == 1){
            cout << p*p*p << endl;
            continue;
        }
        for(ll i = 2; ; i++){
            if(p >= n/i + 1){
                ll x = n%(n/i + 1);
                if(x == 0) cout << p*p*p << endl;
                else cout << (p-x)*(p-x) + max((p-n)*(p-x), 0LL) + max((p-n)*(p-n), 0LL) << endl;
                break;
            }
        }
    }
}
