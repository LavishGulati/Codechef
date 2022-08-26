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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    pii helper[26];
    int t;
    cin >> t;
    string s;
    while(t--){
        for(int i = 0; i < 26; i++){
            helper[i].f = INT_MAX;
            helper[i].s = INT_MIN;
        }
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            helper[s[i]-'a'].f = min(i, helper[s[i]-'a'].f);
            helper[s[i]-'a'].s = max(i, helper[s[i]-'a'].s);
        }

        int maxDistance = 0;
        for(int i = 0; i < 26; i++){
            maxDistance = max(abs(helper[i].f-helper[25-i].s), maxDistance);
            maxDistance = max(abs(helper[i].s-helper[25-i].f), maxDistance);
        }

        cout << maxDistance << endl;
    }
}
