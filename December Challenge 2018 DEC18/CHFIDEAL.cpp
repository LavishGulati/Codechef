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
#define f first
#define s second
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    bool isOpened[3];
    for(int i = 0; i < 3; i++) isOpened[i] = false;
    srand(time(0));
    int x = rand()%3 + 1;
    isOpened[x-1] = true;
    cout << x << endl;

    int y;
    cin >> y;
    isOpened[y-1] = true;

    for(int i = 0; i < 3; i++){
        if(!isOpened[i]) cout << i+1 << endl;
    }
}
