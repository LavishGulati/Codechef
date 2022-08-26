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
		string s;
		cin >> s;

		int n = s.length();

		string t = s[n-1]+s.substr(0, n-1);
		if(t[n-1]+t.substr(0, n-1) == s){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}