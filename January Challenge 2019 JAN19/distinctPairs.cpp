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

bool compare(pii a, pii b){
    return a.s < b.s;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, x;
    cin >> n >> m;
    pii A[n], B[m];
    for(int i = 0; i < n; i++){
        cin >> A[i].s;
        A[i].f = i;
    }
    for(int i = 0; i < m; i++){
        cin >> B[i].s;
        B[i].f = i;
    }

    sort(A, A+n, compare);
    sort(B, B+m, compare);
    for(int i = 0; i < m; i++){
        cout << A[0].f << " " << B[i].f << endl;
    }
    for(int i = 1; i < n; i++){
        cout << A[i].f << " " << B[m-1].f << endl;
    }
}
