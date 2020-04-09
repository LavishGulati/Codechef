#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define endl "\n"
#define mp make_pair
#define all(x) x.begin(), x.end()

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll y;
    cin >> y;

    vector<ll> output;

    double limit = sqrt(2*y)+9;
    ll x = 1;
    while(x <= limit){
        ll a = y - (x*(x-1))/2;
        if(a%x == 0){
            ll help = a/x + 1;
            while(help%2 == 0){
                help /= 2;
            }
            if(help == 1){
                // cout << (a/x + 1)*x << " ";
                output.pb((a/x + 1)*x);
            }
        }
        x += 2;
    }

    if(output.size() > 0){
        sort(all(output));
        for(ll i = 0; i < output.size(); i++){
            cout << output[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
}