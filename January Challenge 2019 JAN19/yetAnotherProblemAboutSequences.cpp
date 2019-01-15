#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

#define MAX 1000000LL
#define BOUND 1000000000LL

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	bool sieve[MAX];
	sieve[0] = false;
	sieve[1] = false;
	for(ll i = 2; i < MAX; i++) sieve[i] = true;

	for(ll i = 2; i < MAX; i++){
		if(sieve[i]){
			ll k = i;
			while(1){
				if(i*k > MAX) break;
				sieve[i*k] = false;
				k++;
			}
		}
	}

	vector<ll> prime;
	for(ll i = 0; i < MAX; i++){
		if(sieve[i]){
			if(prime.size() > 0 && i*prime[prime.size()-1] > BOUND){
				break;
			}
			prime.pb(i);
		}
	}

	ll m = 900;
	ll helper[m][m];
	for(ll j = 0; j < m; j++){
		for(ll i = j+1; i < m; i++) helper[i-1][j] = prime[i]*prime[j];
	}

	ll t, n;
	cin >> t;
	while(t--){
		cin >> n;
		ll k = n;

		if(n == 3){
			cout << "6 10 15" << endl;
			continue;
		}

		vector<ll> answer;
		ll i = 0;
		ll j = 0;
		ll direction = 3;
		while(k--){
			if(direction == 3){
				answer.pb(helper[i][j]);
				i++;
				direction = 2;
			}
			else if(direction == 2){
				if(i != m-1){
					answer.pb(helper[i][j]);
					j++;
					direction = 3;
				}
				else{
					answer.pb(helper[i][j]);
					j -= 2;
					direction = 1;
				}
			}
			else if(direction == 1){
				answer.pb(helper[i][j]);
				i--;
				direction = 4;
			}
			else if(direction == 4){
				if(i != 1){
					answer.pb(helper[i][j]);
					j--;
					direction = 1;
				}
				else{
					answer.pb(helper[i][j]);
					i -= 2;
					direction = 3;
				}
			}
		}

		answer[0] = 2*prime[900];
		answer[n-1] *= 2;

		for(ll i = 0; i < n; i++) cout << answer[i] << " ";
		cout << endl;
	}
}
