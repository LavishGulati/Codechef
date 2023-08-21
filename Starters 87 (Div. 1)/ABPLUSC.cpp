#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair< int, pair<int, int> > tii;
typedef pair< long long, pair<long long, long long> > tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		if (n == 1) {
			cout << -1 << endl;
			continue;
		} else if (n == 2) {
			cout << 1 << " " << 1 << " " << 1 << endl;
			continue;
		}

		ll a = min(n-1, 1000000LL);
		ll b = (n%a == 0 ? n/a - 1 : n/a);
		cout << a << " " << b << " " << n - a * b << endl;
	}
}