#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

#define MAX 1000000
#define BOUND 1000000000

void print(vector<int> &v, int n){
	cout << v[0]*v[n-1] << " ";
	for(int i = 1; i < n; i++){
		cout << v[i]*v[i-1] << " ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bool sieve[MAX];
	sieve[0] = false;
	sieve[1] = false;
	for(int i = 2; i < MAX; i++) sieve[i] = true;
	for(int i = 2; i*i < MAX; i++){
		if(sieve[i]){
			for(int j = i*i; j < MAX; j += i) sieve[j] = false;
		}
	}

	vector<int> prime;
	for(int i = 2; i < MAX; i++){
		if(sieve[i]) prime.pb(i);
	}

	vector<int> odd;
	for(int i = 0; i < 5; i++){
		odd.pb(prime[i]);
	}
	for(int i = 5; i+1 < prime.size(); i += 2){
		odd.pb(3);
		odd.pb(prime[i]);
		odd.pb(5);
		odd.pb(prime[i+1]);
	}

	vector<int> even;
	for(int i = 0; i < 4; i++){
		even.pb(prime[i]);
	}
	for(int i = 4; i+1 < prime.size(); i += 2){
		even.pb(3);
		even.pb(prime[i]);
		even.pb(5);
		even.pb(prime[i+1]);
	}

	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		if(n < 3000){
			print(prime, n);
		}
		else if(n%2 == 0){
			print(even, n);
		}
		else{
			print(odd, n);
		}
	}
}
