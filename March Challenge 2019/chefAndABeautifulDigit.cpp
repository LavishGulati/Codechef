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

string shiftLeft(string s, int id, int k){
    string output = s;
    for(int i = id+k; i < s.length(); i++){
        output[i-k] = s[i];
    }
    return output;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        char d;
        cin >> d;

        // char smallestDigitId = 0;
        for(int i = 0; i < s.length(); i++){
            // if(s[i] < s[smallestDigitId]) smallestDigitId = i;
            if(s[i] > d){
                s = shiftLeft(s, i, 1);
                s[s.length()-1] = d;
                i--;
            }
        }

        // cout << s << endl;

        for(int i = 0; i < s.length(); i++){
            int smallestDigitId = i;
            for(int j = i; j < s.length(); j++){
                if(s[j] < s[smallestDigitId]) smallestDigitId = j;
            }
            s = shiftLeft(s, i, smallestDigitId-i);
            // cout << s << " ";
            for(int j = 0; j < smallestDigitId-i; j++){
                s[s.length()-1-j] = d;
            }

            // cout << s << endl;
        }

        cout << s << endl;
    }
}
