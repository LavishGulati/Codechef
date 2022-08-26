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

    int t, n, i;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        n = s.length();
        i = n-1;
        if(n == 1){
            cout << s << endl;
            continue;
        }

        bool IsZero = true;
        bool IsIntermediateZero = true;
        bool AllNines = true;
        for(int i = 1; i < n; i++){
            if(s[i] != '0'){
                IsZero = false;
                break;
            }
        }
        for(int i = 1; i < n-1; i++){
            if(s[i] != '0'){
                IsIntermediateZero = false;
                break;
            }
        }
        for(int i = 1; i < n; i++){
            if(s[i] != '9') AllNines = false;
        }

        if(s[0] == '1' && IsZero){
            s[0] = '0';
            for(int i = 1; i < n; i++) s[i] = '9';
        }
        else if(s[0] == '1' && IsIntermediateZero){

        }
        else if(AllNines){

        }
        else if(s[0] == '1'){
            bool DoNine = false;
            int j = n-1;
            while(s[j] == '9') j--;
            for(int i = 1; i <= j; i++){
                if(DoNine){
                    s[i] = '9';
                }
                else if(i < j && s[i] != '0'){
                    s[i]--;
                    DoNine = true;
                }
            }
        }
        else{
            s[0]--;
            for(int i = 1; i < n; i++){
                s[i] = '9';
            }
        }

        i = 0;
        while(s[i] == '0'){
            s = s.substr(1);
        }
        // while(1){
        //     i = s.length()-1;
        //     if(s[i] != '0') break;
        //     else{
        //         s = s.substr(0, s.length()-1);
        //     }
        // }
        cout << s << endl;
    }
}
