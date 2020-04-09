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
		int r, c;
		cin >> r >> c;

		int count = 0;
		vector<pii> output;

		while(r < c){
			r++; c--;
			count++;
			output.pb(mp(r, c));
		}

		while(c < r){
			c++; r--;
			count++;
			output.pb(mp(r, c));
		}

		while(r != 1){
			r--; c--;
			count++;
			output.pb(mp(r, c));
		}

		while(r != 8){
			r++; c++;
			count++;
			output.pb(mp(r, c));

			while(r != 1 && c != 8){
				r--; c++;
				count++;
				output.pb(mp(r, c));
			}

			while(r != c){
				r++; c--;
				count++;
				output.pb(mp(r, c));
			}

			while(c != 1 && r != 8){
				r++; c--;
				count++;
				output.pb(mp(r, c));
			}

			while(r != c){
				r--; c++;
				count++;
				output.pb(mp(r, c));
			}
		}

		cout << count << endl;
		for(int i = 0; i < count; i++){
			cout << output[i].f << " " << output[i].s << endl;
		}
	}
}