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

#define MAX 100000000

int maxDifference(vector<int> **graph, int id, int maxVal, int *wealth){
    int maxDiff = maxVal - wealth[id];
    for(int i = 0; i < graph[id]->size(); i++){
        int v = graph[id]->at(i);
        int val = maxDifference(graph, v, max(maxVal, wealth[id]), wealth);
        maxDiff = max(maxDiff, val);
    }
    return maxDiff;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int *wealth = new int[n];
    for(int i = 0; i < n; i++) cin >> wealth[i];

    vector<int> **graph = new vector<int> *[n];
    for(int i = 0; i < n; i++) graph[i] = new vector<int>;

    int parent, root;
    for(int i = 0; i < n; i++){
        cin >> parent;
        if(parent == -1) root = i;
        else graph[parent-1]->pb(i);
    }

    cout << maxDifference(graph, root, -MAX, wealth) << endl;
}
