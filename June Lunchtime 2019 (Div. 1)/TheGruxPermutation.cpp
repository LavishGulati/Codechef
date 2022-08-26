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

ll inversions(vector<ll> &v, ll si, ll ei){
    if(si >= ei) return 0;

    ll mid = (si+ei)/2;
    ll x = inversions(v, si, mid);
    ll y = inversions(v, mid+1, ei);

    ll answer = x+y;
    ll i = si;
    ll j = mid+1;
    vector<ll> helper;
    while(i <= mid && j <= ei){
        if(v[i] < v[j]){
            helper.pb(v[i]);
            i++;
        }
        else{
            answer += mid+1-i;
            helper.pb(v[j]);
            j++;
        }
    }

    while(i <= mid){
        helper.pb(v[i]);
        i++;
    }

    while(j <= ei){
        helper.pb(v[j]);
        j++;
    }

    for(i = si; i <= ei; i++){
        v[i] = helper[i-si];
    }

    return answer;
}

ll solve(ll *input, ll n, ll d){
    ll *dup = new ll[n];
    for(ll i = 0; i < n; i++) dup[i] = input[i];
    sort(dup, dup+n);

    ll j, m, k;
    ll ans = 0, x;
    set<ll> s1;
    set<ll> s2;
    vector<ll> v;
    for(ll i = 0; i < d; i++){
        s1.clear();
        s2.clear();
        v.clear();
        j = i;
        while(j < n){
            s1.insert(dup[j]);
            j += d;
        }
        j = i;
        while(j < n){
            s2.insert(input[j]);
            j += d;
        }

        if(s1 != s2){
            return -1;
        }

        j = i;
        while(j < n){
            v.pb((input[j]-i-1)/d + 1);
            j += d;
        }

        ans += inversions(v, 0, v.size()-1);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, n, d;
    cin >> t;
    while(t--){
        cin >> n >> d;
        ll *input = new ll[n];
        for(ll i = 0; i < n; i++) cin >> input[i];

        cout << solve(input, n, d) << endl;
    }
}
