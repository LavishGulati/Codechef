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

    ll numTest, n, t, x, y, z, a;
    cin >> numTest;
    while(numTest--){
        cin >> n >> t >> x >> y >> z;
        if(t == 1){
            if(y == x+1 && z == x+2){
                a = __gcd(2*n-y, 2*n+1);
                cout << (2*n-y)/a << " " << (2*n+1)/a << endl;
            }
            else if(y == x+1 && z == x){
                a = __gcd(y-1, 2*n+1);
                cout << (y-1)/a << " " << (2*n+1)/a << endl;
            }
            else if(y == x-1 && z == x){
                a = __gcd(y+1, 2*n+1);
                cout << (y+1)/a << " " << (2*n+1)/a << endl;
            }
            else if(y == x-1 && z == x-2){
                a = __gcd(2*n+2-y, 2*n+1);
                cout << (2*n+2-y)/a << " " << (2*n+1)/a << endl;
            }
        }
        else if(t == 2){
            if(y == x+1 && z == x+2){
                a = __gcd(2*n+1-2*y, 2*n+1);
                cout << (2*n+1-2*y)/a << " " << (2*n+1)/a << endl;
            }
            else if(y == x+1 && z == x){
                cout << 0 << " " << 1 << endl;
            }
            else if(y == x-1 && z == x){
                cout << 0 << " " << 1 << endl;
            }
            else if(y == x-1 && z == x-2){
                a = __gcd(2*n+1-2*y, 2*n+1);
                cout << (2*n+1-2*y)/a << " " << (2*n+1)/a << endl;
            }
        }
        else if(t == 3){
            if(y == x+1 && z == x+2){
                if(x == 0) cout << 1 << " " << 1 << endl;
                else{
                    a = __gcd(2*n+2-y, 2*n+1);
                    cout << (2*n+2-y)/a << " " << (2*n+1)/a << endl;
                }
            }
            else if(y == x+1 && z == x){
                a = __gcd(y-1, 2*n+1);
                cout << (y-1)/a << " " << (2*n+1)/a << endl;
            }
            else if(y == x-1 && z == x){
                a = __gcd(y+1, 2*n+1);
                cout << (y+1)/a << " " << (2*n+1)/a << endl;
            }
            else if(y == x-1 && z == x-2){
                a = __gcd(2*n-y, 2*n+1);
                cout << (2*n-y)/a << " " << (2*n+1)/a << endl;
            }
        }
        else if(t == 4){
            if(y == x+1 && z == x+2){
                a = __gcd(2*n+1-2*y, 2*n+1);
                cout << (2*n+1-2*y)/a << " " << (2*n+1)/a << endl;
            }
            else if(y == x+1 && z == x){
                cout << 0 << " " << 1 << endl;
            }
            else if(y == x-1 && z == x){
                cout << 0 << " " << 1 << endl;
            }
            else if(y == x-1 && z == x-2){
                a = __gcd(2*n+1-2*y, 2*n+1);
                cout << (2*n+1-2*y)/a << " " << (2*n+1)/a << endl;
            }
        }
    }
}
