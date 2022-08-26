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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;

		ll help = 1, ans = 0;
		for(ll i = s.length()-1; i >= 0; i--){
			if(s[i] >= '0' && s[i] <= '9'){
				ans += help*(s[i]-'0');
			}
			else if(s[i] >= 'A' && s[i] <= 'F'){
				ans += help*(s[i]-'A'+10);
			}
			help *= 16;
		}
		cout << ans << endl;
	}
}