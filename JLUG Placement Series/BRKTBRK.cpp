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
		int s, w[3];
		cin >> s >> w[0] >> w[1] >> w[2];

		if(w[0]+w[1]+w[2] <= s){
			cout << 1 << endl;
		}
		else if(w[0]+w[1] <= s){
			cout << 2 << endl;
		}
		else if(w[1]+w[2] <= s){
			cout << 2 << endl;
		}
		else{
			cout << 3 << endl;
		}
	}
}