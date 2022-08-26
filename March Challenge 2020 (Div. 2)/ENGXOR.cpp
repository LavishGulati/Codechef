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
	scanf(" %d", &t);
	// cin >> t;
	while(t--){
		int n, q;
		scanf(" %d %d", &n, &q);
		// cin >> n >> q;

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			// cin >> a[i];
			scanf(" %d", a+i);
		}

		int *setbit = new int[32];
		int *numset = new int[n];
		for(int i = 0; i < n; i++){
			numset[i] = 0;
		}

		for(int i = 0; i < 32; i++){
			setbit[i] = 0;
			for(int j = 0; j < n; j++){
				if(a[j]%2){
					setbit[i]++;
					numset[j] ^= 1;
				}
				a[j] /= 2;
			}
		}

		// for(int i = 0; i < 32; i++){
		// 	cout << setbit[i] << " ";
		// }
		// cout << endl;

		// for(int i = 0; i < n; i++){
		// 	cout << numset[i] << " ";
		// }
		// cout << endl;

		int odd = 0, even = 0;
		for(int i = 0; i < n; i++){
			if(numset[i]){
				odd++;
			}
			else{
				even++;
			}
		}

		// cout << odd << " " << even << endl;

		int p;
		while(q--){
			scanf("%d", &p);

			int smallodd = odd, smalleven = even;
			for(int i = 0; i < 32; i++){
				if(p%2){
					swap(smallodd, smalleven);
				}
				p /= 2;
			}

			printf("%d %d\n", smalleven, smallodd);
		}
	}
}