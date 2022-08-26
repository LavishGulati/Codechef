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

int n, m, k;

int check(vector<int> &output, int **c){
	int score = INT_MAX;
	for(int j = 0; j < k; j++){
		int x = 0;
		for(int i = 0; i < n; i++){
			if(output[i] == c[i][j]){
				x++;
			}
		}
		score = min(x, score);
	}
	return score;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	srand (time(NULL));

	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> k;

		int **c = new int *[n];
		for(int i = 0; i < n; i++){
			c[i] = new int[k];
			for(int j = 0; j < k; j++){
				cin >> c[i][j];
				c[i][j]--;
			}
		}

		int *score = new int[m];

		vector<int> output;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				score[j] = 0;
			}

			for(int j = 0; j < k; j++){
				score[c[i][j]]++;
			}

			int maxel = 0, ans = -1;
			for(int j = 0; j < m; j++){
				if(score[j] == maxel){
					if(int(rand())%2){
						ans = j;
						maxel = score[j];
					}
				}
				else if(score[j] > maxel){
					ans = j;
					maxel = score[j];
				}
			}

			output.pb(ans);
			// cout << ans+1 << " ";
		}
		// cout << endl;

		int maxscore = check(output, c);

		for(int k = 0; k < m; k++){
			vector<int> v;
			for(int i = 0; i < n; i++){
				v.pb(k);
			}

			int x = check(v, c);
			if(x > maxscore){
				maxscore = x;
				output = v;
			}
		}

		for(int i = 0; i < n; i++){
			cout << output[i]+1 << " ";
		}
		cout << endl;
	}
}