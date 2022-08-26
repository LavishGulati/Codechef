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

	int n;
	// cin >> n;
	scanf(" %d", &n);
	while(n--){
		string s;
		getline(cin, s);
		// cout << s << endl;

		string answer = "";

		bool start = true;
		string prevword = "";
		string curword = "";
		for(ll i = 0; i < s.length(); i++){
			if(s[i] == ' '){

				string temp = curword;
				transform(all(temp), temp.begin(), ::tolower);

				if(temp != prevword){
					if(!start){
						answer += ' ';
					}
					start = false;
					answer += curword;
					prevword = temp;
				}

				curword = "";
			}
			else{
				curword += s[i];
			}
		}

		string temp = curword;
		transform(all(temp), temp.begin(), ::tolower);

		if(temp != prevword){
			answer += ' ';
			answer += curword;
			prevword = temp;
		}

		curword = "";

		cout << answer << endl;
	}
}