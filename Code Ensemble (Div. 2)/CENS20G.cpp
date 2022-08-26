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

#define MAX 1000005

int main(){
	int t;
	scanf("%d", &t);

	char s[MAX];

	while(t--){
		scanf("%s\n", s);
		int n = strlen(s);

		int x1, y1;
		scanf("%d%d", &x1, &y1);

		int l = 0, r = 0, d = 0, u = 0;
		for(int i = 0; i < n; i++){
			char c = s[i];
			if(c == 'L'){
				l++;
			}
			else if(c == 'R'){
				r++;
			}
			else if(c == 'D'){
				d++;
			}
			else{
				u++;
			}
		}

		bool poss;
		int q, x, y;
		scanf("%d", &q);
		while(q--){
			scanf("%d%d", &x, &y);

			poss = true;
			if(x > x1){
				if(r < x-x1){
					poss = false;
				}
			}
			else if(x < x1){
				if(l < x1-x){
					poss = false;
				}
			}

			if(y > y1){
				if(u < y-y1){
					poss = false;
				}
			}
			else if(y < y1){
				if(d < y1-y){
					poss = false;
				}
			}

			if(!poss){
				printf("NO\n");
			}
			else{
				printf("YES %d\n", abs(x-x1)+abs(y-y1));
			}
		}
	}
}