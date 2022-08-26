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
// #define s second
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s = "";
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x == 1) s += '(';
        else if(x == 2) s += ')';
    }

    stack<char> st;

    int maxNesting = 0;
    int nestingPos = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(') st.push('(');
        else st.pop();

        if(st.size() > maxNesting){
            maxNesting = st.size();
            nestingPos = i;
        }
    }

    while(!st.empty()) st.pop();

    int maxLength = 0;
    int lengthPos = 0;
    int id = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            if(st.empty()) id = i;
            st.push('(');
        }
        else{
            st.pop();
            if(st.empty()){
                if(i-id+1 > maxLength){
                    maxLength = i-id+1;
                    lengthPos = id;
                }
            }
        }
    }

    cout << maxNesting << " " << nestingPos+1 << " " << maxLength << " " << lengthPos+1 << endl;
}
