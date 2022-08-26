#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
typedef pair<pair<long long, long long>, long long> tll;
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

	ll k;
	cin >> k;

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		priority_queue<pll, vector<pll>, greater<pll>> pq;
		string output(n, '.');
		pq.push({0, 0});
		pq.push({0, 1});
		pll p;
		for(ll i = n; i >= 1; i--){
			p = pq.top();
			pq.pop();
			p.f += pow(i, k);
			output[i-1] = '0'+p.s;
			pq.push(p);
		}
		p = pq.top();
		pq.pop();
		cout << pq.top().f-p.f << endl;
		cout << output << endl;
	}
}