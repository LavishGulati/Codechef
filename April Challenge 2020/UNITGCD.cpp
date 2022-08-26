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
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	// cin >> t;
	scanf(" %d", &t);
	while(t--){
		int n;
		// cin >> n;
		scanf(" %d", &n);

		if(n == 1){
			printf("1\n1 1\n");
			continue;
		}

		// cout << n/2 << endl;
		printf("%d\n", n/2);
		for(int i = 1; i <= (n%2 ? n-3 : n); i += 2){
			// cout << 2 << " " << i << " " << i+1 << endl;
			printf("2 %d %d\n", i, i+1);
		}
		if(n%2){
			// cout << 3 << " " << n-2 << " " << n-1 << " " << n << endl;
			printf("3 %d %d %d\n", n-2, n-1, n);
		}
	}
}