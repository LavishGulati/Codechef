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

class Event{
public:
	int y, t, id;

	bool operator < (Event const &b){
		return mp(this->y, this->t) < mp(b.y, b.t);
	}
};

void buildTree(int *tree, int *input, int si, int ei, int id){
    if(si == ei){
        tree[id] = input[si];
        return;
    }
    
    int mid = (si+ei)/2;
    buildTree(tree, input, si, mid, 2*id);
    buildTree(tree, input, mid+1, ei, 2*id+1);
    
    tree[id] = tree[2*id]+tree[2*id+1];
}

void update(int *tree, int si, int ei, int id, int x, int val){
    if(si == ei){
        tree[id] = val;
        return;
    }
    
    int mid = (si+ei)/2;
    if(x <= mid) update(tree, si, mid, 2*id, x, val);
    else update(tree, mid+1, ei, 2*id+1, x, val);
    
    tree[id] = tree[2*id]+tree[2*id+1];
}

int query(int *tree, int si, int ei, int start, int end, int id){  
    if(si > end || ei < start){
    	return 0;
    }
    else if(si >= start && ei <= end){
    	return tree[id];
    }
    else{
        int mid = (si+ei)/2;
        int a = query(tree, si, mid, start, end, 2*id);
        int b = query(tree, mid+1, ei, start, end, 2*id+1);
        return a+b;
    }
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, q;
		cin >> n >> q;

		vector<Event> v;
		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		for(int i = 0; i < n-1; i++){
			v.pb({min(a[i], a[i+1]), 1, i});
			v.pb({max(a[i], a[i+1]), 3, i});
		}

		int *ql = new int[q];
		int *qr = new int[q];
		int *qy = new int[q];

		for(int i = 0; i < q; i++){
			cin >> ql[i] >> qr[i] >> qy[i];
			ql[i]--; qr[i]--;
		}

		for(int i = 0; i < q; i++){
			v.pb({qy[i], 2, i});
		}

		sort(all(v));

		int *tree = new int[4*n+1];
		for(int i = 0; i <= 4*n; i++){
			tree[i] = 0;
		}

		int *output = new int[q];

		for(Event e : v){
			if(e.t == 1){
				// cout << "INC: " << e.id << endl; 
				update(tree, 0, n-1, 1, e.id, 1);
			}
			else if(e.t == 2){
				// cout << "OUT: " << ql[e.id] << " " << qr[e.id] << endl;
				output[e.id] = query(tree, 0, n-1, ql[e.id], qr[e.id]-1, 1);
			}
			else{
				// cout << "DEC: " << e.id << endl; 
				update(tree, 0, n-1, 1, e.id, 0);
			}
		}

		for(int i = 0; i < q; i++){
			cout << output[i] << "\n";
		}
	}
}