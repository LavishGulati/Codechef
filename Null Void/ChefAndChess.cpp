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

#define MAX 10000001
// #define MAX 100001

ll exponent(ll x, ll n){
    if(n == 0) return 1;
    if(n == 1) return x%MOD;

    ll y;
    if(n%2 == 0){
        y = exponent(x, n/2);
        return (y*y)%MOD;
    }
    else{
        y = exponent(x, (n-1)/2);
        return (x*((y*y)%MOD))%MOD;
    }
}

ll ModInverse(ll x){
    return exponent(x, MOD-2);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, n;
    cin >> t;

    ll factorial[MAX];
    factorial[0] = 1;
    for(ll i = 1; i < MAX; i++) factorial[i] = (i*factorial[i-1])%MOD;

    ll power[MAX];
    power[0] = 1;
    for(ll i = 1; i < MAX; i++) power[i] = (2*power[i-1])%MOD;

    ll answer;

    while(t--){
        cin >> n;

        if(n%2 == 0){
            answer = (factorial[n/2]*power[n/2])%MOD;
            answer = ModInverse(answer);
            answer = (factorial[n]*answer)%MOD;
            cout << answer << endl;
        }
        else{
            answer = (factorial[(n-1)/2]*power[(n-1)/2])%MOD;
            answer = ModInverse(answer);
            answer = (factorial[n-1]*answer)%MOD;
            answer = (n*answer)%MOD;
            cout << answer << endl;
        }
    }
}
