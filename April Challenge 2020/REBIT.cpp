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

#define MOD 998244353

#define MAX 100005



ll power(ll x, ll n, ll mod){
	if(n == 0){
		return 1%mod;
	}
	else if(n == 1){
		return x%mod;
	}

	ll y = power(x, n/2, mod);
	if(n%2){
		return (((y*y)%mod)*x)%mod;
	}
	else{
		return (y*y)%mod;
	}
}

ll modInverse(ll x){
	return power(x, MOD-2, MOD);
}

ll solve(map<pll, ll> &memo, ll *mymap, string &s, ll si, ll ei, ll val){
// ll solve(map<pll, ll> &memo, ll *mymap, char *s, ll si, ll ei, ll val){
	if(memo.find(mp(si, val)) != memo.end()){
		return memo[mp(si, val)];
	}

	if(si > ei){
		return 0;
	}
	if(si == ei){
		return 1;
	}

	ll opid;
	if(s[si+1] == '('){
		opid = mymap[si+1]+1;
	}
	else{
		opid = si+2;
	}

	ll ans = 0, x;
	if(val == 0){
		if(s[opid] == '|'){

			x = solve(memo, mymap, s, si+1, opid-1, 0);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 0))%MOD;
			ans = (ans+x)%MOD;
		
		}
		else if(s[opid] == '^'){

			x = solve(memo, mymap, s, si+1, opid-1, 0);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 0))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 1);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 1))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 2);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 2))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 3);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 3))%MOD;
			ans = (ans+x)%MOD;

		}
		else{

			x = solve(memo, mymap, s, si+1, opid-1, 0);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 0))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 0);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 1))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 0);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 2))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 0);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 3))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 1);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 0))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 2);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 0))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 2);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 3))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 3);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 0))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 3);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 2))%MOD;
			ans = (ans+x)%MOD;

		}
	}
	else if(val == 1){
		if(s[opid] == '|'){

			x = solve(memo, mymap, s, si+1, opid-1, 0);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 1))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 1);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 0))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 1);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 1))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 1);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 2))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 1);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 3))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 2);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 1))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 2);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 3))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 3);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 1))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 3);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 2))%MOD;
			ans = (ans+x)%MOD;

		}
		else if(s[opid] == '^'){

			x = solve(memo, mymap, s, si+1, opid-1, 0);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 1))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 1);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 0))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 2);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 3))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 3);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 2))%MOD;
			ans = (ans+x)%MOD;

		}
		else{
			
			x = solve(memo, mymap, s, si+1, opid-1, 1);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 1))%MOD;
			ans = (ans+x)%MOD;

		}
	}
	else if(val == 2){
		if(s[opid] == '|'){

			x = solve(memo, mymap, s, si+1, opid-1, 0);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 2))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 2);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 0))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 2);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 2))%MOD;
			ans = (ans+x)%MOD;

		}
		else if(s[opid] == '^'){

			x = solve(memo, mymap, s, si+1, opid-1, 0);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 2))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 1);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 3))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 2);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 0))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 3);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 1))%MOD;
			ans = (ans+x)%MOD;

		}
		else{
			
			x = solve(memo, mymap, s, si+1, opid-1, 1);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 2))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 2);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 1))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 2);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 2))%MOD;
			ans = (ans+x)%MOD;

		}
	}
	else if(val == 3){
		if(s[opid] == '|'){

			x = solve(memo, mymap, s, si+1, opid-1, 0);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 3))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 3);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 0))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 3);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 3))%MOD;
			ans = (ans+x)%MOD;

		}
		else if(s[opid] == '^'){

			x = solve(memo, mymap, s, si+1, opid-1, 0);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 3))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 1);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 2))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 2);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 1))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 3);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 0))%MOD;
			ans = (ans+x)%MOD;

		}
		else{
		
			x = solve(memo, mymap, s, si+1, opid-1, 1);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 3))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 3);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 1))%MOD;
			ans = (ans+x)%MOD;

			x = solve(memo, mymap, s, si+1, opid-1, 3);
			x = (x*solve(memo, mymap, s, opid+1, ei-1, 3))%MOD;
			ans = (ans+x)%MOD;

		}
	}

	memo[mp(si, val)] = ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t, a, b, c, d, sum, ai, bi, ci, di;
	cin >> t;
	// scanf(" %lld", &t);
	string s;
	// char *s = new char[MAX];
	stack<ll> mystack;

	while(t--){
		map<pll, ll> memo;
		cin >> s;
		// scanf(" %s", s);

		ll *mymap = new ll[s.length()];
		// ll *mymap = new ll[strlen(s)];

		stack<ll> mystack;

		for(ll i = 0; i < s.length(); i++){
		// for(ll i = 0; i < strlen(s); i++){
			if(s[i] == '('){
				mystack.push(i);
			}
			else if(s[i] == ')'){
				mymap[mystack.top()] = i;
				mystack.pop();
			}
		}

		a = solve(memo, mymap, s, 0, s.length()-1, 0);
		b = solve(memo, mymap, s, 0, s.length()-1, 1);
		c = solve(memo, mymap, s, 0, s.length()-1, 2);
		d = solve(memo, mymap, s, 0, s.length()-1, 3);

		// a = solve(memo, mymap, s, 0, strlen(s)-1, 0);
		// b = solve(memo, mymap, s, 0, strlen(s)-1, 1);
		// c = solve(memo, mymap, s, 0, strlen(s)-1, 2);
		// d = solve(memo, mymap, s, 0, strlen(s)-1, 3);

		sum = (a+b)%MOD;
		sum = (sum+c)%MOD;
		sum = (sum+d)%MOD;
		sum = modInverse(sum)%MOD;
		ai = (a*sum)%MOD;
		bi = (b*sum)%MOD;
		ci = (c*sum)%MOD;
		di = (d*sum)%MOD;

		cout << ai << " " << bi << " " << ci << " " << di << endl;
		// printf("%lld %lld %lld %lld\n", ai, bi, ci, di);
	}
}