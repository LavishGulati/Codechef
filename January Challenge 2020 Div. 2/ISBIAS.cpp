#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

int binarySearch(vector<pib> &v, int l, int r){
	int si = 0;
	int ei = v.size()-1;
	int firstAns = -1;
	while(si <= ei){
		int mid = (si+ei)/2;
		if(v[mid].f < l){
			si = mid+1;
		}
		else if(v[mid].f > r){
			ei = mid-1;
		}
		else if(v[mid].s && v[mid].f == r){
			ei = mid-1;
		}
		else if(!v[mid].s && v[mid].f == l){
			si = mid+1;
		}
		else{
			firstAns = mid;
			ei = mid-1;
		}
	}

	si = 0;
	ei = v.size()-1;
	int secondAns = -1;
	while(si <= ei){
		int mid = (si+ei)/2;
		if(v[mid].f < l){
			si = mid+1;
		}
		else if(v[mid].f > r){
			ei = mid-1;
		}
		else if(v[mid].s && v[mid].f == r){
			ei = mid-1;
		}
		else if(!v[mid].s && v[mid].f == l){
			si = mid+1;
		}
		else{
			secondAns = mid;
			si = mid+1;
		}
	}

	if(firstAns != -1 && secondAns != -1){
		return secondAns/2 - firstAns/2 + 1;
		// if(v[firstAns].s && !v[secondAns].f){
		// 	return (secondAns-firstAns)/2 + 1;
		// }
		// else if(v[firstAns].s && v[secondAns].s){
		// 	return (secondAns-firstAns)/2 + 1;
		// }
		// else if(!v[firstAns].s && v[secondAns].s){
		// 	return 
		// }
	}
	else if(firstAns == -1 && secondAns == -1){
		si = 0;
		ei = v.size()-1;
		int id = -1;
		while(si <= ei){
			int mid = (si+ei)/2;
			if(v[mid].s && v[mid].f >= l){
				ei = mid-1;
			}
			else if(v[mid].s && v[mid].f < l){
				si = mid+1;
				id = mid;
			}
			else if(!v[mid].s && v[mid-1].f < l){
				si = mid+1;
				id = mid-1;
			}
			else{
				ei = mid-1;
			}
		}

		if(id >= 0 && v[id+1].f > r){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(firstAns != -1){
		// case cant occur
	}
	else{
		// case cant occur		
	}

	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, q;
	cin >> n >> q;

	int *input = new int[n];
	for(int i = 0; i < n; i++){
		cin >> input[i];
	}

	vector<pib> increasing;
	vector<pib> decreasing;

	int i = 0;
	while(i < n){
		int j = i+1;

		if(j >= n){
			break;
		}

		if(input[j] <= input[i]){
			i++;
			continue;
		}

		while(j < n && input[j] > input[j-1]){
			j++;
		}

		increasing.pb(mp(i, true));
		increasing.pb(mp(j-1, false));
		i = j;
	}

	i = 0;
	while(i < n){
		int j = i+1;

		if(j >= n){
			break;
		}

		if(input[j] >= input[i]){
			i++;
			continue;
		}

		while(j < n && input[j] < input[j-1]){
			j++;
		}

		decreasing.pb(mp(i, true));
		decreasing.pb(mp(j-1, false));
		i = j;
	}

	int l ,r;
	while(q--){
		cin >> l >> r;
		l--; r--;

		int inc = binarySearch(increasing, l, r);
		int dec = binarySearch(decreasing, l, r);
		// cout << "Inc: " << inc << ", Dec: " << dec << endl;
		if(inc == dec){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}