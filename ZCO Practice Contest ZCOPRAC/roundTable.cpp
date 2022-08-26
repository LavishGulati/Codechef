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

int memo[1000005][2][2];

int roundTable(int *input, int id, int n, int isAdj, int isFirst){
    if(id == n) return 0;

    if(memo[id][isAdj][isFirst] != -1) return memo[id][isAdj][isFirst];

    if(isAdj == 0){
        memo[id][isAdj][isFirst] = input[id]+roundTable(input, id+1, n, 1, isFirst);
        return memo[id][isAdj][isFirst];
    }

    if(id == n-1 && isFirst == 0){
        memo[id][isAdj][isFirst] = input[id]+roundTable(input, id+1, n, 1, isFirst);
        return memo[id][isAdj][isFirst];
    }

    int x = input[id]+roundTable(input, id+1, n, 1, isFirst);
    int y = roundTable(input, id+1, n, 0, isFirst);
    memo[id][isAdj][isFirst] = min(x, y);
    return memo[id][isAdj][isFirst];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i = 0; i < 1000005; i++){
        for(int j = 0; j < 2; j++){
            memo[i][j][0] = -1;
            memo[i][j][1] = -1;
        }
    }

    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    int x = input[0]+roundTable(input, 1, n, 1, 1);
    int y = roundTable(input, 1, n, 0, 0);
    cout << min(x,y) << endl;
}
