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

void ModifiedBubbleSort(int *input, int n){
    bool IsComplete;
    int temp;
    while(1){
        IsComplete = true;
        for(int i = 0; i < n-2; i++){
            if(input[i] > input[i+2]){
                temp = input[i];
                input[i] = input[i+2];
                input[i+2] = temp;
                IsComplete = false;
            }
        }
        if(IsComplete) break;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    ModifiedBubbleSort(input, n);
    int id = 0;
    while(id < n-1){
        if(input[id] > input[id+1]){
            cout << id << endl;
            break;
        }
        id++;
    }

    if(id == n-1) cout << "OK" << endl;
}
