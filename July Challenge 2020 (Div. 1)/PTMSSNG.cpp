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

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		map<int, int> mpi;
		map<int, int> mpj;
		int x, y;
		for(int i = 0; i < 4*n-1; i++){
			cin >> x >> y;
			mpi[x]++;
			mpj[y]++;
		}

		for(pii a : mpi){
			if(a.s%2){
				x = a.f;
				break;
			}
		}
		for(pii b : mpj){
			if(b.s%2){
				y = b.f;
				break;
			}
		}
		cout << x << " " << y << endl;
	}
}