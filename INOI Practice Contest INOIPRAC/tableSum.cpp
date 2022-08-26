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

    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    for(int i = 0; i < n; i++){
        input[i] += i+1;
        if(i > 0) input[i] = max(input[i], input[i-1]);
    }

    cout << input[n-1] << " ";
    int count = 0;
    for(int i = n-1; i > 0; i--){
        input[i] -= n;
        if(i < n-1) input[i] = max(input[i], input[i+1])+1;
        else input[i]++;
        count++;
        input[i-1] += count;
        cout << max(input[i], input[i-1]) << " ";
    }
    cout << endl;
}
