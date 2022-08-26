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
#define MAX 200005

int h[MAX], a[MAX];
bool taken[2][MAX];
int segId[2][MAX], pos[2][MAX], endpos[2][MAX], nextp[2][MAX];
int tree[2][4*MAX+1];

void buildTree0(int *tree, int si, int ei, int id){
    if(si == ei){
        tree[id] = si;
        return;
    }
    
    int mid = (si+ei)/2;
    buildTree0(tree, si, mid, 2*id);
    buildTree0(tree, mid+1, ei, 2*id+1);
    
    if(h[tree[2*id]] >= h[tree[2*id+1]]){
    	tree[id] = tree[2*id];
    }
    else{
    	tree[id] = tree[2*id+1];
    }
}

int query0(int *tree, int si, int ei, int start, int end, int id){  
    if(si > end || ei < start){
    	return -1;
    }
    else if(si >= start && ei <= end){
    	return tree[id];
    }
    else{
        int mid = (si+ei)/2;
        int a = query0(tree, si, mid, start, end, 2*id);
        int b = query0(tree, mid+1, ei, start, end, 2*id+1);
        if(a == -1){
        	return b;
        }
        else if(b == -1){
        	return a;
        }
        else if(h[a] >= h[b]){
        	return a;
        }
        else{
        	return b;
        }
    }
}

void buildTree1(int *tree, int si, int ei, int id){
    if(si == ei){
        tree[id] = si;
        return;
    }
    
    int mid = (si+ei)/2;
    buildTree1(tree, si, mid, 2*id);
    buildTree1(tree, mid+1, ei, 2*id+1);
    
    if(h[tree[2*id+1]] >= h[tree[2*id]]){
    	tree[id] = tree[2*id+1];
    }
    else{
    	tree[id] = tree[2*id];
    }
}

int query1(int *tree, int si, int ei, int start, int end, int id){  
    if(si > end || ei < start){
    	return -1;
    }
    else if(si >= start && ei <= end){
    	return tree[id];
    }
    else{
        int mid = (si+ei)/2;
        int a = query1(tree, si, mid, start, end, 2*id);
        int b = query1(tree, mid+1, ei, start, end, 2*id+1);
        if(a == -1){
        	return b;
        }
        else if(b == -1){
        	return a;
        }
        else if(h[b] >= h[a]){
        	return b;
        }
        else{
        	return a;
        }
    }
}

void buildTree(ll *tree, vector<ll> &arr, int si, int ei, int id){
    if(si == ei){
        tree[id] = a[arr[si]];
        return;
    }
    
    int mid = (si+ei)/2;
    buildTree(tree, arr, si, mid, 2*id);
    buildTree(tree, arr, mid+1, ei, 2*id+1);
    
    tree[id] = tree[2*id]+tree[2*id+1];
}

void update(ll *tree, int si, int ei, int id, int x, int val){
    if(si == ei){
        tree[id] = val;
        return;
    }
    
    int mid = (si+ei)/2;
    if(x <= mid){
    	update(tree, si, mid, 2*id, x, val);
    }
    else{
    	update(tree, mid+1, ei, 2*id+1, x, val);
    }
    
    tree[id] = tree[2*id]+tree[2*id+1];
}

ll query(ll *tree, int si, int ei, int start, int end, int id){  
    if(si > end || ei < start){
    	return 0;
    }
    else if(si >= start && ei <= end){
    	return tree[id];
    }
    else{
        int mid = (si+ei)/2;
        ll a = query(tree, si, mid, start, end, 2*id);
        ll b = query(tree, mid+1, ei, start, end, 2*id+1);
        return a+b;
    }
}

int main(){
	int n, q, i, j, m;
	scanf("%d%d", &n, &q);

	for(i = 0; i < n; i++){
		scanf("%d", h+i);
	}

	for(i = 0; i < n; i++){
		scanf("%d", a+i);
	}

	buildTree0(tree[0], 0, n-1, 1);
	buildTree1(tree[1], 0, n-1, 1);

	for(i = 0; i < n; i++){
		nextp[0][i] = -1;
		nextp[1][i] = -1;
	}

	stack<int> st;
	for(i = 0; i < n; i++){
		if(st.empty()){
			st.push(i);
		}
		else if(h[i] > h[st.top()]){
			while(!st.empty() && h[i] > h[st.top()]){
				nextp[0][st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		else{
			st.push(i);
		}
	}

	while(!st.empty()){
		st.pop();
	}
	for(i = n-1; i >= 0; i--){
		if(st.empty()){
			st.push(i);
		}
		else if(h[i] > h[st.top()]){
			while(!st.empty() && h[i] > h[st.top()]){
				nextp[1][st.top()] = i;
				st.pop();
			}
			st.push(i);
		}
		else{
			st.push(i);
		}
	}

	for(i = 0; i < n; i++){
		taken[0][i] = false; taken[1][i] = false;
	}

	
	ll **segSize = new ll *[2];
	segSize[0] = new ll[MAX]; segSize[1] = new ll[MAX];

	ll ***segArr = new ll **[2];
	segArr[0] = new ll *[n]; segArr[1] = new ll *[n];
	ll id = 0;

	vector<ll> help;
	for(i = 0; i < n; i++){
		if(!taken[0][i]){
			help.clear();
			j = i;
			while(1){
				taken[0][j] = true;
				help.pb(j);
				if(nextp[0][j] == -1 || taken[0][nextp[0][j]]){
					break;
				}
				j = nextp[0][j];
			}

			m = help.size();
			segArr[0][id] = new ll[4*m];
			for(j = 0; j < m; j++){
				segId[0][help[j]] = id;
				pos[0][help[j]] = j;
				endpos[0][help[j]] = help[m-1];
			}
			segSize[0][id] = m;

			buildTree(segArr[0][id], help, 0, m-1, 1);
			id++;
		}
	}

	id = 0;
	for(i = n-1; i >= 0; i--){
		if(!taken[1][i]){
			help.clear();
			j = i;
			while(1){
				taken[1][j] = true;
				help.pb(j);
				if(nextp[1][j] == -1 || taken[1][nextp[1][j]]){
					break;
				}
				j = nextp[1][j];
			}

			m = help.size();
			segArr[1][id] = new ll[4*m];
			for(j = 0; j < m; j++){
				segId[1][help[j]] = id;
				pos[1][help[j]] = j;
				endpos[1][help[j]] = help[m-1];
			}
			segSize[1][id] = m;

			buildTree(segArr[1][id], help, 0, m-1, 1);
			id++;
		}
	}

	int type, b, c, maxh;
	ll ans;
	while(q--){
		scanf("%d%d%d", &type, &b, &c);
		if(type == 1){
			b--;
			update(segArr[0][segId[0][b]], 0, segSize[0][segId[0][b]]-1, 1, pos[0][b], c);
			update(segArr[1][segId[1][b]], 0, segSize[1][segId[1][b]]-1, 1, pos[1][b], c);
		}
		else{
			b--; c--;
			if(b != c && h[b] <= h[c]){
				ans = -1;
			}
			else{
				if(b < c){
					maxh = query1(tree[1], 0, n-1, b, c, 1);
					if(maxh > b){
						ans = -1;
					}
					else{
						if(segId[1][b] == segId[1][c]){
							ans = query(segArr[1][segId[1][c]], 0, segSize[1][segId[1][c]]-1, pos[1][c], pos[1][b], 1);
						}
						else{
							ans = 0;
							while(segId[1][c] != segId[1][b]){
								ans += query(segArr[1][segId[1][c]], 0, segSize[1][segId[1][c]]-1, pos[1][c], pos[1][endpos[1][c]], 1);
								c = nextp[1][endpos[1][c]];
							}
							ans += query(segArr[1][segId[1][b]], 0, segSize[1][segId[1][b]]-1, pos[1][c], pos[1][b], 1);
						}
					}
				}
				else{
					maxh = query0(tree[0], 0, n-1, c, b, 1);
					if(maxh < b){
						ans = -1;
					}
					else{
						if(segId[0][b] == segId[0][c]){
							ans = query(segArr[0][segId[0][c]], 0, segSize[0][segId[0][b]]-1, pos[0][c], pos[0][b], 1);
						}
						else{
							ans = 0;
							while(segId[0][c] != segId[0][b]){
								ans += query(segArr[0][segId[0][c]], 0, segSize[0][segId[0][c]]-1, pos[0][c], pos[0][endpos[0][c]], 1);
								c = nextp[0][endpos[0][c]];
							}
							ans += query(segArr[0][segId[0][b]], 0, segSize[0][segId[0][b]]-1, pos[0][c], pos[0][b], 1);
						}
					}
				}
			}
			printf("%lld\n", ans);
		}
	}
}