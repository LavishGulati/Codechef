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
		ans = true;
		int n;
		cin >> n;

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		int last = -1;
		for(int i = 0; i < n; i++){
			if(a[i]){
				if(last == -1){
					last = i;
				}
				else if(i-last < 6){
					ans = false;
					break;	
				}
				else{
					last = i;
				}
			}
		}
		if(ans){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}