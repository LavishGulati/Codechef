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

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		if((n*(n+1))%4 != 0){
			cout << 0 << endl;
			continue;
		}

		ll target = (n*(n+1))/4;
		ll si = 1, ei = n, mid, ans = -1;
		while(si <= ei){
			mid = (si+ei)/2;
			if((mid*(mid+1))/2 >= target - (n-1)){
				ans = mid;
				ei = mid-1;
			}
			else{
				si = mid+1;
			}
		}

		if(ans == -1){
			cout << 0 << endl;
			continue;
		}

		ll output = 0, diff, l, r;
		while((ans*(ans+1))/2 <= target){
			if(ans*(ans+1)/2 == target){
				output += (ans*(ans-1))/2;
				output += ((n-ans)*(n-ans-1))/2;
			}
			else{
				diff = target - (ans*(ans+1))/2;
				l = max(diff+1, ans+1);
				r = min(n, ans+diff);
				output += max(0LL, r-l+1);
			}
			ans++;
		}
		cout << output << endl;
	}
}