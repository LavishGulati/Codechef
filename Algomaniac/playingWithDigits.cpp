#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppi pair<int,pi >
#define ppl pair<ll,pl >
#define ld long double
#define pb push_back
#define mod 1000000007

long long int modular(long long int a,long long int b,long long int c){
  if(b==0){
    return 1;
  }
  if(b%2==0){
    return (modular((a*a)%c,b/2,c))%c;
  }else{
    return ((a%c)*modular((a*a)%c,b/2,c))%c;
  }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll int n,q;
    cin>>n>>q;
    ll int *a=new ll int[n+1];
    for(ll int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll int *dp=new ll int[n+1];
    for(ll int i=0;i<=n;i++){
        dp[i]=0;
    }
    for(ll int i=1;i<=n;i++){
        dp[i]=dp[i-1]+a[i];
    }
    while(q--){
        ll int l1,r1,l2,r2,c;
        cin>>l1>>r1>>l2>>r2>>c;
        ll int q=(dp[r2]-dp[l2-1]);
        ll int p=(dp[r1]-dp[l1-1]);
        ll int ans=(modular(p,q,100));
        ll int flag=0;
        // cout<<c<<endl;
        ll int res=1;
        for(ll int i=0;i<q;i++){
            res=(res*p);
            if(res>=10){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"No "<<-1<<endl;
            continue;
        }
        if((ans/10)==c){
                cout<<"Yes "<<(ans/10)<<endl;
            }else{
                cout<<"No "<<(ans/10)<<endl;
            }
    }

    return 0;
}
