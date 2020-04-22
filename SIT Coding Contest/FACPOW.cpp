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

	ll t;
	scanf(" %lld", &t);
	while(t--){
		ll x, k;
		scanf(" %lld %lld", &x, &k);

		ll ans1 = 0, ans2 = 0;


		for(ll i = 1; i*i <= x; i++){
			if(x%i == 0){
				ans1 += pow(i, k);
				if(x/i != i){
					ans1 += pow(x/i, k);
				}
			}
		}
		ans1--;

		for(ll i = 1; i*i <= k; i++){
			if(k%i == 0){
				ans2 += x*i;
				if(k/i != i){
					ans2 += x*(k/i);
				}
			}
		}
		ans2 -= x;

		printf("%lld %lld\n", ans1, ans2);
	}
}