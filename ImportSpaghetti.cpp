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

ll n, intime[1000], outtime[1000], vis[1000], shor;
vector<ll> graph[1000];
vector<ll> shortest, curr;
map<string, ll> name;
map<ll, string> rev;

void dfs(ll u, ll time){
	// cout << u << " " << shor << " -> ";
	// for(ll i=0;i<curr.size();i++)
	// 	cout << curr[i] << " ";
	// cout << "\n";
	vis[u] = 1;
	intime[u] = time;
	curr.push_back(u);

	for(ll v : graph[u]){
		if(vis[v] == 0)
			dfs(v, time + 1);
		if(vis[v] == 1){
			// cout << "\n" << u << " " << v << " " << intime[u] << " " << intime[v] << "\n";
			if((intime[u] - intime[v]) < shor){
				shor = (intime[u] - intime[v]);
				// cout << "------------\n";
				// cout << u << "\n";
				// cout << v << ' ' << u << "\n";
				// cout << intime[v] << " " << intime[u] << "\n";

				shortest.clear();
				shortest.push_back(v);
				for(ll i=curr.size()-1;i>=0;i--)
					if(curr[i] == v)
						break;
					else
						shortest.push_back(curr[i]);

				// cout << shor << "\n";
				// for(ll i=0;i<shortest.size();i++)
				// 	cout << shortest[i] << " ";
				// cout << "\n";
				// cout << "------------\n";
			}
		}
	}

	vis[u] = 2;
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

	cin.ignore(256, '\n');

	for(ll i=0;i<n;i++){
		string inp, st;
		getline(cin, inp);
		ll m;

		for(ll i=0;i<inp.size();i++){
			if(inp[i] == ' '){
				st = inp.substr(0, i);
				m = stoll(inp.substr(i + 1, inp.size() - i - 1 + 1));
				break;
			}
		}

		// cout << inp << " " << st << " " << m << "\n";

		for(ll i=0;i<m;i++){
			string s;
			getline(cin, s);

			s = s.substr(7, s.size() - 7);

			ll start = 0;
			for(ll i=0;i<s.size();i++){
				if(s[i] == ','){
					graph[name[s.substr(start, i - start)]].push_back(name[st]);
					if(st == s.substr(start, i - start)){
						cout << st << "\n";
						return;
					}
					start = i + 2;
				}
			}
			graph[name[s.substr(start, s.size() - start)]].push_back(name[st]);
			if(st == s.substr(start, s.size() - start)){
				cout << st << "\n";
				return;
			}
		}
	}

	for(ll i=0;i<n;i++){
		fill(vis, vis + n, 0);
		fill(intime, intime + n, 0);
		fill(outtime, outtime + n, 0);
		curr.clear();
		dfs(i, 0);
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
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}