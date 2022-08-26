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

    ll t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        ll *C = new ll[m];
        for(ll i = 0; i < m; i++) cin >> C[i];

        ll *D = new ll[n];
        ll *F = new ll[n];
        ll *B = new ll[n];
        for(ll i = 0; i < n; i++){
            cin >> D[i] >> F[i] >> B[i];
            D[i]--;
        }

        ll reqd[m];
        for(ll i = 0; i < m; i++) reqd[i] = 0;
        for(ll i = 0; i < n; i++){
            reqd[D[i]]++;
        }

        queue<pll> q;
        for(ll i = 0; i < m; i++){
            if(C[i]-reqd[i] > 0) q.push(mp(i, C[i]-reqd[i]));
        }

        ll answer = 0;
        ll output[n];
        pll x;
        for(ll i = 0; i < n; i++){
            if(C[D[i]] > 0){
                answer += F[i];
                output[i] = D[i]+1;
                C[D[i]]--;
            }
            else{
                answer += B[i];
                x = q.front();
                q.pop();
                output[i] = x.f + 1;
                C[x.f]--;
                x.s--;
                if(x.s > 0){
                    q.push(x);
                }
            }
        }

        cout << answer << endl;
        for(ll i = 0; i < n; i++){
            cout << output[i] << " ";
        }
        cout << endl;
    }
}
