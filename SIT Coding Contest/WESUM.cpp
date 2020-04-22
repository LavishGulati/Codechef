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
		vector<ll> a;
		ll x, cnt = 0;
		while(1){
			cin >> x;
			if(x == -1){
				break;
			}

			if(x > 30){
				cnt++;
			}

			a.pb(x);
		}

		ll sum = 0, num = 0;
		for(ll i = 0; i < a.size(); i++){
			if(!(a[i]%2)){
				sum += a[i]*(i+1);
				num += i+1;
			}
		}

		double ans = sum/double(num);
		printf("%lld %.2lf\n", cnt, ans);
	}
}