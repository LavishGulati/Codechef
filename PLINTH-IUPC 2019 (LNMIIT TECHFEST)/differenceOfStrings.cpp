

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

int arr[2002][402][26] ;


int main( int argc , char ** argv )
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    // clock_t begin,end ;

    // begin = clock() ;

    ll N, Q ;
    cin >> N >> Q ;

    forr(i,1,N+1)
    {
        int len ;
        cin >> len ;
        string s ;
        cin >> s ;
        for(int j = 0 ; j < len ; j++ )
        {
            arr[i][j][s[j]-'a']++ ;
        }
    }


    forr(i,1,N+1)
    {
        for(int j = 0 ; j < 400 ; j++ )
        {
            for(int jj = 0 ; jj < 26 ; jj++)
            {
                arr[i][j][jj] += arr[i-1][j][jj] ;
            }
        }
    }

    while(Q--)
    {
        ll L,R ;
        string s ;
        cin >> L >> R >> s ;

        ll total = 0 ;
        ll len = s.length() ;

        forn(i,len)
        {
            forn(k,26)
            {
                total += (arr[R][i][k] - arr[L-1][i][k])*(abs(s[i]-('a'+k))) ;
            }
        }

        cout << total << '\n' ;
    }

    // end = clock() ;
    // cout << fixed ;
    // cout << "Time Taken: " << (double)(end-begin)/CLOCKS_PER_SEC << '\n' ;


    return 0 ;
}
