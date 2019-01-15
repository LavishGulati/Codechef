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

int findV(int *V, int t, int n){
    int si = 0;
    int ei = n-1;
    int answer;
    while(si <= ei){
        int mid = (si+ei)/2;
        if(V[mid] <= t){
            answer = V[mid];
            si = mid+1;
        }
        else ei = mid-1;
    }

    return answer;
}

int findW(int *W, int t, int n){
    int si = 0;
    int ei = n-1;
    int answer;
    while(si <= ei){
        int mid = (si+ei)/2;
        if(W[mid] >= t){
            answer = W[mid];
            ei = mid-1;
        }
        else si = mid+1;
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, x, y;
    cin >> n >> x >> y;

    pii *contest = new pii[n];
    for(int i = 0; i < n; i++){
        cin >> contest[i].f >> contest[i].s;
    }

    int *V = new int[x];
    int *W = new int[y];
    for(int i = 0; i < x; i++) cin >> V[i];
    for(int i = 0; i < y; i++) cin >> W[i];

    sort(V, V+x);
    sort(W, W+y);

    int minTime = INT_MAX;
    for(int i = 0; i < n; i++){
        int startTime = contest[i].f;
        int endTime = contest[i].s;

        int v = findV(V, startTime, x);
        int w = findW(W, endTime, y);

        if(v <= startTime && w >= endTime){
            minTime = min(minTime, w-v+1);
        }
    }

    cout << minTime << endl;
}
