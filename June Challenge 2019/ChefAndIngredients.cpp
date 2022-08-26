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

ll power(ll x, ll n){
    if(n == 0) return 1;
    else if(n == 1) return x%MOD;

    if(n%2 == 0){
        ll y = power(x, n/2);
        return (y*y)%MOD;
    }
    else{
        ll y = power(x, (n-1)/2);
        return (x*((y*y)%MOD))%MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll inv = power(2, MOD-2);
    ll t, n, k, answer, x, y, r;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k-1 < n){
            cout << (k-1+MOD)%MOD << endl;
            continue;
        }

        r = ((k-2)/(n-1) + 1)%MOD;
        x = (((r*(r+1))%MOD)*(k%MOD))%MOD;
        x = (x*inv)%MOD;
        y = (((k+n-1)%MOD)*((r*((r-1+MOD)%MOD))%MOD))%MOD;
        y = (y*inv)%MOD;
        answer = (x-y+MOD)%MOD;
        answer = (answer-r+MOD)%MOD;

        cout << answer << endl;
    }
}
