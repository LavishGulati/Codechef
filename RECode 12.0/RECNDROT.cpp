#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pq priority_queue

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		map<int, set<int> > mymap;

		int id = 0;
		int x;
		for(int i = 0; i < n; i++){
			cin >> x;
			mymap[x].insert(i);
		}


		id = -1;
		int ans = 1;
		for(auto p : mymap){
			auto it = p.s.upper_bound(id);
			// cout << p.f << " " << p.s << endl;
			if(it != p.s.end() && *it > id){
				id = *it;
			}
			else{
				id = *p.s.begin();
				ans++;
			}
		}
		cout << ans << endl;
	}
}