const int MAX = 40, hMAX = (MAX + 1)/2, MAXE = MAX*MAX, MAXM = MAX*MAX;
int f[1 << hMAX];
int fr[MAXE], to[MAXE];

bool in_range(int s, int e, int x){
    return s <= x && x <= e;
}

void build(int L, int R, int *f, int *fr, int *to, int m, int *powers){
    int N = R-L+1;

    for(int msk = 0; msk < (1 << N); msk++) {
        f[msk] = 0;
        bool is_cover = 1;
        loop(e, m) if(in_range(L, R, fr[e]) && in_range(L, R, to[e])){
            int a = fr[e] - L;
            int b = to[e] - L;
            int ia = (msk >> a) & 1;
            int ib = (msk >> b) & 1;
            is_cover &= ia || ib;
            if(!is_cover) break;
        }
        int cnt = N;
        loop(i, N) if((msk >> i) & 1) {
            cnt--;
        }
        // f[msk] = powers[cnt] * is_cover;
        f[msk] = powers[cnt] * is_cover;
    }
    // prArr(f, (1 << N), int);
    for(int b = 0;b < N;b ++) {
        loop(msk, (1 << N)) if(!(msk & (1 << b))) f[msk] = add(f[msk], f[msk ^ (1 << b)]);
    }
    // prArr(f, (1 << N), int);
}


int solve(int N, int k, int *fr, int *to, int m) {
    static int powers[2*MAX];
    powers[0] = 1;
    loop(i, N) powers[i+1] = mul(powers[i], k);

    build(N/2, N-1, f, fr, to, m, powers);

    int n = N/2, res = 0;

    loop(msk, (1 << n)) {
        int other_msk = 0;
        int cnt = n;
        loop(i, n) if((msk >> i)&1){
            cnt--;
        }
        bool is_cover = 1;
        loop(e, m) {
            int a = fr[e], b = to[e];
            if(a >= n && b >= n) continue;
            if(a < n && b < n) {
                int ia = (msk >> a) & 1;
                int ib = (msk >> b) & 1;
                is_cover &= ia || ib;
                continue;
            }
            if(a > b) swap(a, b);
            assert(a < n);
            if(msk & (1 << a)) continue;
            other_msk |= 1 << (b - n);
        }
        if(!is_cover) continue;
        res = add(res, mul(f[other_msk], powers[cnt]));
    }
    return res;
}



int N, M;
bool has_contradiction = 0;
bool is_infinite = 0;
map<int, int> Z[MAXM];
int A[MAXM], B[MAXM], target[MAXM];
int lim[MAX], val[MAX];
bool done[MAXM];


queue<int> q;
vi V;
int solve(int p) {
    //cerr << "solve " << p << endl;
    loop(i, N) lim[i] = INT_MAX, val[i] = -1;
    loop(i, M){
        target[i] = 0;
        if(Z[i].count(p)) target[i] = Z[i][p];
        lim[A[i]] = min(lim[A[i]], target[i]);
        lim[B[i]] = min(lim[B[i]], target[i]);        
        done[i] = 0;
    }

    while(!q.empty()) q.pop();

    //cerr << "make q" << endl;
    loop(i, M){
        int a = A[i], b = B[i];
        if(lim[a] > lim[b]) swap(a, b);

        int ways = 0;
        int fa = lim[a] == target[i];
        int fb = lim[b] == target[i];
        ways = fa + fb - fa*(a == b);
        if(ways == 0) {
            //cerr << "contradiction" << endl;
            has_contradiction = 1;
            return 0;
        }
        if(ways == 1) q.push(i), done[i] = 1;
    }


    //cerr << "deduct" << endl;
    vi usable;
    while(!q.empty()){
        int i = q.front(); q.pop();
        int a = A[i], b = B[i];
        if(lim[a] > lim[b]) swap(a, b);

        if(val[a] == target[i] || val[b] == target[i]) continue;
        usable.clear();
        if(val[a] == -1 && lim[a] == target[i]) usable.pb(a);
        if(val[b] == -1 && lim[b] == target[i] && a != b) usable.pb(b);
        //cerr << "@" << i << " ";
        if(usable.empty()){
            //cerr << "contradiction" << endl;
            has_contradiction = 1;
            return 0;
        }
        assert(usable.size() == 1);

        a = usable[0];

        val[a] = target[i];
        //cerr << "set " << a << " to " << target[i] << endl;

        loop(j, M) if(!done[j] && (a == A[j] || a == B[j])) {
            done[j] = 1;
            q.push(j);
        }
    }
    loop(i, N) if(lim[i] == INT_MAX) {
        is_infinite = 1;
        return 0;
    }
    //cerr << "VC" << endl;
    set<int> freeVals;
    loop(i, N) if(val[i] == -1) freeVals.insert(lim[i]);
    int ret = 1;
    for(int v : freeVals) {
        V.clear();
        loop(i, N) if(val[i] == -1 && lim[i] == v) V.pb(i);
        int m = 0;
        loop(c, M) if(binary_search(all(V), A[c]) && binary_search(all(V), B[c])){
            int a = lower_bound(all(V), A[c]) - V.begin();
            int b = lower_bound(all(V), B[c]) - V.begin();
            if(a > b) swap(a, b);
            fr[m] = a;
            to[m] = b;
            m++;
        }
        ret = mul(ret, solve(sz(V), v, fr, to, m));
    }
    return ret;
}


void test_case(){
    set<int> P;
    scanf("%d %d", &N, &M);
    // cerr << "\t" << N << " " << M << endl;
    map<pi, map<int, int> > mem;
    int i = 0;
    bool return_zero = 0;

    loop(j, M){
        scanf("%d %d ", A + i, B + i);
        A[i]--, B[i]--;
        int k; scanf("%d", &k);
        Z[i].clear();
        for(;k;k--) {
            int p, e; scanf("%d %d", &p, &e);
            assert(p);
            Z[i][p] += e;
            P.insert(p);
        }
        int a = A[i], b = B[i];
        if(a > b) swap(a, b);
        pi p(a, b);
        if(mem.count(p)) {
            if(mem[p] != Z[i]) {
                return_zero = 1;
            }
            continue;
        }
        mem[p] = Z[i];
        i++;
    }
    if(return_zero) {
        puts("0");
        return;
    }
    // cerr << "M was " << M << " will become " << i << endl;
    M = i;
    set<int> constrained;
    loop(i, M) constrained.insert(A[i]), constrained.insert(B[i]);
    // cerr << constrained.size() << " vs " << N << endl;
    is_infinite = sz(constrained) != N;
    has_contradiction = 0;

    int res = 1;
    for(int p : P) {
        res = mul(res, solve(p));
        // //cerr << has_contradiction << endl;
        if(has_contradiction) {
            puts("0");
            return ;
        }
    }
    if(is_infinite) {
        puts("-1");
        return ;
    }
    printf("%d\n", res);
}



int main(){
#ifdef HOME
    freopen("in.in", "r", stdin);
#endif
    int T; scanf("%d", &T);
    while(T--) test_case();
    return 0;
}