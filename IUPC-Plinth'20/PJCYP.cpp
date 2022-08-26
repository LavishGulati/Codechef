#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pi pair<int,int>
#define ppi pair<int,pi >
#define ld long double
#define pb push_back
#define mod 1000000007
#define F first
#define S second
#define endl "\n"
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector< vector<int> > vvi;
typedef vector<pair<int, int> > vpii;
typedef vector<int>::iterator ii;
typedef vector<vi>::iterator ivi;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<int, string> umapis;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<int, int> mapii;
typedef map<string, int> mapsi;
typedef map<int, string> mapis;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, pair<int,int> > mapipii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef unordered_set<int> useti;
typedef set<int> seti;
typedef priority_queue<int> mxpq;
typedef priority_queue< int, vector<int>, greater<int> > mnpq;


int modular(int a,int b,int c){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        return modular(((a*a)%c),b/2,c);
    }else{
        return ((a%c)*(modular(((a*a)%c),b/2,c)%c))%c;
    }
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=1;
    bool flag=false;
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i]){
            c++;
        }else{
            if(c%2!=0){
                flag=true;
                break;
            }else{
                c=1;
            }
        }
    }
    if(c%2!=0){
        flag=true;
    }
    if(flag){
        cout<<"Customer-A"<<endl;
    }else{
        cout<<"Customer-B"<<endl;
    }
    return 0;
}
