#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
set_t;


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

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        int *input = new int[n];
        for(int i = 0; i < n; i++){
            cin >> input[i];
        }

        int total = 0;

        for(int i = 0; i < n; i++){
            map<int, int> mp;
            set_t s;
            for(int j = i; j < n; j++){
                mp[input[j]]++;
                s.insert(input[j]);
                int l = j-i+1;
                int m = ceil((double(k))/(double(l)));
                int id = ceil((double(k))/(double(m)));

                int x = *s.find_by_order(id-1);  // id-th smallest element in subarray A[i..j]

                int f = mp[x];
                if(mp[f] != mp.end()){
                    // cout << i << " " << j << " " << id << " " << x << endl;
                    total++;
                }
            }
        }

        cout << total << endl;
    }
}
