#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
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

#define MAX 100000000000000

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, d;
		cin >> n >> d;

		ll *c = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> c[i];
		}
		sort(c, c+n);

		double si = 0, ei = MAX, mid, ans = 0, last;
		ll it = 300, num = 0;
		bool poss;
		while(num < it){
			mid = (si+ei)/2;
			poss = true;
			last = c[0];
			for(ll i = 1; i < n; i++){
				if(c[i]+d < last+mid){
					poss = false;
					break;
				}
				last = max(last+mid, double(c[i]));
			}

			if(!poss){
				ei = mid;
			}
			else{
				ans = mid;
				si = mid;
			}
			num++;
		}
		cout << ans << endl;
	}
}