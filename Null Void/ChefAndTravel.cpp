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

    ll t, n, h, x;
    cin >> t;
    while(t--){
        cin >> n >> h;
        if(n%2 == 0){
            x = n - (n-2)/2;
            cout << ((x-1)*(x))%MOD << endl;
        }
        else{
            if((n/2)%2 == 0){
                x = (n/2)-1;
                cout << (x*(x+1) + 3*x + 4)%MOD << endl;
            }
            else{
                x = (n/2);
                cout << (x*(x+1) + x + 1)%MOD << endl;
            }
        }
    }
}
