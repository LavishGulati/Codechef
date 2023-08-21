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

vector<int> v1, v2, v3;
vector<int> output[3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		output[0].clear(); output[1].clear(); output[2].clear();

		v1.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> v1[i];
		}

		int ans = 0, m, temp;
		for (int i = 0; i < 32; i++) {
			v2.clear();
			v3.clear();
			for (int j = 0; j < n; j++) {
				if (v1[j]&(1<<i)) {
					v2.pb(v1[j]);
				} else {
					v3.pb(v1[j]);
				}
			}

			m = v2.size();
			for (int j = 0; j < m; j += 3) {
				if (j+2 < m) {
					ans++;
					output[0].pb(v2[j]);
					output[1].pb(v2[j+1]);
					output[2].pb(v2[j+2]);
					v3.pb(v2[j]^v2[j+1]);
					v3.pb(v2[j+1]^v2[j+2]);
					v3.pb(v2[j]^v2[j+2]);
				}
			}

			if (m%3 == 1) {
				ans++;
				output[0].pb(v2[m-1]);
				output[1].pb(v3[0]);
				output[2].pb(v3[1]);
				temp = v2[m-1];
				v2[m-1] = temp^v3[0];
				v2.pb(temp^v3[1]); m++;
				v3[1] = v3[0]^v3[1];
				for (int j = 1; j < v3.size(); j++) {
					v3[j-1] = v3[j];
				}
				v3.resize(v3.size()-1);
				goto TAG;
			} else if (m%3 == 2) {
				TAG:
				ans++;
				output[0].pb(v2[m-2]);
				output[1].pb(v3[0]);
				output[2].pb(v3[1]);
				temp = v2[m-2];
				v2[m-2] = temp^v3[0];
				v2.pb(temp^v3[1]); m++;
				v3[1] = v3[0]^v3[1];

				ans++;
				output[0].pb(v2[m-3]);
				output[1].pb(v2[m-2]);
				output[2].pb(v2[m-1]);
				v3[0] = v2[m-3]^v2[m-2];
				v3.pb(v2[m-2]^v2[m-1]);
				v3.pb(v2[m-3]^v2[m-1]);
			}

			v1 = v3;
		}

		cout << ans << endl;
		for (int i = 0; i < output[0].size(); i++) {
			cout << output[0][i] << " " << output[1][i] << " " << output[2][i] << endl;
		}
	}
}