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

#define MAX 1e12+5

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, x;
	cin >> n;

	for(ll i = 0; i < n; i++){
		cin >> x;

		double a = sqrt(x);
		ll b = floor(a);
		if(a-b == 0 && x > 1){
			bool isPrime = true;
			for(ll j = 2; j*j <= a; j++){
				if(b%j == 0){
					isPrime = false;
					break;
				}
			}
			if(isPrime){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
		else{
			cout << "NO\n";
		}
	}
}