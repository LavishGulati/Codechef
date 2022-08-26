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
		string a, b;
		cin >> a >> b;

		int maxAns = stoi(a)+stoi(b);
		for(int i = 0; i < a.length(); i++){
			for(int j = 0; j < b.length(); j++){
				swap(a[i], b[j]);
				maxAns = max(maxAns, stoi(a)+stoi(b));
				swap(a[i], b[j]);
			}
		}

		cout << maxAns << endl;
	}
}