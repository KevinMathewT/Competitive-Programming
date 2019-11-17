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

ll n, intime[1000], outtime[1000], vis[1000], shor, star;
vector<ll> graph[1000];
vector<ll> shortest, curr;
map<string, ll> name;
map<ll, string> rev;

void dfs(ll u){
	// cout << star << " " << u << " --> ";
	// for(ll i=0;i<graph[u].size();i++)
	// 	cout << graph[u][i] << " ";
	// cout << "\n";
	vis[u] = 1;
	curr.push_back(u);

	for(ll v : graph[u]){
		if(vis[v] != 1)
			dfs(v);
		if(v == star){
			// cout << u << " " << v << " " << star << "\n";
			// cout << curr.size() << "\n";
			if(curr.size() < shor){
				shor = curr.size();
				shortest.clear();
				for(ll i=0;i<curr.size();i++)
					shortest.push_back(curr[i]);
			}
		}
	}

	curr.pop_back();
}

void solve(){
	shor = LLONG_MAX;
	shortest.clear();
	cin >> n;
	for(ll i=0;i<n;i++){
		string s;
		cin >> s;
		name[s] = i;
		rev[i] = s;
	}

	for(ll i=0;i<n;i++){
		string st;
		cin >> st;
		ll m;
		cin >> m;

		// cout << st << " " << m << " " << name[st] << "--\n";

		cin.ignore(256, '\n');

		for(ll i=0;i<m;i++){
			string s;
			getline(cin, s);

			s = s.substr(7, s.size() - 7);

			ll start = 0;
			for(ll i=0;i<s.size();i++){
				if(s[i] == ','){
					graph[name[st]].push_back(name[s.substr(start, i - start)]);
					if(st == s.substr(start, i - start)){
						cout << st << "\n";
						return;
					}
					start = i + 2;
				}
			}
			graph[name[st]].push_back(name[s.substr(start, s.size() - start)]);
			if(st == s.substr(start, s.size() - start)){
				cout << st << "\n";
				return;
			}
		}
	}

	for(ll i=0;i<n;i++){
		// cout << "--------\n";
		star = i;
		fill(vis, vis + n, 0);
		fill(intime, intime + n, 0);
		fill(outtime, outtime + n, 0);
		curr.clear();
		dfs(i);
	}

	if(shor == LLONG_MAX)
		cout << "SHIP IT";
	else
		for(ll i=0;i<shortest.size();i++)
			cout << rev[shortest[i]] << " ";

	cout << "\n";
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}