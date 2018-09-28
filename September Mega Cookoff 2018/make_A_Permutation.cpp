#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int *arr = new int[100000];
    while(t--){
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) arr[i] = -1;

        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(x <= n) arr[x-1] = 1;
        }

        int total = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] == -1) total++;
        }
        cout << total << endl;
    }
}
