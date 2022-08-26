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

#define MAX 1005

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		vector< vector<int> > v(MAX);
		for(int i = 0; i < n; i++){
			v[a[i]].pb(i);
		}

		int ans = 0, num;
		for(int i = 1; i < MAX; i++){
			if(v[i].size() == 0){
				continue;
			}
			bool counted = true;
			int x = 1;
			for(int j = 1; j < v[i].size(); j++){
				if(v[i][j] == v[i][j-1]+1){
					if(counted){
						counted = false;
					}
					else{
						counted = true;
						x++;
					}
				}
				else{
					counted = true;
					x++;
				}
			}

			// cout << i << " " << x << endl;
			if(x > ans){
				num = i;
				ans = x;
			}
		}

		cout << num << endl;
	}
}