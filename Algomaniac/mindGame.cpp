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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll int n,q;
    cin>>n>>q;

    ll int *L=new ll int[q+1];
    pair<ll int,ll int> *arr=new pair<ll int,ll int>[q+1];
    ll int *dp1=new ll int[q+1];
    ll int *dp2=new ll int[q+1];
    for(ll int i=0;i<=q;i++){
        dp1[i]=0;
        dp2[i]=0;
    }
    ll int k=1;
    ll int t=q;
    while(t--){
        ll int l,r;
        cin>>l>>r;
        L[k]=l;
        arr[k].first=r;
        arr[k].second=l;
        k++;
    }
    sort(L+1,L+q+1);
    sort(arr+1,arr+q+1);
    // for(int i=1;i<=q;i++){
    //     cout<<L[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=1;i<=q;i++){
    //     cout<<arr[i].first<<" ";
    // }
    // cout<<endl;
    for(ll int i=1;i<=q;i++){
        dp1[i]=dp1[i-1]+L[i];
    }
    for(ll int i=1;i<=q;i++){
        dp2[i]=dp2[i-1]+arr[i].second;
    }
    for(ll int i=1;i<=n;i++){
        ll int start=1;
        ll int end=q;
        ll int ans=-1;
        while(start<=end){
            ll int mid=(start+end)/2;
            if(L[mid]>i){
                end=(mid-1);
            }else{
                ans=mid;
                start=mid+1;
            }
        }
        ll int sum=0;
        if(ans!=-1){
            sum=sum+(i+1)*ans-(dp1[ans]);
        }
        ll int start2=1;
        ll int end2=q;
        ll int ans2=-1;
        while(start2<=end2){
            ll int mid2=(start2+end2)/2;
            if(arr[mid2].first>=i){
                end2=(mid2-1);
            }else{
                ans2=mid2;
                start2=mid2+1;
            }
        }
        ll int help=0;
        if(ans2!=-1){
            help=help+(i+1)*ans2-(dp2[ans2]);
        }
        // cout<<sum<<" "<<help<<" "<<endl;
        cout<<(sum-help)<<" ";
    }
    cout<<endl;
    return 0;
}
