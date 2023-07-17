#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using vbb  = vector<vb>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using table = unordered_map<unsigned long, int>;
using pll = pair<ll,ll>;
using vpl = vector<pll>;
using vpll = vector<vpl>;

#define f first
#define s second

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i <= b; i++)
#define for1n(i, n) for(int i = 1; i <= n; i++)
#define rof(i, n) for(int i = n-1; i >= 0; i--)
#define rofe(i, a, b) for(int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
#define dsc(type) greater<type>

#define Flag cout << "Reached here.\n"
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert

#define lb(a, val) lower_bound(all(a), val);
#define ub(a, val) upper_bound(all(a), val);

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 1000000000
#define MIN -MAX

#define mod 1000000007LL

#define clr(x, y) memset(x, y, sizeof(x))

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void init() {
    /*
    #ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    #endif
    */

    freopen("build/input.txt", "r", stdin);
}

ll binpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a, res %= mod;
        a *= a, a %= mod;
        b >>= 1;
    }
    return res;
}

vi fct(ll n) {
    vi fac;
    while(n%2 == 0) n /= 2, fac.pb(2);
    for(int i = 3; i * i <= n; i += 2) 
        while(n%i == 0) fac.pb(i), n /= i;
    if(n > 1) fac.pb(n);
    return fac;
}

ll gcd(ll a, ll b) {
   if (b == 0) return a;
   return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return (a*b) / gcd(a, b);
}

//Using sparse table

#define maxN 200005
int sp[20][maxN];

class Lca {
private:
int log[2*maxN];
vi euler, fir, hit;

void dfs(vector<vi>& adj, int v, int h = 1) {
    fir[v] = euler.size();
    euler.push_back(v);
    hit[v] = h;

    for(auto e : adj[v]) {
        if(fir[e] == -1) {
            dfs(adj, e, h+1);
            euler.push_back(v);
        }
    }
}

void build() {
    int n = euler.size();
    for(int i = 0 ;i < n; i++) sp[0][i] = euler[i];

    for(int j = 1; (1<<j) < n; j++) {
        for(int i = 0; i+(1<<j) < n; i++)
            sp[j][i] = (hit[sp[j-1][i]] < hit[sp[j-1][i+(1<<(j-1))]]) ? sp[j-1][i] : sp[j-1][i+(1<<(j-1))];
    }
    log[1] = 0;
    for(int i = 2; i < 2*maxN; i++) log[i] = log[i/2]+1;
}

public:
Lca(vector<vi>& adj, int root = 0) {
    euler.reserve(adj.size()*2+1);
    fir.resize(adj.size(), -1);
    hit.resize(adj.size());

    dfs(adj, root);

    build();
}

int lca(int u, int v) {
    u = fir[u], v = fir[v];
    if(u > v) swap(u, v);
    // cout << v-u+1 << '\n';
    int lg = log[v-u+1];
    
    // cout << lg << " And this is: " << sp[lg][0] << '\n';
    auto one = sp[lg][u];
    auto two = sp[lg][v-(1<<lg)+1];
    
    return (hit[one] > hit[two]) ? two : one;
}

int dist(int u, int v) {
    return (hit[u]+hit[v])-(2*hit[lca(u,v)]);
}

};


void solve() {
    int n, q;
    cin >> n >> q;
    vii adj(n);

    forn(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }

    Lca ds(adj);

    vi trace(n);
    forn(i, n) trace[i] = i;
    forn(k, q) {
        int t, i, j;
        cin >> t >> i >> j;
        if(t == 0) swap(trace[i-1], trace[j-1]);
        else {
            // cout << i-1 << ' ' << j-1 << '\n';
            cout << ds.dist(trace[i-1], trace[j-1]) << '\n';
        }
    }
}

int main() {
    //Sublime
    init();
    /*
    FASTIO;
    int t;
    cin >> t;
    while(t--) solve();
    */
    solve();
}
