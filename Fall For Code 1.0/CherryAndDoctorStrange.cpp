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

    ll t, n, x;
    cin >> t;
    priority_queue<ll> pq;
    while(t--){
        while(!pq.empty()) pq.pop();

        cin >> n;
        for(ll i = 0; i < n; i++){
            cin >> x;
            pq.push(x);
        }

        ll score[2] = {0, 0};
        ll id = 0;
        while(!pq.empty()){
            x = pq.top();
            pq.pop();
            if(x == 0) break;

            if(!pq.empty() && pq.top() == x){
                while(!pq.empty() && pq.top() == x) pq.pop();
            }
            else{
                score[id] += x;
                pq.push(x/2);
            }

            id ^= 1;
        }

        if(score[0] > score[1]) cout << "Cherry " << score[0]-score[1] << endl;
        else cout << "Hazardous" << endl;
    }
}
