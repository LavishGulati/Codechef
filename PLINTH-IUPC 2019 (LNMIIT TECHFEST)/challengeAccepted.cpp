

/*

                Name: Kartik Gupta
                IIT-Guwahati

*/

#include <bits/stdc++.h>
#define ll long long
#define maxn 100001
#define vll vector<ll>
#define forr(i,a,n) for(ll i = a ; i < n ; i++)
#define forn(i,n) for(ll i = 0 ; i < n ; i++)
#define revfor(i,b,a) for(ll i = b ; i >= a ; i--)
#define revforn(i,n) for(ll i = n ; i >= 0 ; i--)
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define fi first
#define sec second

using namespace std;

ll findCost(ll Z, ll * A, ll N, ll X, ll Y)
{
    ll cost = 0 ;
    forn(i,N)
    {
        ll a = Z - A[i] ;
        if(a < 0)
        {
            a *= X ;
        }
        else
        {
            a *= Y ;
        }
        cost += a ;
    }
    return cost ;
}


int main( int argc , char ** argv )
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    ll T ;
    cin >> T ;
    while(T--)
    {
        ll N ;
        ll X,Y ;

        cin >> N >> X >> Y ;

        ll A[maxn] ;
        ll maxEl = -1 ;
        forn(i,N)
        {
            cin >> A[i] ;
            maxEl = max(A[i],maxEl) ;
        }

        // sort(A,A+N) ;

        ll left = 1 ;
        ll right = maxEl+1 ;

        ll Ans = -1 ;

        while(left <= right)
        {
            ll mid = (right-left)/2 + left ;
            ll cost = findCost(mid, A, N, X, Y) ;
            // cout << "At " << mid << " Cost: " << cost << '\n' ;
            if(cost > 0)
            {
                /* Check for left */
                Ans = mid ;
                right = mid-1 ;
            }
            else if(cost < 0)
            {
                left = mid+1 ;
            }
            else
            {
                Ans = mid ;
                break ;
            }
        }

        cout << findCost(Ans,A,N,X,Y) << '\n' ;
        cout << flush ;
    }









    return 0 ;
}
