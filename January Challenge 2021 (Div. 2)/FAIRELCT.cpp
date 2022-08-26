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
		int n, m;
		cin >> n >> m;

		priority_queue<int, vector<int>, greater<int>> pq1;
		priority_queue<int> pq2;
		int a = 0, b = 0, x, y;
		for(int i = 0; i < n; i++){
			cin >> x;
			a += x;
			pq1.push(x);
		}
		for(int i = 0; i < m; i++){
			cin >> x;
			b += x;
			pq2.push(x);
		}

		int cnt = 0;
		while(a <= b && pq1.top() < pq2.top()){
			x = pq1.top();
			pq1.pop();
			y = pq2.top();
			pq2.pop();
			a += y-x;
			b -= y-x;
			pq1.push(y);
			pq2.push(x);
			cnt++;
		}

		if(a > b){
			cout << cnt << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
}