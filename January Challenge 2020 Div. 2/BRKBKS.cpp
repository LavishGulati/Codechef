#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, s, w1, w2, w3;
	cin >> t;
	while(t--){
		cin >> s >> w1 >> w2 >> w3;
		if(w1+w2+w3 <= s){
			cout << 1 << endl;
		}
		else if(w1+w2 <= s || w2+w3 <= s){
			cout << 2 << endl;
		}
		else{
			cout << 3 << endl;
		}
	}
}