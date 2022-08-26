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
#define s second
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, h;
    cin >> n >> h;

    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    int command;
    bool isBox = false;
    int id = 0;
    while(1){
        cin >> command;
        if(command == 0) break;

        if(command == 1 && id > 0) id--;
        else if(command == 2 && id <= n-2) id++;
        else if(command == 3 && input[id] > 0 && !isBox){
            isBox = true;
            input[id]--;
        }
        else if(command == 4 && input[id] < h && isBox){
            isBox = false;
            input[id]++;
        }
    }

    for(int i = 0; i < n; i++) cout << input[i] << " ";
    cout << endl;
}
