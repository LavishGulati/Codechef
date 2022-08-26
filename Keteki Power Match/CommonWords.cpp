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
typedef vector<int> vi;

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
    int t, i, n, m;
    cin >> t;
    string a, b, c;
    getline(cin, c);
    bool answer;
    set<string> st;
    while(t--){
        st.clear();
        answer = false;

        getline(cin, a);
        getline(cin, b);

        n = a.length();
        m = b.length();

        c = "";
        for(i = 0; i < n; i++){
            if(a[i] == ' '){
                st.insert(c);
                c = "";
            }
            else c += a[i];
        }
        st.insert(c);

        c = "";
        for(i = 0; i < m; i++){
            if(b[i] == ' '){
                if(st.find(c) != st.end()){
                    answer = true;
                    break;
                }
                c = "";
            }
            else c += b[i];
        }
        if(st.find(c) != st.end()){
            answer = true;
        }

        if(answer) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
