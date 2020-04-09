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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t, n, d, sum;
    cin >> t;
    while(t--){
        sum = 0;
        cin >> n >> d;
        ll *input = new ll[n];
        for(ll i = 0; i < n; i++){
            cin >> input[i];
            sum += input[i];
        }

        sort(input, input+n);
        vector<pll> v;
        ll count = 0, prev = input[0];
        for(ll i = 0; i < n; i++){
            if(input[i] == prev) count++;
            else{
                v.pb(mp(prev, count));
                prev = input[i];
                count = 1;
            }
        }
        v.pb(mp(prev, count));

        ll i = 0, j = v.size()-1, inc = 0, min, max, total = v[0].s;
        while(i < n-1){
            if(d > inc+total*(v[i+1].f-v[i].f)){
                inc += total*(v[i+1].f-v[i].f);
                total += v[i+1].s;
                i++;
            }
            else{
                min = v[i].f + (d-inc)/total;
                break;
            }
        }

        inc = 0, total = v[j].s;
        while(j > 0){
            if(d > inc+total*(v[j].f-v[j-1].f)){
                inc += total*(v[j].f-v[j-1].f);
                total += v[j-1].s;
                j--;
            }
            else{
                max = v[j].f - (d-inc)/total;
                break;
            }
        }

        if(i < j) cout << max-min << endl;
        else cout << 0 << endl;
    }
}
