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

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int ans[n]={0};
        for(int i=0;i<m;i++){
            int sum=0;
            int a[n];
            for(int j=0;j<n;j++){
                cin>>a[j];
                sum+=a[j];
            }
            ld help=((ld)(sum))/(n);
            for(int j=0;j<n;j++){
                if(a[j]>help){
                    ans[j]=1;
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(ans[i]==1){
                c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
