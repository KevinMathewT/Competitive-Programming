#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew

const int size = (int) 1e5+10000;
stack<ll> s;
vector<ll> graph[size];
vector<ll> revGraph[size];
ll vis[size];
ll revVis[size];
ll cost[size];
ll min_val = 0, cou1nt = 1, tot = 1;

void dfs(ll n){
	// cout << "POP HORA " << n << "\n";
	vis[n] = 1;
	for(ll i=0;i<graph[n].size();i++)
		if(vis[graph[n][i]] !=  1)
			dfs(graph[n][i]);
	// cout << "PUSH HORA " << n << "\n";
	s.push(n);
}

void revDfs(ll n){
	if(cost[n] == min_val) cou1nt++;
	min_val = min(cost[n], min_val);
	revVis[n] = 1;
	for(ll i=0;i<revGraph[n].size();i++)
		if(revVis[revGraph[n][i]] != 1)
			revDfs(revGraph[n][i]);
}

void showstack(stack<ll> gq)
{
    stack <ll> g = gq;
    while (!g.empty())
    {
        cout << g.top() << ' ';
        g.pop();
    }
    cout << '\n';
}

void te(){
	ll n; cin >> n;
	for(ll i=1;i<=n;i++) cin >> cost[i];
	ll m; cin >> m;
	
	for(ll i=0;i<m;i++){
		ll u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		revGraph[v].push_back(u);
	}

	// cout << "////////////\n";

	// for(ll i=1;i<=n;i++){
	// 	for(ll j=0;j<graph[i].size();j++)
	// 		cout << graph[i][j] << " ";
	// 	cout << "\n";
	// }

	// cout << "////////////\n";

	// for(ll i=1;i<=n;i++){
	// 	for(ll j=0;j<revGraph[i].size();j++)
	// 		cout << revGraph[i][j] << " ";
	// 	cout << "\n";
	// }

	// cout << "////////////\n";

	for(ll i=1;i<=n;i++)
		if(vis[i] != 1)
			dfs(i);

	// showstack(s);

	ll firstAns = 0;
	for(ll i=1;i<=n;i++){
		// cout << s.top() << " " << revVis[s.top()] << "\n";
		if(revVis[s.top()] != 1){
			// cout << s.top() << "\n";
			min_val = LLONG_MAX;
			cou1nt = 1;
			revDfs(s.top());
			firstAns += min_val;
			// cout << revVis[50] << "--\n";
			// cout << firstAns << "-\n";
			// cout << cou1nt << " is the count\n";
			tot *= cou1nt;
		}
		s.pop();
	}

	cout << firstAns << " " << tot << "\n";

	// ll tot = 0;
	// for(ll i=0;i<v.size();i++){
	// 	ll min_val = LLONG_MAX;
	// 	for(ll j=0;j<v[i].size();j++)
	// 		min_val = min(min_val, cost[v[i][j]]);
	// 	tot += min_val;
	// }

	// cout << tot << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}