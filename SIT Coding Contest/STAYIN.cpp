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

#define MAX 1000005

ll *sieve(ll n){ 

    ll *prime = new ll[n+1]; 
    memset(prime, 0, sizeof(prime)); 
  
    for (ll p=2; p<=n; p++){ 
        if (!prime[p]){
        	prime[p] = p; 
            for (ll i=p*p; i<=n; i += p){
            	if(!prime[i]){
            		prime[i] = p;
            	} 
            }
        } 
    } 
  
  	return prime;
    // vector<ll> output;

    // for (ll p=2; p<=n; p++){
    // 	if (prime[p] == p){
    // 		output.pb(p);
    // 	}
    // }

    // return output; 
}

ll secondLargestFactor(ll n, ll *prime){
	map<ll, ll> mymap;
	while(n > 1){
		mymap[prime[n]]++;
		n /= prime[n];
	}

	auto p1 = mymap.begin();
	auto p2 = ++p1;
	p1--;
	if(p1->s == 1){
		return p2->f;
	}
	else if(p1->f*p1->f < p2->f){
		return p1->f*p1->f;
	}
	else{
		return p2->f;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll *prime = sieve(MAX);

	ll t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		ll n = stoll(s);

		ll x = secondLargestFactor(n, prime);

		ll maxDigit = '0', y = -1;
		for(ll i = 0; i < s.length(); i++){
			if(s[i] >= maxDigit){
				maxDigit = s[i];
				y = i;
			}
			if(!((s[i]-'0')%2)){
				s[i]++;
			}
		}

		y = s.length()-y;

		cout << x  << " " << y << " " << s << endl;
	}
}