#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define SZ 200010

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n, m, a[SZ], depth[SZ], vis[SZ], startEven[SZ], endEven[SZ], startOdd[SZ], endOdd[SZ];
ll bitEven[SZ], bitOdd[SZ];
vector<ll> graph[SZ], odd, even;

void dfs(ll x, ll d){
	vis[x] = 1;
	depth[x] = d;
	// cout << x << "--\n";
	if(d % 2 == 0){
		startEven[x] = even.size();
		startOdd[x] = odd.size();
		even.push_back(x);
	}
	else{
		startEven[x] = even.size();
		startOdd[x] = odd.size();
		odd.push_back(x);
	}

	for(ll i=0;i<graph[x].size();i++)
		if(vis[graph[x][i]] != 1){
			dfs(graph[x][i], 1 + d);
		}

	if(d % 2 == 0){
		endEven[x] = even.size();
		endOdd[x] = odd.size();
	}
	else{
		endEven[x] = even.size();
		endOdd[x] = odd.size();
	}
}

void updateEven(ll x, ll val){
	for(;x<=even.size();x+=(x&-x))
		bitEven[x] += val;
}

void updateOdd(ll x, ll val){
	for(;x<=odd.size();x+=(x&-x))
		bitOdd[x] += val;
}

ll queryEven(ll x){
	ll sum = 0;
	for(;x>0;x-=(x&-x))
		sum += bitEven[x];
	return sum;
}

ll queryOdd(ll x){
	ll sum = 0;
	for(;x>0;x-=(x&-x))
		sum += bitOdd[x];
	return sum;
}

void te(){
	for(ll i=0;i<SZ;i++)
		vis[i] = 0;
	cin >> n >> m;
	for(ll i=1;i<=n;i++)
		cin >> a[i];

	for(ll i=0;i<n-1;i++){
		ll u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, 1);

	// for(ll i=0;i<even.size();i++)
	// 	cout << even[i] << " ";
	// cout << "\n----\n";

	// for(ll i=0;i<odd.size();i++)
	// 	cout << odd[i] << " ";
	// cout << "\n----\n";

	for(ll i=0;i<SZ;i++){
		bitEven[i] = 0;
		bitOdd[i] = 0;
	}

	// for(ll i=1;i<=n;i++){
	// 	cout << i << " " << startEven[i] << " " << endEven[i] << " " << startOdd[i] << " " << endOdd[i] << "\n";
	// }

	while(m--){
		ll ch;
		cin >> ch;
		// cout << ch << " ";

		if(ch == 2){
			ll x;
			cin >> x;
			// cout << x << "--\n";

			if(depth[x] % 2 == 0){
				cout << a[x] + queryEven(startEven[x]+1) << "\n";
			}
			else{
				cout << a[x] + queryOdd(startOdd[x]+1) << "\n";
			}
		}
		else{
			ll x, val;
			cin >> x >> val;
			// cout << x << " " << val << "----\n";

			if(depth[x] % 2 == 0){
				updateEven(startEven[x]+1, val);
				updateEven(endEven[x]+1, -val);
				updateOdd(startOdd[x]+1, -val);
				updateOdd(endOdd[x]+1, val);
			}
			else{
				updateEven(startEven[x]+1, -val);
				updateEven(endEven[x]+1, val);
				updateOdd(startOdd[x]+1, val);
				updateOdd(endOdd[x]+1, -val);	
			}
		}
	}
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