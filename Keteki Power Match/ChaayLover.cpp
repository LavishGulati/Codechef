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

    ll q, t, m, s, p;
    ll nt, nm, ns, np;
    ll pt, pm, ps, pp, r;
    ll si, ei, mid, answer, total;
    cin >> q;
    while(q--){
        cin >> t >> m >> s >> p;
        cin >> nt >> nm >> ns >> np;
        cin >> pt >> pm >> ps >> pp >> r;
        si = 0;
        ei = r + max(t, max(m, max(s, p)));
        answer = 0;
        while(si <= ei){
            mid = (si+ei)/2;
            total = (mid*t-nt)*pt;
            total += (mid*m-nm)*pm;
            total += (mid*s-ns)*ps;
            total += (mid*p-np)*pp;
            if(total <= r){
                answer = mid;
                si = mid+1;
            }
            else ei = mid-1;
        }

        cout << answer << endl;
    }
}
