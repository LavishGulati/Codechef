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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string u;
		cin >> u;

		int num = 1;
		string s = "";
		for (int i = 1; i < n; i++) {
			if (u[i] == u[i-1]) {
				num++;
			} else {
				s += u[i-1];
				if (!(num%2)) {
					s += u[i-1];
				}
				num = 1;
			}
		}
		s += u[n-1];
		if (!(num%2)) {
			s += u[n-1];
		}
		cout << s << endl;
	}
}