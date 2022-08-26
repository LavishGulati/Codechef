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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, n, x;
    cin >> t;
    while(t--){
        cin >> n;

        set<ll> st;
        for(ll i = 0; i < n; i++){
            cin >> x;
            st.insert(x);
        }

        vector<ll> helper;
        for(auto i = st.begin(); i != st.end(); i++){
            helper.pb(*i);
        }
        n = helper.size();
        if(n == 1){
            cout << 2*helper[0] << endl;
            continue;
        }

        ll gcds[n];
        gcds[0] = helper[0];
        for(ll i = 1; i < n; i++){
            gcds[i] = __gcd(gcds[i-1], helper[i]);
        }

        ll gcde[n];
        gcde[n-1] = helper[n-1];
        for(ll i = n-2; i >= 0; i--){
            gcde[i] = __gcd(gcde[i+1], helper[i]);
        }

        ll answer = 0;
        for(ll i = 0; i < n; i++){
            if(i == 0){
                answer = max(answer, helper[0]+gcde[1]);
            }
            else if(i == n-1){
                answer = max(answer, helper[n-1]+gcds[i-1]);
            }
            else{
                answer = max(answer, __gcd(gcds[i-1], gcde[i+1])+helper[i]);
            }
        }
        cout << answer << endl;
    }
}
