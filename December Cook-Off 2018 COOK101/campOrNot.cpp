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

    int t;
    cin >> t;
    while(t--){
        int d[32];
        for(int i = 0; i < 32; i++) d[i] = 0;

        int D;
        cin >> D;
        int id, val;
        while(D--){
            cin >> id >> val;
            d[id] = val;
        }

        int cum[32];
        cum[0] = 0;
        for(int i = 1; i < 32; i++) cum[i] = cum[i-1]+d[i];

        int Q;
        cin >> Q;
        while(Q--){
            cin >> id >> val;
            if(cum[id] >= val) cout << "Go Camp" << endl;
            else cout << "Go Sleep" << endl;
        }
    }
}
