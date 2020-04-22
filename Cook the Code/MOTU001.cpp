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

	ll t;
	cin >> t;
	while(t--){
		ll a, b, c;
		cin >> a >> b >> c;

		if(c%a == b){
			cout << c << endl;
		}
		else if(c - (c%a) + b <= c){
			cout << c - (c%a) + b << endl;
		}
		else{
			cout << c - (c%a) - a + b << endl;
		}
	}
	
}