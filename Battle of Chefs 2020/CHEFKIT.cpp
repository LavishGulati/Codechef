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

#define MAX 3000005

ll a[MAX], d[MAX];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll m, v;
	cin >> m >> v;

	for(ll i = 0; i < MAX; i++){
		a[i] = d[i] = 0;
	}

	ll day, num;
	for(ll i = 0; i < m; i++){
		cin >> day >> num;
		a[day] += num;
	}

	ll ans = 0;

	ll lm;
	for(ll i = 1; i <= 3001; i++){
		lm = v;
		if(d[i]){
			num = min(lm, d[i]);
			d[i] = 0;
			ans += num;
			lm -= num;
		}

		num = min(lm, a[i]);
		a[i] -= num;
		d[i+1] += a[i];
		ans += num;
	}

	cout << ans << endl;
}
