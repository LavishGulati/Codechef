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

    int n, c, isBroken;
    cin >> n >> c;

    int ans;
    for(ans = 1; ans+512 < n; ans += 512){
        cout << "1 " << ans+512 << endl;
        cin >> isBroken;
        if(isBroken == 1){
            cout << "2" << endl;
            break;
        }
    }

    for(; ans+32 < n; ans += 32){
        cout << "1 " << ans+32 << endl;
        cin >> isBroken;
        if(isBroken == 1){
            cout << "2" << endl;
            break;
        }
    }

    for(; ; ans++){
        cout << "1 " << ans << endl;
        cin >> isBroken;
        if(isBroken == 1){
            cout << "2" << endl;
            cout << "3 " << ans << endl;
            break;
        }
    }
}
