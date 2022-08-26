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

    int t, d;
    cin >> t;
    string s;
    while(t--){
        cin >> d >> s;
        bool helper[d];
        int AlreadyPresent = 0;
        for(int i = 0; i < d; i++) helper[i] = false;
        for(int i = 0; i < d; i++){
            if(s[i] == 'P'){
                AlreadyPresent++;
                helper[i] = true;
            }
            else if(i > 1 && i < d-2){
                if(s[i-1] == 'P' && s[i+1] == 'P') helper[i] = true;
                else if(s[i-2] == 'P' && s[i+2] == 'P') helper[i] = true;
                else if(s[i-2] == 'P' && s[i+1] =='P') helper[i] = true;
                else if(s[i-1] == 'P' && s[i+2] == 'P') helper[i] = true;
            }
        }

        double num = 0;
        for(int i = 0; i < d; i++){
            if(helper[i]) num++;
        }

        double attendance = num/double(d);
        if(attendance < 0.75) cout << -1 << endl;
        else cout << max(int(ceil(0.75*d))-AlreadyPresent, 0) << endl;
    }
}
