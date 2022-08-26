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

ll modified_merge(ll *a, ll si, ll ei){
	if(si > ei){
		return 0;
	}
	else if(si == ei){
		if(a[si]%2){
			return 1;
		}
		else if(!(a[si]%2) && (a[si]%4)){
			return 0;
		}
		else{
			return 1;
		}
	}

	ll mid = (si+ei)/2;
	ll ans = 0;
	ans += modified_merge(a, si, mid);
	ans += modified_merge(a, mid+1, ei);

	ll i = mid;
	ll j = mid+1;
	while(i >= si){
		if(a[i]%4 == 0){
			break;
		}
		i--;
	}

	while(j <= ei){
		if(a[j]%4 == 0){
			break;
		}
		j++;
	}

	ll ik = mid;
	ll jk = mid+1;
	while(ik >= si){
		if(a[ik]%2 == 0){
			break;
		}
		ik--;
	}

	while(jk <= ei){
		if(a[jk]%2 == 0){
			break;
		}
		jk++;
	}

	ll il = ik-1;
	ll jl = jk+1;
	while(il >= si){
		if(a[il]%2 == 0){
			break;
		}
		il--;
	}

	while(jl <= ei){
		if(a[jl]%2 == 0){
			break;
		}
		jl++;
	}

	// ans += (mid-ik)*(jk-mid-1);
	// ans += (ik-i)*(j-jk);
	// ans += (i-si+1)*(ei-mid);
	// ans += (ei-j+1)*(mid-si+1);
	// ans -= (i-si+1)*(ei-j+1);

	ans += (ei-mid)*(mid-si+1);
	if(ik >= il && il >= i){
		ans -= (ik-il)*(jk-mid-1);
	}
	
	if(j >= jl && jl >= jk){
		ans -= (jl-jk)*(mid-ik);
	}

	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		ll *a = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}

		ll ans = modified_merge(a, 0, n-1);
		cout << ans << endl;
	}
}