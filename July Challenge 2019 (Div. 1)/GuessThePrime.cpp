#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;
typedef vector<int> vi;

#define uset unordered_set
#define it iterator
// #define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

vector< ll > fact(ll num)
{
    vector< ll > ret;

    for(ll i=2;i*1ll*i<=num;i++)
    {
        int ctr=0;

        while(num%i==0)
        {
            num/=i;

            ctr++;
        }

        if(ctr>0)
        {
            ret.pb(i);
        }
    }

    if(num>1)
    {
        ret.pb(num);
    }

    return ret;
}

ll poww(ll a,ll b,ll mod)
{
    ll x=1,y=a%mod;

    while(b>0)
    {
        if(b%2==1)
        {
            x=(x*y)%mod;
        }

        y=(y*y)%mod;b/=2;
    }

    return (x%mod);
}

ll inv(ll a,ll mod)
{
    return poww(a,mod-2,mod);
}

ll crt(vector< pll > v)
{
    int n=v.size();

    ll prod=1;

    for(int i=0;i<n;i++)
    {
        prod*=v[i].second;
    }

    ll ret=0;

    for(int i=0;i<n;i++)
    {
        ll now=prod/v[i].second;

        ll zz=(v[i].first*inv(now,v[i].second))%prod;

        zz=(zz*now)%prod;

        ret=(ret+zz)%prod;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;cin>>t;

    ll val=31623;

    while(t>0)
    {
        cout<<1<<" "<<val<<endl;

        ll res;cin>>res;

        res=(val*1ll*val)-res;

        vector< ll > divs=fact(res);sort(divs.begin(),divs.end());

        vector< pll > vec;set< ll > s;

        if(divs.size()==1)
        {
            cout<<2<<" "<<divs[0]<<endl;
        }

        else
        {

            for(int i=0;i<divs.size();i++)
            {
                for(ll j=0;;j++)
                {
                    ll zz=(j*1ll*j)%divs[i];

                    int prev=s.size();

                    s.insert(zz);

                    if(s.size()!=prev)
                    {
                        vec.pb({j,divs[i]});

                        break;
                    }
                }
            }

            ll q=crt(vec);assert(q>0);

            for(int i=0;i<vec.size();i++)
            {
                ll now=q%vec[i].second;

                assert(now==vec[i].first);
            }

            cout<<1<<" "<<q<<endl;

            ll get;cin>>get;ll ans=-1;

            for(ll x:divs)
            {
                ll now=(q*1ll*q)%x;

                if(now==get)
                {
                    ans=x;

                    break;
                }
            }

            cout<<2<<" "<<ans<<endl;
        }

        string qq;cin>>qq;

        t--;
    }

    return 0;
}
