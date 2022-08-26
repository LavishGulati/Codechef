#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
typedef pair<long long, pair<long long, long long>> tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int *v = new int[n];
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}

		bool *vis = new bool[n];
		int small = INT_MAX, large = INT_MIN, change, minEl, maxEl, cur;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				vis[j] = false;
			}
			vis[i] = true;
			minEl = v[i];
			maxEl = v[i];
			cur = 1;
			while(1){
				change = 0;
				for(int j = i+1; j < n; j++){
					if(v[j] < maxEl && !vis[j]){
						change++;
						cur++;
						vis[j] = true;
						minEl = min(minEl, v[j]);
					}
				}
				for(int j = i-1; j >= 0; j--){
					if(v[j] > minEl && !vis[j]){
						change++;
						cur++;
						vis[j] = true;
						maxEl = max(maxEl, v[j]);
					}
				}
				if(!change){
					break;
				}
			}
			small = min(small, cur);
			large = max(large, cur);
		}

		cout << small << " " << large << endl;
	}
}