#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	while(1){
		cin >> n;
		if(n == 0){
			break;
		}

		int *input = new int[n];
		for(int i = 0; i < n; i++){
			cin >> input[i];
		}

		stack<int> st;
		int num = 1;
		int id = 0;
		while(num <= n && id < n){
			if(!st.empty() && st.top() == num){
				num++;
				st.pop();
			}
			else if(input[id] == num){
				id++;
				num++;
			}
			else{
				st.push(input[id]);
				id++;
			}
		}

		while(!st.empty() && st.top() == num){
			st.pop();
			num++;
		}

		if(st.empty()){
			cout << "yes" << endl;
		}
		else{
			cout << "no" << endl;
		}
	}
}