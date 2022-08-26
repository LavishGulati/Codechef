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

const int MAX = 43;
const int MAXDP = (1<<(MAX/2))+10;

int t, n, m, a[MAX], FirstPartNeighbours[MAX];
ll dp[MAXDP], ans;
bool IsClique[MAXDP], mat[MAX][MAX];
umapii FactorsMap;
set<pii> FactorsSet;

void factorize(int x){
    for(int i = 2; i*i <= x; i++){
        while(x%i == 0){
            FactorsSet.erase(mp(i, FactorsMap[i]));
            FactorsMap[i]++;
            FactorsSet.insert(mp(i, FactorsMap[i]));
            if(FactorsMap[i] >= 3) return;
            x /= i;
        }
    }

    if(x > 1){
        FactorsSet.erase(mp(x, FactorsMap[x]));
        FactorsMap[x]++;
        FactorsSet.insert(mp(x, FactorsMap[x]));
    }
}

bool adjacent(int x, int y){
    FactorsMap.clear();
    FactorsSet.clear();
    factorize(x);
    factorize(y);
    for(auto i : FactorsSet){
        if(i.s >= 3) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];

        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                mat[i][j] = 0;
            }
        }

        for(int i = 0; i < MAX; i++){
            FirstPartNeighbours[i] = 0;
        }

        int half = n/2;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(adjacent(a[i], a[j])){
                    if(j < half){
                        FirstPartNeighbours[i] |= (1<<j);
                    }
                    if(i < half){
                        FirstPartNeighbours[j] |= (1<<i);
                    }
                    mat[i][j] = mat[j][i] = true;
                }
            }
        }

        IsClique[0] = true;
        for(int mask = 1; mask < (1<<half); mask++){
            int v = __builtin_ctz(mask);
            int mask2 = (mask ^ (1<<v));
            if(!IsClique[mask2]){
                IsClique[mask] = false;
                continue;
            }

            IsClique[mask] = true;
            for(int i = 0; i < half; i++){
                if((mask2 & (1<<i)) && !mat[v][i]){
                    IsClique[mask] = false;
                    break;
                }
            }
        }

        dp[0] = 1;
        for(int mask = 1; mask < (1<<(n-half)); mask++){
            int v = __builtin_ctz(mask);
            int mask2 = (mask ^ (1<<v));
            dp[mask] = dp[mask2];
            int mask3 = 0;
            for(int i = 0; i < n-half; i++){
                if(mat[v+half][i+half] && ((1<<i) & mask)){
                    mask3 |= (1<<i);
                }
            }
            dp[mask] += dp[mask3];
        }

        ans = 0;
        for(int mask = 0; mask < (1<<half); mask++){
            if(!IsClique[mask]) continue;
            int mask2 = 0;
            for(int i = half; i < n; i++){
                if((FirstPartNeighbours[i] & mask) == mask){
                    mask2 |= (1<<(i-half));
                }
            }
            ans += dp[mask2];
        }
        cout << ans << endl;
    }
}
