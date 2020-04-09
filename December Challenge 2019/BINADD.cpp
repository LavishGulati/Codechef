#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long, long> pll;

#define pb push_back
#define umap unordered_map
#define f first
#define s second

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, n, m;
	cin >> t;

	bool allZero = true;

	string a, b;
	while(t--){
		cin >> a >> b;

		n = a.length();
		m = b.length();
		for(int i = 0; i < m; i++){
			if(b[i] == '1'){
				allZero = false;
				break;
			}
		}

		if(allZero){
			cout << 0 << endl;
			continue;
		}

		string helper = "";
		for(int i = 0; i < abs(n-m); i++){
			helper += '0';
		}

		if(n < m){
			a = helper+a;
		}
		else{
			b = helper+b;
		}
		n = max(n, m);

		int answer = 0;
		int id = n-1;
		while(id >= 0){
			if(a[id] == '1' && b[id] == '1'){
				id--;
				int cnt = 1;
				while(id >= 0 && ((a[id] == '0' && b[id] == '1') || (a[id] == '1' || b[id] == '0'))){
					id--;
					cnt++;
				}
				answer = max(answer, cnt);
			}
			else{
				id--;
			}
		}

		cout << answer+1 << endl;
	}
}