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

    ll t, a, b, l, r;
    cin >> t;
    while(t--){
        cin >> a >> b >> l >> r;

        if(r < l){
            swap(l, r);
        }

        ll sa = l%a == 0 ? l : (l/a+1)*a;
        ll sb = l%b == 0 ? l : (l/b+1)*b;
        ll ea = (r/a)*a;
        ll eb = (r/b)*b;

        ll na = (ea/a)-(sa/a)+1;
        ll suma = na*sa + (na*(na-1)*a)/2;

        ll nb = (eb/b)-(sb/b)+1;
        ll sumb = nb*sb + (nb*(nb-1)*b)/2;

        ll x = (a*b)/__gcd(a, b);
        ll sx = l%x == 0 ? l : (l/x+1)*x;
        ll ex = (r/x)*x;
        ll nx = (ex/x)-(sx/x)+1;
        ll sumx = (nx*sx) + (nx*(nx-1)*x)/2;

        ll answer = 0;
        if((suma+sumb-sumx)%2 == 0) answer++;
        if((suma+sumb)%3 == 0 || (suma+sumb)%2 == 0) answer++;

        // cout << suma << " " << sumb << " " << sumx << endl;

        if(answer == 2) cout << "TRUE LOVE" << endl;
        else if(answer == 1) cout << "LOVE" << endl;
        else cout << "FAKE LOVE" << endl;
    }
}
