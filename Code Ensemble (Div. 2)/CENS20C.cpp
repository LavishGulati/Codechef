#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

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

int *computeLPS(string pat){
	int m = pat.length(), len = 0, i = 1;

	int *lps = new int[m];
	lps[0] = 0;
	
	while(i < m){
		if(pat[i] == pat[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len != 0){
				len = lps[len-1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
	return lps;
}

vector<int> KMP(string txt, string pat){
	int n = txt.length();
	int m = pat.length();

	vector<int> output;
	int *lps = computeLPS(pat);
	int i = 0, j = 0;
	while(i < n){
		if(pat[j] == txt[i]){
			j++; i++;
		}

		if(j == m){
			output.pb(i-j);
			j = lps[j-1];
		}
		else if(i < n && pat[j] != txt[i]){
			if(j != 0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}
	}
	return output;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();

	vector<int> v1 = KMP(s, t);
	vector<int> v2 = KMP(s+s, t);
	int c1 = v1.size();
	int c2 = v2.size();
	int c3 = c2-2*c1;

	ll *dp = new ll[2*n];
	for(ll i = 0; i < 2*n; i++){
		dp[i] = 0;
	}
	for(ll x : v2){
		dp[x+m-1] = 1;
	}
	for(ll j = 1; j < 2*n; j++){
		dp[j] += dp[j-1];
	}
	

	ll q, qry, x, ans;
	cin >> q;
	while(q--){
		cin >> qry;
		x = qry/n;

		ans = 0;
		if(x > 0){
			ans += x*c1 + (x-1)*c3;
			qry = qry%n;
			ans += dp[n+qry-1]-dp[n-1];
		}
		else{
			ans += dp[qry-1];
		}
		
		cout << ans << endl;
	}
}