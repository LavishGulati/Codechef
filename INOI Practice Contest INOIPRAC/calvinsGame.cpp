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

    int n, k;
    cin >> n >> k;
    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    int *dp = new int[n];
    dp[k-1] = 0;
    if(k < n) dp[k] = input[k];
    for(int i = k+1; i < n; i++){
        dp[i] = max(dp[i-1], dp[i-2])+input[i];
    }

    if(n-2 >= 0){
        if(n-2 >= k-1) dp[n-2] = max(dp[n-2], dp[n-1]+input[n-2]);
        else dp[n-2] = dp[n-1]+input[n-2];
    }

    for(int i = n-3; i >= 0; i--){
        if(i >= k-1){
            dp[i] = max(dp[i], max(dp[i+1]+input[i], dp[i+2]+input[i]));
        }
        else{
            dp[i] = max(dp[i+1], dp[i+2])+input[i];
        }
    }

    cout << dp[0] << endl;
}
