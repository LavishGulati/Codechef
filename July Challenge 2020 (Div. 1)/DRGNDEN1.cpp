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

	ll n, q;
	cin >> n >> q;

	ll *h = new ll[n];
	for(ll i = 0; i < n; i++){
		cin >> h[i];
	}

	ll *a = new ll[n];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}

	ll type, b, c;
	while(q--){
		cin >> type >> b >> c;
		if(type == 1){
			a[b-1] = c;
		}
		else{
			b--; c--;
			if(b != c && h[b] <= h[c]){
				cout << -1 << endl;
			}
			else{
				ll i = c, ans = a[c], id = c;
				if(b < c){
					while(i > b){
						i--;
						if(h[i] > h[id]){
							id = i;
							ans += a[id];
						}
					}
				}
				else{
					while(i < b){
						i++;
						if(h[i] > h[id]){
							id = i;
							ans += a[id];
						}
					}
				}
				if(id == b){
					cout << ans << endl;
				}
				else{
					cout << -1 << endl;
				}
			}
		}
	}
}