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

#define MAX 100001

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

ll h(ll n){
    if(n == 0) return 0;
    else return n/2 + h(n/2);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll factorial[MAX];
    factorial[0] = factorial[1] = 1;
    factorial[2] = 2;
    ll FactorialWithout2[MAX];
    FactorialWithout2[1] = FactorialWithout2[0] = 1;
    FactorialWithout2[2] = 1;
    for(ll i = 3; i < MAX; i++){
        factorial[i] = (factorial[i-1]*i)%MOD;
        FactorialWithout2[i] = (FactorialWithout2[i-1]*i)%MOD;
    }

    ll t, n;
    cin >> t;
    while(t--){
        cin >> n;
        ll input[n];
        for(ll i = 0; i < n; i++) cin >> input[i];
        sort(input, input+n);

        if(n == 1){
            cout << input[0] << endl;
            cout << 3 << endl;
            continue;
        }

        ll output[n];
        ll i = 2;
        ll j = n-1;
        ll id = 2;
        output[0] = input[0];
        output[1] = input[1];
        bool IsLeft = false;
        while(i <= j){
            if(IsLeft){
                output[i] = input[id];
                i++;
                IsLeft = false;
            }
            else{
                output[j] = input[id];
                j--;
                IsLeft = true;
            }

            id++;
        }

        for(ll i = 0; i < n; i++){
            cout << output[i] << " ";
        }
        cout << endl;

        map<ll, ll> m;
        for(ll i = 0; i < n; i++){
            m[input[i]]++;
        }
        ll q;

        ll helper = 1;
        ll deg2 = h(n);
        for(auto i = m.begin(); i != m.end(); i++){
            helper = (helper*(factorial[i->s]))%MOD;
            deg2 -= h(i->s);
        }
        // cout << helper << " " << endl;

        if(input[1] == input[0]) q = factorial[n];
        else{
            if(deg2) q = FactorialWithout2[n];
            else q = factorial[n];
        }

        q = (q*ModInverse(helper))%MOD;
        // cout << q << endl;

        if(input[0] != input[1] && !deg2){
            cout << (3*q+2)%MOD << endl;
        }
        else cout << (2*q+1)%MOD << endl;
    }
}
