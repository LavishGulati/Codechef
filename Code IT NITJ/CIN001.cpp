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
		int a, b, c, r;
		cin >> a >> b >> c >> r;

		if(c+r >= max(a, b) && c-r <= min(a, b)){
			cout << int(0) << endl;
		}
		else if(c-r >= min(a, b) && c+r <= max(a, b)){
			cout << int(abs(a-b)-2*r) << endl;
		}
		else if(c-r >= max(a, b) || c+r <= min(a, b)){
			cout << int(abs(a-b)) << endl;
		}
		else if(c+r >= min(a, b) && c+r <= max(a, b)){
			cout << int(max(a, b)-c-r) << endl;
		}
		else if(c-r >= min(a, b) && c-r <= max(a, b)){
			cout << int(c-r-min(a,b)) << endl;
		}
	}
}