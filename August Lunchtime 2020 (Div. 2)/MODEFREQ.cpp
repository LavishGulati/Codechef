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

		map<int, int> mp;
		int x;
		for(int i = 0; i < n; i++){
			cin >> x;
			mp[x]++;
		}

		int ans = -1, freq = 0;
		map<int, int> mp2;
		for(pii p : mp){
			mp2[p.s]++;
		}

		for(pii p : mp2){
			if(freq < p.s){
				freq = p.s;
				ans = p.f;
			}
		}

		cout << ans << endl;
	}
}