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

#define MAX 1000005

int a[MAX];

int main(){
	int t, n, x, i, cnt, unq, rm;
	scanf(" %d", &t);

	while(t--){
		scanf(" %d", &n);
		memset(a, 0, sizeof(int)*(n+5));
		// for(int i = 0; i <= n; i++){
		// 	cout << a[i] << endl;
		// }

		for(i = 0; i < n; i++){
			scanf(" %d", &x);
			a[x]++;
		}

		rm = 0, unq = 0;
		for(i = 1; i <= n; i++){
			if(a[i] > 0){
				unq++;
			}

			if(a[i] == 2){
				rm++;
			}
			else if(a[i] >= 3 && !(a[i]%2)){
				rm++;
			}
		}

		if(rm%2){
			printf("%d\n", unq-1);
		}
		else{
			printf("%d\n", unq);
		}
	}
}