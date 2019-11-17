#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
 
// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew?
 
ll n, m, a[110], b[110], graph[500][500], s, t, p[500];
 
ll flow(){
    queue<ll> q;
    q.push(s);
 
    while(!q.empty()){
        ll u = q.front(); q.pop();
 
        for(ll i=0;i<n+m+2;i++)
            if(graph[u][i] == 1 && p[i] == -1){
                q.push(i), p[i] = u;
                if(i == t)
                    return 1;
            }
    }
 
    return 0;
}
 
void solve(){
    cin >> n;
    for(ll i=0;i<n;i++)
        cin >> a[i];
    cin >> m;
    for(ll i=0;i<m;i++)
        cin >> b[i];
 
    for(ll i=0;i<n+m+2;i++)
        for(ll j=0;j<n+m+2;j++)
            graph[i][j] = 0;
 
    s = n + m;
    t = n + m + 1;
 
    for(ll i=0;i<m;i++)
        for(ll j=0;j<n;j++)
            if(b[i] % a[j] == 0)
                graph[j][n + i] = 1;
 
    for(ll i=0;i<n;i++)
        graph[s][i] = 1;
    for(ll j=0;j<m;j++)
        graph[n + j][t] = 1;
 
    fill(p, p + n + m + 10, -1);
    ll ans = 0;
 
    while(flow() == 1){
        ll v = t;
 
        while(v != s){
            graph[p[v]][v]--;
            graph[v][p[v]]++;
            v = p[v];
        }
 
        ans++;
        fill(p, p + n + m + 10, -1);
    }
 
    cout << ans << "\n";
}
 
int main()
{
    freopen("input.txt", "r", stdin);        //Comment
    freopen("output.txt", "w", stdout);      //this out.
    ios::sync_with_stdio(false);            //Not
    cin.tie(NULL);                          //this.
    cout.tie(0);                            //or this.
 
    ll T;
    cin >> T;
    for(ll i=1;i<=T;i++){
        cout << "Case " << i << ": ";
        solve();
    }
 
    return 0;
}