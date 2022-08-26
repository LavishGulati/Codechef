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

ll **matmul(ll **mat1, ll **mat2, ll mod){
	ll **res = new ll *[2];
	res[0] = new ll[2];
	res[1] = new ll[2];
	
	res[0][0] = ( (mat1[0][0]*mat2[0][0])%mod + (mat1[0][1]*mat2[1][0])%mod )%mod;
	res[0][1] = ( (mat1[0][0]*mat2[0][1])%mod + (mat1[0][1]*mat2[1][1])%mod )%mod;
	res[1][0] = ( (mat1[1][0]*mat2[0][0])%mod + (mat1[1][1]*mat2[1][0])%mod )%mod;
	res[1][1] = ( (mat1[1][0]*mat2[0][1])%mod + (mat1[1][1]*mat2[1][1])%mod )%mod;

	return res;
}

ll **matpower(ll **mat, ll n, ll mod){
	if(n == 0){
		ll **id = new ll *[n];
		id[0] = new ll[2];
		id[1] = new ll[2];
		id[0][0] = 1; id[0][1] = 0; id[1][0] = 0; id[1][1] = 1;
		return id; 
	}
	else if(n == 1){
		return mat;
	}

	ll **res = new ll *[2];
	res[0] = new ll[2];
	res[1] = new ll[2];
	res = matpower(mat, n/2, mod);
	if(n%2){
		// n is odd
		res = matmul(res, res, mod);
		res = matmul(res, mat, mod);
	}
	else{
		// n is even
		res = matmul(res, res, mod);
	}

	return res;
}

ll solve(ll n){
	if(n == 1){
		return 2;
	}

	ll **mat = new ll *[2];
	mat[0] = new ll[2];
	mat[1] = new ll[2];
	mat[0][0] = 2; mat[0][1] = 2; mat[1][0] = 1; mat[1][1] = 0;
	
	mat = matpower(mat, n-1, MOD);
	return (2*mat[0][0]+mat[0][1])%MOD;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		cout << solve(n) << endl;
	}
}