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
#define f first
#define s second
#define MOD 1000000007

bool compare(pll a, pll b){
    return max(a.f+a.s, a.f+b.f+b.s) < max(b.f+b.s, b.f+a.f+a.s);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    pll *input = new pll[n];

    ll a, b, c;
    for(ll i = 0; i < n; i++){
        cin >> a >> b >> c;
        input[i] = mp(a, b+c);
    }

    sort(input, input+n, compare);
    for(ll i = 1; i < n; i++) input[i].f += input[i-1].f;
    ll maxTime = 0;
    for(ll i = 0; i < n; i++){
        maxTime = max(maxTime, input[i].f+input[i].s);
    }

    cout << maxTime << endl;
}
