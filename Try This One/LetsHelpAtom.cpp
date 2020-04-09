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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q, t, k;
    cin >> q;
    string s = "", w;
    stack<string> st;
    st.push(s);
    while(q--){
        cin >> t;
        if(t == 1){
            cin >> w;
            s += w;
            st.push(s);
        }
        else if(t == 2){
            cin >> k;
            s = s.substr(0, s.length()-k);
            st.push(s);
        }
        else if(t == 3){
            cin >> k;
            cout << s[k-1] << endl;
        }
        else{
            st.pop();
            s = st.top();
        }
    }
}
