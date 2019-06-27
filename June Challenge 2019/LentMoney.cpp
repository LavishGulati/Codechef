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

    ll t, n, k, x, a, answer;
    cin >> t;
    while(t--){
        cin >> n;
        ll input[n];
        for(ll i = 0; i < n; i++) cin >> input[i];
        cin >> k >> x;

        pll helper[n];
        for(ll i = 0; i < n; i++){
            helper[i] = mp((input[i]^x) - input[i], i);
        }
        sort(helper, helper+n);

        bool picked[n];
        for(ll i = 0; i < n; i++){
            picked[i] = false;
        }

        ll answer = 0;
        if(n == k){
            for(ll i = n-1; i >= 0; i--){
                answer += helper[i].f;
            }
            if(answer < 0) answer = 0;
        }
        else if(k%2 == 0){
            for(ll i = n-1; i >= 0; i -= 2){
                if(i-1 >= 0 && helper[i].f+helper[i-1].f > 0){
                    answer += helper[i].f+helper[i-1].f;
                }
                else break;
            }
        }
        else{
            for(ll i = n-1; i >= 0; i--){
                if(helper[i].f > 0){
                    answer += helper[i].f;
                }
                else break;
            }
        }

        for(ll i = 0; i < n; i++){
            answer += input[i];
        }
        cout << answer << endl;
    }
}
