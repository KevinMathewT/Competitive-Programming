// Manacher's Algorithm
vector<ll> d1, d2; // for even length, for odd length, s: string
for (int i = 0, l = 0, r = -1; i < n; i++)
{
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
    {
        k++;
    }
    d1[i] = k--;
    if (i + k > r)
    {
        l = i - k;
        r = i + k;
    }
}
for (int i = 0, l = 0, r = -1; i < n; i++)
{
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k])
    {
        k++;
    }
    d2[i] = k--;
    if (i + k > r)
    {
        l = i - k - 1;
        r = i + k;
    }
}

// Z-algorithm                          string s with pattern + '#' + string
vector<int> z_function(string s)
{
    int n = (int)s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

// Segment Tree
void updateRange(int node, int start, int end, int l, int r, int val)
{
    if (lazy[node] != 0)
    {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start > end or start > r or end < l)
        return;
    if (start >= l and end <= r)
    {
        tree[node] += (end - start + 1) * val;
        if (start != end)
        {

            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node * 2, start, mid, l, r, val);
    updateRange(node * 2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int queryRange(int node, int start, int end, int l, int r)
{
    if (start > end or start > r or end < l)
        return 0;
    if (lazy[node] != 0)
    {

        tree[node] += (end - start + 1) * lazy[node];
        if (start != end)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (start >= l and end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node * 2, start, mid, l, r);
    int p2 = queryRange(node * 2 + 1, mid + 1, end, l, r);
    return (p1 + p2);
}

// Prefix function  string: s
vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// GRAPHS

// Bridges in a graph
int n;                   // number of nodes
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> tin, low;
int timer;
void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}
void find_bridges()
{
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

// Articulation Points
int n;                   // number of nodes
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> tin, low;
int timer;
void dfs(int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children = 0;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cutpoints()
{
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
}

// Strongly Connected Components
vector<vector<int>> g, gr;
vector<bool> used;
vector<int> order, component;
void dfs1(int v)
{
    used[v] = true;
    for (size_t i = 0; i < g[v].size(); ++i)
        if (!used[g[v][i]])
            dfs1(g[v][i]);
    order.push_back(v);
}
void dfs2(int v)
{
    used[v] = true;
    component.push_back(v);
    for (size_t i = 0; i < gr[v].size(); ++i)
        if (!used[gr[v][i]])
            dfs2(gr[v][i]);
}
int main()
{
    int n;
    cin >> n;
    for (;;)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }

    used.assign(n, false);
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    for (int i = 0; i < n; ++i)
    {
        int v = order[n - 1 - i];
        if (!used[v])
        {
            dfs2(v);
            ... printing next component... component.clear();
        }
    }
}

// Dijkstra
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
void dijkstra(int s, vector<int> &d, vector<int> &p)
{
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty())
    {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v])
        {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to])
            {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

// Bellman-Ford
void solve()
{
    vector<int> d(n, INF);
    d[v] = 0;
    vector<int> p(n - 1);
    int x;
    for (int i = 0; i < n; ++i)
    {
        x = -1;
        for (int j = 0; j < m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost)
                {
                    d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }

    if (x == -1)
        cout << "No negative cycle from " << v;
    else
    {
        int y = x;
        for (int i = 0; i < n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur = y;; cur = p[cur])
        {
            path.push_back(cur);
            if (cur == y && path.size() > 1)
                break;
        }
        reverse(path.begin(), path.end());

        cout << "Negative cycle: ";
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << ' ';
    }
}

// Floyd Warshall
for (int k = 0; k < n; ++k)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}

// Prim's
const int INF = 1000000000;

struct Edge
{
    int w = INF, to = -1;
    bool operator<(Edge const &other) const
    {
        return w < other.w;
    }
};

int n;
vector<vector<Edge>> adj;

void prim()
{
    int total_weight = 0;
    vector<Edge> min_e(n);
    min_e[0].w = 0;
    set<Edge> q;
    q.insert({0, 0});
    vector<bool> selected(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (q.empty())
        {
            cout << "No MST!" << endl;
            exit(0);
        }

        int v = q.begin()->to;
        selected[v] = true;
        total_weight += q.begin()->w;
        q.erase(q.begin());

        if (min_e[v].to != -1)
            cout << v << " " << min_e[v].to << endl;

        for (Edge e : adj[v])
        {
            if (!selected[e.to] && e.w < min_e[e.to].w)
            {
                q.erase({min_e[e.to].w, e.to});
                min_e[e.to] = {e.w, v};
                q.insert({e.w, e.to});
            }
        }
    }

    cout << total_weight << endl;
}

// Kruskal
vector<int> parent, rank;

void make_set(int v)
{
    parent[v] = v;
    rank[v] = 0;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

struct Edge
{
    int u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

int n;
vector<Edge> edges;

int cost = 0;
vector<Edge> result;
parent.resize(n);
rank.resize(n);
for (int i = 0; i < n; i++)
    make_set(i);

sort(edges.begin(), edges.end());

for (Edge e : edges)
{
    if (find_set(e.u) != find_set(e.v))
    {
        cost += e.weight;
        result.push_back(e);
        union_sets(e.u, e.v);
    }
}

// LCA
//P[i][j] stores the 2^j th ancestor of node i
int P[MAX_NODES][MAX_LOG], parent[MAX_NODES];

void preprocess()
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; (1 << j) < N; ++i)
        {
            P[i][j] = -1;
        }
    }
    for (int i = 1; i <= N; ++i)
    {
        P[i][0] = parent[i];
    }

    for (int j = 1; (1 << j) < N; ++j)
    {
        for (int i = 1; i <= N; ++i)
        {
            if (P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
            }
        }
    }
}
int LCA(int u, int v)
{
    if (level[u] < level[v])
    {
        swap(u, v);
    }
    int dist = level[u] - level[v];
    while (dist > 0)
    {
        int raise_by = log2(dist);
        u = P[u][raise_by];
        dist -= (1 << raise_by);
    }
    if (u == v)
    {
        return u;
    }
    for (int j = MAXLOG; j >= 0; --j)
    {
        if ((P[u][j] != -1) and (P[u][j] != P[v][j]))
        {
            u = P[u][j];
            v = P[v][j];
        }
    }
    return parent[u];
}

// MAX FLOW ALGORITHMS

// Ford Fulkerson
int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur])
        {
            if (parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t)
{
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent))
    {
        flow += new_flow;
        int cur = t;
        while (cur != s)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

// Dinic Max Flow
struct FlowEdge
{
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic
{
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t)
    {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap)
    {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs()
    {
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int id : adj[v])
            {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed)
    {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++)
        {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow()
    {
        long long f = 0;
        while (true)
        {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf))
            {
                f += pushed;
            }
        }
        return f;
    }
};

// Push Relabel
const int inf = 1000000000;

int n;
vector<vector<int>> capacity, flow;
vector<int> height, excess;

void push(int u, int v)
{
    int d = min(excess[u], capacity[u][v] - flow[u][v]);
    flow[u][v] += d;
    flow[v][u] -= d;
    excess[u] -= d;
    excess[v] += d;
}

void relabel(int u)
{
    int d = inf;
    for (int i = 0; i < n; i++)
    {
        if (capacity[u][i] - flow[u][i] > 0)
            d = min(d, height[i]);
    }
    if (d < inf)
        height[u] = d + 1;
}

vector<int> find_max_height_vertices(int s, int t)
{
    vector<int> max_height;
    for (int i = 0; i < n; i++)
    {
        if (i != s && i != t && excess[i] > 0)
        {
            if (!max_height.empty() && height[i] > height[max_height[0]])
                max_height.clear();
            if (max_height.empty() || height[i] == height[max_height[0]])
                max_height.push_back(i);
        }
    }
    return max_height;
}

int max_flow(int s, int t)
{
    height.assign(n, 0);
    height[s] = n;
    flow.assign(n, vector<int>(n, 0));
    excess.assign(n, 0);
    excess[s] = inf;
    for (int i = 0; i < n; i++)
    {
        if (i != s)
            push(s, i);
    }

    vector<int> current;
    while (!(current = find_max_height_vertices(s, t)).empty())
    {
        for (int i : current)
        {
            bool pushed = false;
            for (int j = 0; j < n && excess[i]; j++)
            {
                if (capacity[i][j] - flow[i][j] > 0 && height[i] == height[j] + 1)
                {
                    push(i, j);
                    pushed = true;
                }
            }
            if (!pushed)
            {
                relabel(i);
                break;
            }
        }
    }

    int max_flow = 0;
    for (int i = 0; i < n; i++)
        max_flow += flow[0][i];
    return max_flow;
}

// Topological Sort
int n;                   // number of vertices
vector<vector<int>> adj; // adjacency list of graph
vector<bool> visited;
vector<int> ans;

void dfs(int v)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
            dfs(u);
    }
    ans.push_back(v);
}

void topological_sort()
{
    visited.assign(n, false);
    ans.clear();
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

// Heavy-Light Decomposition
#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#define print(x) cerr << #x << " is " << x << endl;
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

vll parent, depth, heavy, head, pos;
pll adj[10005];
ll n, curPos, t[100050], a[10050], down[10050], weight[10050];

ll dfs(ll x)
{
    ll s = 1, mx = -1;
    f(0, adj[x].size())
    {
        if (adj[x][i].first != parent[x])
        {
            parent[adj[x][i].first] = x, depth[adj[x][i].first] = depth[x] + 1;
            ll k = dfs(adj[x][i].first);
            down[adj[x][i].second] = adj[x][i].first;
            s += k;
            if (k > mx)
                mx = k, heavy[x] = adj[x][i].first;
        }
    }
    return s;
}

void decompose(ll v, ll h)
{
    head[v] = h, pos[v] = curPos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h);
    f(0, adj[v].size()) if (adj[v][i].first != parent[v] && adj[v][i].first != heavy[v]) decompose(adj[v][i].first, adj[v][i].first);
}

void init()
{
    parent.clear();
    parent.resize(n + 5);
    depth.clear();
    depth.resize(n + 5);
    heavy.clear();
    heavy = vector<ll>(n + 5, -1);
    head.clear();
    head.resize(n + 5);
    pos.clear();
    pos.resize(n + 5);
    curPos = 1;
    memset(a, 0, sizeof(a));
    dfs(1);
    decompose(1, 1);
}

void create(ll node, ll start, ll end)
{
    if (start == end)
    {
        t[node] = a[start];
        return;
    }
    ll mid = start + end >> 1;
    create(node << 1, start, mid);
    create(node << 1 ^ 1, mid + 1, end);
    t[node] = max(t[node << 1], t[node << 1 ^ 1]);
}

void update(ll node, ll start, ll end, ll in, ll val)
{
    if (start == end)
    {
        a[start] = val;
        t[node] = a[start];
        return;
    }
    ll mid = start + end >> 1;
    if (in <= mid)
        update(node << 1, start, mid, in, val);
    else
        update(node << 1 ^ 1, mid + 1, end, in, val);
    t[node] = max(t[node << 1], t[node << 1 ^ 1]);
}

ll query(ll node, ll start, ll end, ll l, ll r)
{
    if (start > r || end < l || l > r)
        return -1e18;
    if (start >= l && end <= r)
        return t[node];
    ll mid = start + end >> 1;
    return max(query(node << 1, start, mid, l, r), query(node << 1 ^ 1, mid + 1, end, l, r));
}

ll hldQuery(ll a, ll b)
{
    ll r = 0;
    for (; head[a] != head[b]; b = parent[head[b]])
    {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        r = max(r, query(1, 1, n, pos[head[b]], pos[b]));
    }
    if (depth[a] > depth[b])
        swap(a, b);
    r = max(r, query(1, 1, n, pos[heavy[a]], pos[b]));
    return r;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll tc;
    cin >> tc;
    while (tc--)
    {
        cin >> n;
        f(1, n + 1) adj[i].clear();
        f(0, n - 1)
        {
            ll x, y, w;
            cin >> x >> y >> w;
            adj[x].pb({y, i + 1});
            adj[y].pb({x, i + 1});
            weight[i + 1] = w;
        }
        init();
        f(1, n) a[pos[down[i]]] = weight[i];
        create(1, 1, n);
        while (1)
        {
            string s;
            cin >> s;
            if (s == "DONE")
                break;
            if (s == "QUERY")
            {
                ll a, b;
                cin >> a >> b;
                ll ans = hldQuery(a, b);
                cout << ans << "\n";
            }
            else
            {
                ll in, val;
                cin >> in >> val;
                update(1, 1, n, pos[down[in]], val);
            }
        }
    }

    return 0;
}

// Miscellaneous

// LIS
int lis(vector<int> const &a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n + 1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j - 1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

// Josephus
int josephus(int n, int k)
{
    if (n == 1)
        return 0;
    if (k == 1)
        return n - 1;
    if (k > n)
        return (joseph(n - 1, k) + k) % n;
    int cnt = n / k;
    int res = joseph(n - cnt, k);
    res -= n % k;
    if (res < 0)
        res += n;
    else
        res += res / (k - 1);
    return res;
}

//Convex Hull--------------
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define MAX 1000000007
#define point pair<ll, ll>
#define x first
#define y second
point arr[105];
point r;
ll dist(point a, point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
ll orientation(point p, point a, point b) //1 for anticlockwise -1 for clockwise 0 for colinear
{
    point v1 = {a.x - p.x, a.y - p.y};
    point v2 = {b.x - p.x, b.y - p.y};
    point v1_rotated = {-v1.y, v1.x};
    ll dot = v2.x * v1_rotated.x + v2.y * v1_rotated.y;
    if (dot == 0)
        return 0;
    if (dot > 0)
        return 1;
    else
        return -1;
}
point nextToTop(stack<point> &S)
{
    point p = S.top();
    S.pop();
    point res = S.top();
    S.push(p);
    return res;
}
bool compare(point a, point b)
{
    ll dot = orientation(r, a, b);
    if (dot == 0)
    {
        if (dist(a, r) > dist(b, r))
            return 1;
        return 0;
    }
    if (dot > 0)
        return 1;
    else
        return 0;
}
int main()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i].x >> arr[i].y;
    sort(arr, arr + n);
    r = arr[0];
    sort(arr + 1, arr + n, compare);
    vector<point> v;
    v.push_back(arr[0]);
    //removing colinear points considering only the farthest point
    for (int i = 1; i < n; i++)
    {
        v.push_back(arr[i]);
        ll j = i + 1;
        while (j < n && orientation(r, arr[i], arr[j]) == 0)
            j++;
        i = j - 1;
    }
    if (v.size() < 3)
    {
        cout << "-1\n";
        return 0;
    }
    // Calculating Hull Here
    stack<point> st;
    st.push(v[0]);
    st.push(v[1]);
    st.push(v[2]);
    point last2 = v[1];
    for (int i = 3; i < v.size(); i++)
    {
        while (orientation(nextToTop(st), st.top(), v[i]) <= 0)
        {
            st.pop();
        }
        st.push(v[i]);
    }
    v.clear();
    while (!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i].x << " " << v[i].y << "\n";
    }
}

//Hull Trick Optimization
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
#define MAX 1000000007
#define quad pair<ll, ll>
#define x first
#define c second
ll n, c;
deque<quad> dq;
ll cost(quad q, ll y)
{
    return (q.x - y) * (q.x - y) + q.c;
}
bool chkdel(quad cur)
{
    quad q1 = dq[dq.size() - 1];
    quad q2 = dq[dq.size() - 2];
    bool f = ((cur.x - q2.x) * ((q1.c - q2.c) + q1.x * (q1.x - q2.x))) >= ((q1.x - q2.x) * ((cur.c - q2.c) + cur.x * (cur.x - q2.x)));
    return f;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> c;

    ll bp = 0, x;

    for (ll i = 0; i < n; i++)
    {
        cin >> x;
        quad q = {x, bp + c};

        while (dq.size() >= 2 && chkdel(q))
            dq.pop_back();
        dq.push_back(q);
        while (dq.size() > 1 && cost(dq[0], x) >= cost(dq[1], x))
            dq.pop_front();
        bp = cost(dq.front(), x);
    }
    cout << bp;
}

//dynamic Segment Tree
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
struct segtree
{
    segtree *left;
    segtree *right;
    ll val;
    ll ripe;
    segtree(segtree *l, segtree *r, ll v, ll ri) { left = l, right = r, val = v, ripe = ri; }
};
void update(segtree *root, ll l, ll r, ll ql, ll qr)
{
    if (root->ripe)
        return;
    if (r < ql || l > qr)
        return;
    if (l >= ql && r <= qr)
    {
        root->val = r - l + 1;
        root->ripe = 1;
        return;
    }
    if (root->right == NULL)
        root->right = new segtree(NULL, NULL, 0, 0);
    if (root->left == NULL)
        root->left = new segtree(NULL, NULL, 0, 0);
    ll mid = (l + r) / 2;
    update(root->left, l, mid, ql, qr);
    update(root->right, mid + 1, r, ql, qr);
    root->val = root->left->val + root->right->val;
    return;
}
ll query(segtree *root, ll l, ll r, ll ql, ll qr)
{

    if (r < ql || l > qr)
        return 0;
    if (l >= ql && r <= qr)
    {
        return root->val;
    }
    if (root->ripe)
    {
        if (l <= ql && r >= qr)
            return (qr - ql + 1);
        if (l <= ql && r <= qr)
            return r - ql + 1;
        if (r >= qr && l >= ql)
            return qr - l + 1;
    }

    ll ans = 0;
    ll mid = (l + r) / 2;
    if (root->left)
        ans += query(root->left, l, mid, ql, qr);
    if (root->right)
        ans += query(root->right, mid + 1, r, ql, qr);
    return ans;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    segtree *root = new segtree(NULL, NULL, 0, 0);
    ll c = 0;
    ll m;
    cin >> m;
    ll l = 1, r = 1000000010;
    while (m--)
    {
        ll t, x, y;
        cin >> t >> x >> y;
        x += c, y += c;
        if (t == 1)
        {
            c = query(root, l, r, x, y);
            cout << c << "\n";
        }
        else
        {
            update(root, l, r, x, y);
            // cout << root->val << "\n";
        }
    }
}

// TRIE
struct trie
{
    trie *next[26];
    bool end;
};
trie *root;
root = new trie();

// Set Comparator
class Compare
{
public:
    bool operator()(int a, int b)
    {

        return true; //logic
    }
};
//priority_queue<Foo,vector<Foo>, Compare> pq;
//comparator for set
struct lex_compare
{
    bool operator()(const int64_t &lhs, const int64_t &rhs) const
    {

        return s1.str() < s2.str(); //logic
    }
};
//set<int64_t, lex_compare> s;

// Game Theory
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vll vector<ll>
ll power(ll a, ll b, ll mod)
{
    ll c = 1;
    while (b > 0)
    {
        if (b % 2)
            c *= a, c %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return c;
}
#define MAX 1000000007
int calculateMex(unordered_set<int> Set)
{
    int Mex = 0;

    while (Set.find(Mex) != Set.end())
        Mex++;

    return (Mex);
}
int calculateGrundy(int n)
{
    if (n == 0)
        return (0);

    unordered_set<int> Set;

    Set.insert(calculateGrundy(n / 2));
    Set.insert(calculateGrundy(n / 3));
    Set.insert(calculateGrundy(n / 6));
    return (calculateMex(Set));
}

// DSU ON TREES
#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll, ll>
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
#define print(x) cout << #x << " is " << x << endl;
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

vll adj[1000050], *v[1000050];
ll n, cnt[1000050], level[1000050], ans[1000050], sub[1000050];

void getSize(ll x, ll pr)
{
    sub[x] = 1;
    f(0, adj[x].size()) if (adj[x][i] != pr) level[adj[x][i]] = level[x] + 1, getSize(adj[x][i], x), sub[x] += sub[adj[x][i]];
}

void dfs(ll x, ll pr, bool keep)
{
    ll heavy = -1, mx = -1;
    f(0, adj[x].size()) if (adj[x][i] != pr && sub[adj[x][i]] > mx) mx = sub[adj[x][i]], heavy = adj[x][i];
    f(0, adj[x].size()) if (adj[x][i] != pr && adj[x][i] != heavy) dfs(adj[x][i], x, 0);
    if (heavy != -1)
        dfs(heavy, x, 1), v[x] = v[heavy], ans[x] = ans[heavy];
    else
        v[x] = new vector<ll>();
    cnt[level[x]]++;
    v[x]->pb(x);
    if (cnt[level[x]] >= cnt[ans[x]])
        ans[x] = level[x];
    f(0, adj[x].size())
    {
        if (adj[x][i] != pr && adj[x][i] != heavy)
        {
            for (auto it : *v[adj[x][i]])
            {
                v[x]->pb(it);
                cnt[level[it]]++;
                if (cnt[level[it]] > cnt[ans[x]])
                    ans[x] = level[it];
                else if (cnt[level[it]] == cnt[ans[x]])
                    ans[x] = min(ans[x], level[it]);
            }
        }
    }
    if (keep == 0)
        for (auto it : *v[x])
            cnt[level[it]]--;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, y;
    cin >> n;
    f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
    getSize(1, -1);
    dfs(1, -1, 1);
    f(1, n + 1) cout << ans[i] - level[i] << "\n";

#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " s\n";
#endif
    return 0;
}

// EUCLID GCD
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}
int main()
{
    int x, y, a = 35, b = 15;
    int g = gcdExtended(a, b, &x, &y);
    cout << "GCD(" << a << ", " << b
         << ") = " << g << endl;
    return 0;
}

// EULER TOTIENT
void computeTotient(int n)
{
    long long phi[n + 1];
    for (int i = 1; i <= n; i++)
        phi[i] = i;
    for (int p = 2; p <= n; p++)
    {
        if (phi[p] == p)
        {
            phi[p] = p - 1;
            for (int i = 2 * p; i <= n; i += p)
                phi[i] = (phi[i] / p) * (p - 1);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << "Totient of " << i << " is "
             << phi[i] << endl;
}
int main()
{
    int n = 12;
    computeTotient(n);
    return 0;
}

//LIS – nlog(n)
const int inf = 2000000000; // a large value as infinity
int n;                      // the number of items in the sequence
int Sequence[32];           // the sequence of integers
int L[32];                  // L[] as described in the algorithm
int I[32];                  // I[] as described in the algorithm
void takeInput()
{
    scanf("%d", &n);            // how many numbers in the sequence ?
    for (int i = 0; i < n; i++) // take the sequence
        scanf("%d", &Sequence[i]);
}
int LisNlogK()
{          // which runs the NlogK LIS algorithm
    int i; // auxilary variable for iteration

    I[0] = -inf;             // I[0] = -infinite
    for (i = 1; i <= n; i++) // observe that i <= n are given
        I[i] = inf;          // I[1 to n] = infinite
    int LisLength = 0;       // keeps the maximum position where a data is inserted
    for (i = 0; i < n; i++)
    {                       // iterate left to right
        int low, high, mid; // variables to perform binary search
        low = 0;            // minimum position where we to put data in I[]
        high = LisLength;   // the maximum position
        while (low <= high)
        { // binary search to find the correct position
            mid = (low + high) / 2;
            if (I[mid] < Sequence[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
        // observe the binary search carefully, when the binary search ends
        // low > high and we put our item in I[low]
        I[low] = Sequence[i];
        if (LisLength < low) // LisLength contains the maximum position
            LisLength = low;
    }
    return LisLength; // return the result
}
int main()
{
    takeInput();
    int result = LisNlogK();
    printf("The LIS length is %d\n", result);
    return 0;
}

// Binary Exponentiation
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

//Linear Sieve
const int N = 10000000;
int lp[N + 1];
vector<int> pr;
for (int i = 2; i <= N; ++i)
{
    if (lp[i] == 0)
    {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
        lp[i * pr[j]] = pr[j];
}

// Segmented Sieve
void simpleSieve(int limit, vector<int> &prime)
{
    bool mark[limit + 1];
    memset(mark, true, sizeof(mark));

    for (int p = 2; p * p < limit; p++)
    {
        if (mark[p] == true)
        {
            for (int i = p * 2; i < limit; i += p)
                mark[i] = false;
        }
    }

    for (int p = 2; p < limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            cout << p << " ";
        }
    }
}
void segmentedSieve(int n)
{
    int limit = floor(sqrt(n)) + 1;
    vector<int> prime;
    simpleSieve(limit, prime);
    int low = limit;
    int high = 2 * limit;
    while (low < n)
    {
        if (high >= n)
            high = n;
        bool mark[limit + 1];
        memset(mark, true, sizeof(mark));
        for (int i = 0; i < prime.size(); i++)
        {
            int loLim = floor(low / prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
            for (int j = loLim; j < high; j += prime[i])
                mark[j - low] = false;
        }

        for (int i = low; i < high; i++)
            if (mark[i - low] == true)
                cout << i << " ";
        low = low + limit;
        high = high + limit;
    }
}

//Linear Diophantine Equation
int gcd(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g)
{
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g)
    {
        return false;
    }
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)
        x0 = -x0;
    if (b < 0)
        y0 = -y0;
    return true;
}
void shift_solution(int &x, int &y, int a, int b, int cnt)
{
    x += cnt * b;
    y -= cnt * a;
}
int find_all_solutions(int a, int b, int c, int minx, int maxx, int miny, int maxy)
{
    int x, y, g;
    if (!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;
    int sign_a = a > 0 ? +1 : -1;
    int sign_b = b > 0 ? +1 : -1;
    shift_solution(x, y, a, b, (minx - x) / b);
    if (x < minx)
        shift_solution(x, y, a, b, sign_b);
    if (x > maxx)
        return 0;
    int lx1 = x;
    shift_solution(x, y, a, b, (maxx - x) / b);
    if (x > maxx)
        shift_solution(x, y, a, b, -sign_b);
    int rx1 = x;
    shift_solution(x, y, a, b, -(miny - y) / a);
    if (y < miny)
        shift_solution(x, y, a, b, -sign_a);
    if (y > maxy)
        return 0;
    int lx2 = x;
    shift_solution(x, y, a, b, -(maxy - y) / a);
    if (y > maxy)
        shift_solution(x, y, a, b, sign_a);
    int rx2 = x;
    if (lx2 > rx2)
        swap(lx2, rx2);
    int lx = max(lx1, lx2);
    int rx = min(rx1, rx2);
    if (lx > rx)
        return 0;
    return (rx - lx) / abs(b) + 1;
}

// Area of Polygon
double area(const vector<point> &fig)
{
    double res = 0;
    for (unsigned i = 0; i < fig.size(); i++)
    {
        point p = i ? fig[i - 1] : fig.back();
        point q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}

// Pick's Theorm
// Given a certain lattice polygon with non - zero area. We denote its area by S, the number of points with integer coordinates lying strictly inside the polygon by I and the number of points lying on polygon sides by B.
// S = I + B / 2 − 1

// Number of divisors (CubeRoot N)
void SieveOfEratosthenes(int n, bool prime[], bool primesquare[], int a[])
{
    for (int i = 2; i <= n; i++)
        prime[i] = true;
    for (int i = 0; i <= (n * n + 1); i++)
        primesquare[i] = false;
    prime[1] = false;

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }
    int j = 0;
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
        {
            a[j] = p;
            primesquare[p * p] = true;
            j++;
        }
    }
}
int countDivisors(int n)
{
    if (n == 1)
        return 1;
    bool prime[n + 1], primesquare[n * n + 1];
    int a[n];
    SieveOfEratosthenes(n, prime, primesquare, a);
    int ans = 1;
    for (int i = 0;; i++)
    {
        if (a[i] * a[i] * a[i] > n)
            break;
        int cnt = 1;
        while (n % a[i] == 0) // if a[i] is a factor of n
        {
            n = n / a[i];
            cnt = cnt + 1; // incrementing power
        }
        ans = ans * cnt;
    }
    if (prime[n])
        ans = ans * 2;
    else if (primesquare[n])
        ans = ans * 3;
    else if (n != 1)
        ans = ans * 4;
    return ans; // Total divisors
}

// Enumerating all submasks
for (int s = m; s; s = (s - 1) & m)
{
}
// ... you can use s...

// Gray Code
int g(int n)
{
    return n ^ (n >> 1);
}
// Inverse gray code
int rev_g(int g)
{
    int n = 0;
    for (; g; g >>= 1)
        n ^= g;
    return n;
}

// NCK in O(K)
int C(int n, int k)
{
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

// Burnside
ll n, m, c;
ll power(ll x, ll a)
{
    if (a == 0)
        return 1;
    if (a == 1)
        return x;
    if (a % 2 == 0)
        return power((x * x) % M, a / 2);
    return (x * (power((x * x) % M, a / 2))) % M;
}
ll getburn(ll x)
{
    ll tot = 0;

    for (ll i = 1; i <= m; i++)
    {
        tot = (tot + power(x, __gcd(m, i))) % M;
    }

    return (tot * power(m, M - 2)) % M;
}
void solve()
{
    cin >> n >> m >> c;
    ll color = power(power(c, n), n);

    cout << getburn(color) << "\n";
}

// PBDS
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// find_by_order(k): It returns to an iterator to the kth element (counting from zero) in the set in O(logn) time.To find the first element k must be zero.
// Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
// *(s.find_by_order(2)) : 3rd element in the set i.e. 6
// *(s.find_by_order(4)) : 5th element in the set i.e. 88
// order_of_key(k) : It returns to the number of items that are strictly smaller than our item k in O(logn) time.
// Let us assume we have a set s : {1, 5, 6, 17, 88}, then :
// s.order_of_key(6) : Count of elements strictly smaller than 6 is 2.
// s.order_of_key(25) : Count of elements strictly smaller than 25 is 4.
