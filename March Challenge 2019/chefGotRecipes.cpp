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

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    ll helper[600];
    while(t--){
        for(int i = 0; i < 600; i++) helper[i] = 0;
        int n;
        cin >> n;

        bool isPresent[30];


        string s;
        for(int i = 0; i < n; i++){
            for(int i = 0; i < 30; i++) isPresent[i] = false;

            cin >> s;
            for(int j = 0; j < s.length(); j++){
                isPresent[s[j]-'a'] = true;
            }

            int id = 0;
            if(isPresent['a'-'a']) id += 'a';
            if(isPresent['e'-'a']) id += 'e';
            if(isPresent['i'-'a']) id += 'i';
            if(isPresent['o'-'a']) id += 'o';
            if(isPresent['u'-'a']) id += 'u';

            helper[id]++;
        }

        ll total = 0;
        total += helper['a']*(helper['a'+'e'+'i'+'o'+'u']+helper['e'+'i'+'o'+'u']);
        total += helper['e']*(helper['a'+'e'+'i'+'o'+'u']+helper['a'+'i'+'o'+'u']);
        total += helper['i']*(helper['a'+'e'+'i'+'o'+'u']+helper['a'+'e'+'o'+'u']);
        total += helper['o']*(helper['a'+'e'+'i'+'o'+'u']+helper['a'+'e'+'i'+'u']);
        total += helper['u']*(helper['a'+'e'+'i'+'o'+'u']+helper['a'+'e'+'i'+'o']);

        total += helper['a'+'e']*(helper['i'+'o'+'u']+helper['a'+'i'+'o'+'u']+helper['e'+'i'+'o'+'u']+helper['a'+'e'+'i'+'o'+'u']);
        total += helper['a'+'o']*(helper['e'+'i'+'u']+helper['a'+'e'+'i'+'u']+helper['e'+'i'+'o'+'u']+helper['a'+'e'+'i'+'o'+'u']);
        total += helper['a'+'i']*helper['e'+'o'+'u'];
        total += helper['a'+'i']*helper['a'+'e'+'o'+'u'];
        total += helper['a'+'i']*helper['e'+'i'+'o'+'u'];
        total += helper['a'+'i']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['a'+'u']*helper['i'+'o'+'e'];
        total += helper['a'+'u']*helper['a'+'i'+'o'+'e'];
        total += helper['a'+'u']*helper['e'+'i'+'o'+'u'];
        total += helper['a'+'u']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['i'+'e']*helper['a'+'o'+'u'];
        total += helper['i'+'e']*helper['a'+'i'+'o'+'u'];
        total += helper['i'+'e']*helper['a'+'e'+'o'+'u'];
        total += helper['i'+'e']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['o'+'e']*helper['i'+'a'+'u'];
        total += helper['o'+'e']*helper['a'+'i'+'o'+'u'];
        total += helper['o'+'e']*helper['e'+'i'+'a'+'u'];
        total += helper['o'+'e']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['u'+'e']*helper['i'+'o'+'a'];
        total += helper['u'+'e']*helper['u'+'i'+'o'+'a'];
        total += helper['u'+'e']*helper['e'+'i'+'o'+'a'];
        total += helper['u'+'e']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['i'+'o']*helper['a'+'e'+'u'];
        total += helper['i'+'o']*helper['a'+'i'+'e'+'u'];
        total += helper['i'+'o']*helper['a'+'o'+'e'+'u'];
        total += helper['i'+'o']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['i'+'u']*helper['a'+'e'+'o'];
        total += helper['i'+'u']*helper['a'+'e'+'o'+'u'];
        total += helper['i'+'u']*helper['a'+'e'+'o'+'i'];
        total += helper['i'+'u']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['o'+'u']*helper['a'+'e'+'i'];
        total += helper['o'+'u']*helper['a'+'e'+'i'+'u'];
        total += helper['o'+'u']*helper['a'+'e'+'i'+'o'];
        total += helper['o'+'u']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['a'+'e'+'i']*(helper['o'+'u'+'a'+'e']+helper['o'+'u'+'a'+'i']+helper['o'+'u'+'e'+'i']);
        total += helper['a'+'e'+'i']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['a'+'e'+'o']*(helper['i'+'u'+'a'+'e']+helper['i'+'u'+'a'+'o']+helper['i'+'u'+'e'+'o']);
        total += helper['a'+'e'+'o']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['a'+'e'+'u']*(helper['o'+'i'+'a'+'e']+helper['i'+'o'+'a'+'u']+helper['o'+'u'+'e'+'i']);
        total += helper['a'+'e'+'u']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['a'+'i'+'o']*(helper['e'+'u'+'a'+'i']+helper['e'+'u'+'a'+'o']+helper['e'+'u'+'o'+'i']);
        total += helper['a'+'i'+'o']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['a'+'u'+'i']*(helper['o'+'e'+'a'+'u']+helper['o'+'e'+'a'+'i']+helper['o'+'u'+'e'+'i']);
        total += helper['a'+'u'+'i']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['a'+'o'+'u']*(helper['e'+'i'+'a'+'o']+helper['e'+'i'+'a'+'u']+helper['o'+'u'+'e'+'i']);
        total += helper['a'+'o'+'u']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['e'+'i'+'o']*(helper['a'+'u'+'i'+'e']+helper['o'+'u'+'a'+'e']+helper['o'+'u'+'a'+'i']);
        total += helper['o'+'e'+'i']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['u'+'e'+'i']*(helper['o'+'a'+'u'+'e']+helper['o'+'u'+'a'+'i']+helper['o'+'a'+'e'+'i']);
        total += helper['u'+'e'+'i']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['o'+'e'+'u']*(helper['a'+'i'+'o'+'e']+helper['o'+'u'+'a'+'i']+helper['a'+'u'+'e'+'i']);
        total += helper['o'+'e'+'u']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['o'+'u'+'i']*(helper['o'+'u'+'a'+'e']+helper['o'+'e'+'a'+'i']+helper['a'+'u'+'e'+'i']);
        total += helper['o'+'u'+'i']*helper['a'+'e'+'i'+'o'+'u'];

        total += helper['a'+'e'+'i'+'o'+'u']*(helper['a'+'e'+'i'+'o']+helper['a'+'e'+'i'+'u']+helper['a'+'e'+'o'+'u']+helper['a'+'i'+'o'+'u']+helper['e'+'i'+'o'+'u']);

        total += (helper['a'+'e'+'i'+'o'+'u']*(helper['a'+'e'+'i'+'o'+'u']-1))/2;

        ll mid = 0;
        mid += helper['a'+'e'+'i'+'o']*(helper['e'+'i'+'o'+'u']+helper['a'+'i'+'o'+'u']+helper['a'+'e'+'o'+'u']+helper['a'+'e'+'i'+'u']);
        mid += helper['a'+'e'+'i'+'u']*(helper['a'+'e'+'i'+'o']+helper['a'+'e'+'o'+'u']+helper['a'+'i'+'o'+'u']+helper['e'+'i'+'o'+'u']);
        mid += helper['a'+'e'+'o'+'u']*(helper['a'+'e'+'i'+'o']+helper['a'+'e'+'i'+'u']+helper['a'+'i'+'o'+'u']+helper['e'+'i'+'o'+'u']);
        mid += helper['a'+'i'+'o'+'u']*(helper['a'+'e'+'i'+'o']+helper['a'+'e'+'i'+'u']+helper['a'+'e'+'o'+'u']+helper['e'+'i'+'o'+'u']);
        mid += helper['e'+'i'+'o'+'u']*(helper['a'+'e'+'i'+'o']+helper['a'+'e'+'i'+'u']+helper['a'+'e'+'o'+'u']+helper['a'+'i'+'o'+'u']);
        total += mid/2;

        mid = 0;
        mid += helper['a'+'e'+'i']*(helper['o'+'u'+'a']+helper['o'+'u'+'e']+helper['o'+'u'+'i']);
        mid += helper['a'+'e'+'o']*(helper['i'+'u'+'a']+helper['i'+'u'+'e']+helper['i'+'u'+'o']);
        mid += helper['a'+'e'+'u']*(helper['i'+'o'+'a']+helper['i'+'o'+'e']+helper['i'+'o'+'u']);
        mid += helper['a'+'i'+'o']*(helper['e'+'u'+'a']+helper['e'+'u'+'i']+helper['e'+'u'+'o']);
        mid += helper['a'+'i'+'u']*(helper['e'+'o'+'a']+helper['e'+'o'+'i']+helper['e'+'o'+'u']);
        mid += helper['a'+'o'+'u']*(helper['e'+'i'+'a']+helper['e'+'i'+'o']+helper['e'+'i'+'u']);
        mid += helper['e'+'i'+'o']*(helper['a'+'u'+'e']+helper['a'+'u'+'i']+helper['a'+'u'+'o']);
        mid += helper['e'+'i'+'u']*(helper['a'+'o'+'e']+helper['a'+'o'+'i']+helper['a'+'o'+'u']);
        mid += helper['e'+'o'+'u']*(helper['a'+'i'+'e']+helper['a'+'i'+'o']+helper['a'+'i'+'u']);
        mid += helper['i'+'o'+'u']*(helper['a'+'e'+'i']+helper['a'+'e'+'o']+helper['a'+'e'+'u']);
        total += mid/2;

        cout << total << endl;
    }
}
