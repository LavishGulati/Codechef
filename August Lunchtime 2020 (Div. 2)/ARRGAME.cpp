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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		bool *a = new bool[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		priority_queue<int, vector<int>, greater<int>> pq;
		int len = 0, sum = 0;
		for(int i = 0; i < n; i++){
			if(a[i]){
				if(len > 0){
					if(pq.size() < 2){
						pq.push(len);
					}
					else if(pq.top() < len){
						pq.pop();
						pq.push(len);
					}
					sum += len;
				}
				len = 0;
			}
			else{
				len++;
			}
		}

		if(pq.empty()){
			cout << "No" << endl;
			continue;
		}

		int smax = pq.top();
		pq.pop();
		int max;
		if(!pq.empty()){
			max = pq.top();
		}
		else{
			max = smax;
			smax = -1;
		}

		// cout << max << " " << smax << endl;

		if(sum == 1){
			cout << "Yes" << endl;
		}
		else if(max <= 2){
			cout << "No" << endl;
		}
		else if(max%2){
			if(smax >= (max+1)/2){
				cout << "No" << endl;
			}
			else{
				cout << "Yes" << endl;
			}
		}
		else{
			cout << "No" << endl;
		}
	}
}