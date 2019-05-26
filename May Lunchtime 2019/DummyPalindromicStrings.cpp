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

    int t;
    cin >> t;
    string s;
    int helper[26];
    while(t--){
        for(int i = 0; i < 26; i++){
            helper[i] = 0;
        }
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            helper[s[i]-'a']++;
        }

        int NumOdd = 0;
        for(int i = 0; i < 26; i++){
            if(helper[i]%2 == 1) NumOdd++;
        }

        if(s.length()%2 == 0){
            if(NumOdd > 2 || NumOdd == 0) cout << "!DPS" << endl;
            else cout << "DPS" << endl;
        }
        else{
            if(NumOdd > 3) cout << "!DPS" << endl;
            else cout << "DPS" << endl;
        }
    }
}
