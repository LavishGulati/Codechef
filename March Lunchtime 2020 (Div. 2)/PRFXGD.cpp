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
	while(t--){
		mymap.clear();
		string s;
		cin >> s;

		int k, x;
		cin >> k >> x;

		int n = s.length();

		// string output = "";

		int answer = 0;

		for(int i = 0; i < n; i++){
			mymap[s[i]]++;
			if(mymap[s[i]] > x){
				if(k > 0){
					// output += '0';
					k--;
				}
				else{
					// output += '.';
					break;
				}
			}
			else{
				// output += '1'
				answer++;
			}
		}
		cout << answer << endl;
	}
}