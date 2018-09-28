#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        // int *input = new int[n];
        string answer = "";
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(k >= x){
                answer += '1';
                k -= x;
            }
            else answer += '0';
        }

        cout << answer << endl;
    }
}
