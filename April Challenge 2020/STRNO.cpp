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
		ll x, k;
		cin >> x >> k;

		ll y = x;

		while(k > 0 && x%2 == 0){
			x /= 2;
			k--;
		}

		if(!k){
			cout << "1\n";
			continue;
		}

		for(ll i = 3; i*i <= y; i += 2){
			while(k > 0 && x%i == 0){
				x /= i;
				k--;
			}
			if(!k){
				cout << "1\n";
				break;
			}
		}

		if(!k){
			continue;
		}

		if(k > 0 && x >= 2){
			k--;
		}

		if(!k){
			cout << "1\n";
		}
		else{
			cout << "0\n";
		}
	}
}