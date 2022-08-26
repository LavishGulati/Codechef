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

int memo[200005][3];

int supw(int *input, int id, int n, int num){
    if(id == n) return 0;

    if(memo[id][num] != -1) return memo[id][num];

    if(num == 2){
        memo[id][num] = input[id]+supw(input, id+1, n, 0);
        return memo[id][num];
    }

    int x = input[id]+supw(input, id+1, n, 0);
    int y = supw(input, id+1, n, num+1);
    memo[id][num] = min(x, y);
    return memo[id][num];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for(int i = 0; i < 200005; i++){
        for(int j = 0; j < 3; j++) memo[i][j] = -1;
    }

    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    cout << supw(input, 0, n, 0) << endl;
}
