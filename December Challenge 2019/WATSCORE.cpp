#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int *arr = new int[12];
		for(int i = 0; i <= 11; i++){
			arr[i] = 0;
		}

		int u, v;
		for(int i = 0; i < n; i++){
			cin >> u >> v;
			arr[u] = max(arr[u], v);
		}

		int total = 0;
		for(int i = 1; i <= 8; i++){
			total += arr[i];
		}
		cout << total << endl;
	}
}