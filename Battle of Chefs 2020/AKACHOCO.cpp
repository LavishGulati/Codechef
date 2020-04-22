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
	bool ans;

	while(t--){
		int n, x;
		cin >> n >> x;

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		sort(a, a+n);

		ans = true;

		int day = 1;
		for(int i = 0; i < n; i++){
			int j;
			for(j = 0; j < x && i+j < n; j++){
				if(a[i+j] <= day){
					ans = false;
					break;
				}
			}
			if(!ans){
				break;
			}

			day++;
			i += x;
		}

		if(ans){
			cout << "Possible" << endl;
		}
		else{
			cout << "Impossible" << endl;
		}
	}
}