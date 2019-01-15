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

#define MAX 301
vector<int> input[MAX];

bool check(int ei, int ej, int k){
    int num = 0;
    int i = 0;
    int j = 0;
    while(i < input[ei].size() && j < input[ej].size()){
        if(input[ei][i] == input[ej][j]){
            num++;
            i++;
            j++;
        }
        else if(input[ei][i] < input[ej][j]) i++;
        else j++;

        if(num >= k) return true;
    }

    return false;
}

int bfs(bool **graph, int n){
    bool isVisited[n];
    for(int i = 0; i < n; i++) isVisited[i] = false;

    int num = 1;
    queue<int> q;
    q.push(0);
    isVisited[0] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v = 0; v < n; v++){
            if(graph[u][v] && !isVisited[v]){
                num++;
                q.push(v);
                isVisited[v] = true;
            }
        }
    }

    return num;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    int num, val;
    for(int i = 0; i < n; i++){
        cin >> num;
        while(num--){
            cin >> val;
            input[i].pb(val);
        }
    }

    for(int i = 0; i < n; i++) sort(all(input[i]));

    bool **graph = new bool *[n];
    for(int i = 0; i < n; i++){
        graph[i] = new bool[n];
        for(int j = 0; j < n; j++) graph[i][j] = false;
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(check(i, j, k)){
                graph[i][j] = true;
                graph[j][i] = true;
            }
        }
    }

    cout << bfs(graph, n) << endl;
}
