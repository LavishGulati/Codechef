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

    string s;
    getline(cin, s);

    int n = s.length();
    int len = n;
    for(int i = 0; i < n; i++){
        if(s[i] == ' ') len--;
    }

    int r, c;
    int a, b;
    a = floor(sqrt(len));
    b = ceil(sqrt(len));
    if(a*a >= len){
        r = a;
        c = a;
    }
    else if(a*b >= len){
        r = a;
        c = b;
    }
    else{
        r = b;
        c = b;
    }

    vector<string> output(c);
    for(int i = 0; i < c; i++) output[i] = "";
    int id = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == ' ') continue;

        output[id] += s[i];
        id = (id+1)%c;
    }

    for(int i = 0; i < c; i++) cout << output[i] << " ";
    cout << endl;
}
