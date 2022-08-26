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
#define MAX 200005

ll h[MAX], a[MAX];

void buildTree0(ll *tree, ll si, ll ei, ll id){
    if(si == ei){
        tree[id] = si;
        return;
    }
    
    ll mid = (si+ei)/2;
    buildTree0(tree, si, mid, 2*id);
    buildTree0(tree, mid+1, ei, 2*id+1);
    
    if(h[tree[2*id]] >= h[tree[2*id+1]]){
    	tree[id] = tree[2*id];
    }
    else{
    	tree[id] = tree[2*id+1];
    }
}

ll query0(ll *tree, ll si, ll ei, ll start, ll end, ll id){  
    if(si > end || ei < start){
    	return -1;
    }
    else if(si >= start && ei <= end){
    	return tree[id];
    }
    else{
        ll mid = (si+ei)/2;
        ll a = query0(tree, si, mid, start, end, 2*id);
        ll b = query0(tree, mid+1, ei, start, end, 2*id+1);
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

void buildTree1(ll *tree, ll si, ll ei, ll id){
    if(si == ei){
        tree[id] = si;
        return;
    }
    
    ll mid = (si+ei)/2;
    buildTree1(tree, si, mid, 2*id);
    buildTree1(tree, mid+1, ei, 2*id+1);
    
    if(h[tree[2*id+1]] >= h[tree[2*id]]){
    	tree[id] = tree[2*id+1];
    }
    else{
    	tree[id] = tree[2*id];
    }
}

ll query1(ll *tree, ll si, ll ei, ll start, ll end, ll id){  
    if(si > end || ei < start){
    	return -1;
    }
    else if(si >= start && ei <= end){
    	return tree[id];
    }
    else{
        ll mid = (si+ei)/2;
        ll a = query1(tree, si, mid, start, end, 2*id);
        ll b = query1(tree, mid+1, ei, start, end, 2*id+1);
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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, q;
	cin >> n >> q;

	for(ll i = 0; i < n; i++){
		cin >> h[i];
	}

	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}

	if(n <= 1000 && q <= 1000){

		ll type, b, c;
		while(q--){
			cin >> type >> b >> c;
			if(type == 1){
				a[b-1] = c;
			}
			else{
				b--; c--;
				if(b != c && h[b] <= h[c]){
					cout << -1 << endl;
				}
				else{
					ll i = c, ans = a[c], id = c;
					if(b < c){
						while(i > b){
							i--;
							if(h[i] > h[id]){
								id = i;
								ans += a[id];
							}
						}
					}
					else{
						while(i < b){
							i++;
							if(h[i] > h[id]){
								id = i;
								ans += a[id];
							}
						}
					}
					if(id == b){
						cout << ans << endl;
					}
					else{
						cout << -1 << endl;
					}
				}
			}
		}

	}
	else{

		ll **tree = new ll *[2];
		tree[0] = new ll[4*n+1]; tree[1] = new ll[4*n+1];
		buildTree0(tree[0], 0, n-1, 1);
		buildTree1(tree[1], 0, n-1, 1);

		ll **next = new ll *[2];
		next[0] = new ll[n]; next[1] = new ll[n];
		for(ll i = 0; i < n; i++){
			next[0][i] = -1;
			next[1][i] = -1;
		}

		stack<ll> st;
		for(ll i = 0; i < n; i++){
			if(st.empty()){
				st.push(i);
			}
			else if(h[i] > h[st.top()]){
				while(!st.empty() && h[i] > h[st.top()]){
					next[0][st.top()] = i;
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
		for(ll i = n-1; i >= 0; i--){
			if(st.empty()){
				st.push(i);
			}
			else if(h[i] > h[st.top()]){
				while(!st.empty() && h[i] > h[st.top()]){
					next[1][st.top()] = i;
					st.pop();
				}
				st.push(i);
			}
			else{
				st.push(i);
			}
		}


		ll **cum = new ll *[2];
		cum[0] = new ll[n]; cum[1] = new ll[n];
		for(ll i = n-1; i >= 0; i--){
			cum[0][i] = a[i];
			if(next[0][i] != -1){
				cum[0][i] += cum[0][next[0][i]];
			}
		}
		for(ll i = 0; i < n; i++){
			cum[1][i] = a[i];
			if(next[1][i] != -1){
				cum[1][i] += cum[1][next[1][i]];
			}
		}

		ll type, b, c;
		while(q--){
			cin >> type >> b >> c;
			if(type == 1){
				// do nothing
			}
			else{
				b--; c--;
				ll ans;
				if(b != c && h[b] <= h[c]){
					ans = -1;
				}
				else{
					
					if(b < c){
						ll maxh = query1(tree[1], 0, n-1, b, c, 1);
						// cout << b << " " << c << " " << maxh << endl;
						if(maxh > b){
							ans = -1;
						}
						else{
							if(next[1][b] == -1){
								ans = cum[1][c];
							}
							else{
								ans = cum[1][c]-cum[1][next[1][b]];
							}
						}
					}
					else{
						ll maxh = query0(tree[0], 0, n-1, c, b, 1);
						// cout << b << " " << c << " " << maxh << endl;
						if(maxh < b){
							ans = -1;
						}
						else{
							if(next[0][b] == -1){
								ans = cum[0][c];
							}	
							else{
								ans = cum[0][c]-cum[0][next[0][b]];
							}
						}
					}
				}
				cout << ans << endl;
			}
		}
	}
}