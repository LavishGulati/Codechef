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

map<char, int> mymap;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	bool ans;
	while(t--){
		mymap.clear();
		
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		for(int i = 0; i < n; i++){
			mymap[s[i]]++;
		}

		ans = true;
		for(auto p : mymap){
			if((p.s)%2){
				ans = false;
				break;
			}
			else if(p.s/2 > k){
				ans = false;
				break;
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