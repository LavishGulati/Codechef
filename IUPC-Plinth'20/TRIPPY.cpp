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


void buildTree(int *a,int *tree,int start,int end,int node){
    if(start==end){
        tree[node]=a[start];
        return ;
    }
    int mid=(start+end)/2;
    buildTree(a,tree,start,mid,2*node);
    buildTree(a,tree,mid+1,end,2*node+1);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}

void updateTree(int *a,int *tree,int start,int end,int treeNode,int index,int value){
    if(start==end){
        a[index]=value;
        tree[treeNode]=value;
        return ;
    }
    int mid=(start+end)/2;
    if(index>=start && index<=mid){
        updateTree(a,tree,start,mid,2*treeNode,index,value);
    }else{
        updateTree(a,tree,mid+1,end,2*treeNode+1,index,value);
    }
    tree[treeNode]=min(tree[2*treeNode],tree[2*treeNode+1]);
}

int query(int *a,int *tree,int start,int end,int treeNode,int left,int right){
    if(start>right || end<left){
        return pow(10,18);
    }
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    int mid=(start+end)/2;
    return min(query(a,tree,start,mid,2*treeNode,left,right),query(a,tree,mid+1,end,2*treeNode+1,left,right));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    if(n==2){
        cout<<a[0]<<endl;
        return 0;
    }
    int *dp=new int[n];
    for(int i=0;i<n;i++){
        dp[i]=0;
    }
    int *tree=new int[4*n];
    buildTree(dp,tree,0,n-1,1);
    for(int i=n-2;i>=0;i--){
        int res=query(dp,tree,0,n-1,1,i+1,min(i+k,n-1));
        dp[i]=(a[i]+res);
        updateTree(dp,tree,0,n-1,1,i,dp[i]);
    }
    cout<<dp[0]<<endl;
    return 0;
}