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

    map<char, ll> id;
    id['U'] = 0;
    id['L'] = 1;
    id['R'] = 2;
    id['D'] = 3;

    while(t--){
        cin >> n >> m;

        bool helper1[n][m][4];
        bool helper2[n][m][4];

        char grid[n][m];
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                for(ll k = 0; k < 4; k++){
                    helper1[i][j][k] = false;
                }
                cin >> grid[i][j];
                if(grid[i][j] == 'U' || grid[i][j] == 'D' || grid[i][j] == 'R' || grid[i][j] == 'L'){
                    helper1[i][j][id[grid[i][j]]] = true;
                }
            }
        }

        ll answer = 0, num;
        ll r = max(n, m);
        while(r--){
            for(ll i = 0; i < n; i++){
                for(ll j = 0; j < m; j++){
                    for(ll k = 0; k < 4; k++){
                        helper2[i][j][k] = helper1[i][j][k];
                        helper1[i][j][k] = false;
                    }
                }
            }

            for(ll i = 0; i < n; i++){
                for(ll j = 0; j < m; j++){
                    if(helper2[i][j][0]){
                        if(i-1 >= 0 && grid[i-1][j] != '#'){
                            helper1[i-1][j][0] = true;
                        }
                    }
                    if(helper2[i][j][1]){
                        if(j-1 >= 0 && grid[i][j-1] != '#'){
                            helper1[i][j-1][1] = true;
                        }
                    }
                    if(helper2[i][j][2]){
                        if(j+1 < m && grid[i][j+1] != '#'){
                            helper1[i][j+1][2] = true;
                        }
                    }
                    if(helper2[i][j][3]){
                        if(i+1 < n && grid[i+1][j] != '#'){
                            helper1[i+1][j][3] = true;
                        }
                    }
                }
            }

            for(ll i = 0; i < n; i++){
                for(ll j = 0; j < m; j++){
                    num = 0;
                    for(ll k = 0; k < 4; k++){
                        if(helper1[i][j][k]) num++;
                    }
                    answer += (num*(num-1))/2;
                }
            }

        }

        cout << answer << "\n";
    }
}
