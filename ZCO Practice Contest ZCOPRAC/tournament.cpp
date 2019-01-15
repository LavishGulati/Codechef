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

    ll n;
    cin >> n;
    ll *strength = new ll[1001];
    for(ll i = 0; i < 1001; i++) strength[i] = 0;

    ll x;
    for(ll i = 0; i < n; i++){
        cin >> x;
        strength[x]++;
    }

    ll total = 0;
    for(ll i = 0; i < 1001; i++){
        for(ll j = i+1; j < 1001; j++){
            total += strength[i]*strength[j]*abs(j-i);
        }
    }

    cout << total << endl;
}
