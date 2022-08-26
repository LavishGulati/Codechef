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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, n, m;
	cin >> t;
	while(t--){
		cin >> n >> m;
		int answer[n][m];

		if(n == 1 || m == 1){
			if(n == 1){
				for(int j = 0; j < m; j++){
					answer[0][j] = (j/2)%2 + 1;
				}
			}
			else{
				for(int i = 0; i < n; i++){
					answer[i][0] = (i/2)%2 + 1;
				}
			}
		}
		else if(n < 3 || m < 3){
			if(n == 2){
				for(int j = 0; j < m; j++){
					answer[0][j] = (j%3) + 1;
					answer[1][j] = answer[0][j];
				}
			}
			else{
				for(int i = 0; i < n; i++){
					answer[i][0] = (i%3) + 1;
					answer[i][1] = answer[i][0];
				}
			}
		}
		else{
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(i%2 == 0){
						if((i/2)%2 == 0){
							answer[i][j] = (j/2)%2 == 0 ? 1 : 2;
						}
						else{
							answer[i][j] = (j/2)%2 == 0 ? 2 : 1;
						}
					}
					else{
						if((i/2)%2 == 0){
							answer[i][j] = (j/2)%2 == 0 ? 3 : 4;
						}
						else{
							answer[i][j] = (j/2)%2 == 0 ? 4 : 3;		
						}
					}
				}
			}
		}

		// if(m%2 == 0){
		// 	if(m == 2){
		// 		for(int i = 0; i < n; i++){
		// 			answer[i][0] = (i%3) + 1;
		// 			answer[i][1] = (i%3) + 1;
		// 		}
		// 	}
		// 	else{
		// 		for(int i = 0; i < n; i++){
		// 			for(int j = 0; j < m; j++){
		// 				if(i%2 == 0){
		// 					if((i/2)%2 == 0){
		// 						answer[i][j] = (j/2)%2 == 0 ? 1 : 2;
		// 					}
		// 					else{
		// 						answer[i][j] = (j/2)%2 == 0 ? 2 : 1;
		// 					}
		// 				}
		// 				else{
		// 					if((i/2)%2 == 0){
		// 						answer[i][j] = (j/2)%2 == 0 ? 3 : 4;
		// 					}
		// 					else{
		// 						answer[i][j] = (j/2)%2 == 0 ? 4 : 3;		
		// 					}
		// 				}
		// 			}
		// 		}
		// 	}
		// }
		// else{
		// 	if(m == 1){
		// 		for(int i = 0; i < n; i++){
		// 			answer[i][0] = (i/2)%2 + 1;
		// 		}
		// 	}
		// 	else if(n == 1){
		// 		for(int j = 0; j < m; j++){
		// 			answer[0][j] = (j/2)%2 + 1;
		// 		}
		// 	}
		// 	else{
		// 		for(int i = 0; i < n; i++){
		// 			for(int j = 0; j < m; j++){
		// 				if(i%2 == 0){
		// 					if((i/2)%2 == 0){
		// 						answer[i][j] = (j/2)%2 == 0 ? 1 : 2;
		// 					}
		// 					else{
		// 						answer[i][j] = (j/2)%2 == 0 ? 2 : 1;
		// 					}
		// 				}
		// 				else{
		// 					if((i/2)%2 == 0){
		// 						answer[i][j] = (j/2)%2 == 0 ? 3 : 4;
		// 					}
		// 					else{
		// 						answer[i][j] = (j/2)%2 == 0 ? 4 : 3;		
		// 					}
		// 				}
		// 			}
		// 		}
		// 	}
		// }

		int maxKey = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) maxKey = max(maxKey, answer[i][j]);
		}

		cout << maxKey << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++) cout << answer[i][j] << " ";
			cout << endl;
		}
	}
}