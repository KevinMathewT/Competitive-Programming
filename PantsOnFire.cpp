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

ll n, m, cnt, vis[1000];
vector<ll> graph[100010];
map<string, ll> mp;

ll dfs(ll a, ll b){
	vis[a] = 1;

	ll ret = 0;

	for(ll v : graph[a]){
		if(v == b){
			ret = 1;
			break;
		}
		if(vis[v] == 0)
			ret = ret | dfs(v, b);
	}

	return ret;
}

void solve(){
	cnt = 0;
	cin >> n >> m;
	cin.ignore(256, '\n');
	for(ll i=0;i<n;i++){
		string s;
		getline(cin, s);
		string a, b;
		// cout << s << "\n";

		for(ll i=0;i<s.size();i++)
			if(s[i] == ' '){
				a = s.substr(0, i);
				break;
			}


		for(ll i=s.size()-1;i>=0;i--)
			if(s[i] == ' '){
				b = s.substr(i+1, s.size() - i - 1);
				break;
			}

		// cout << a << " " << b << "\n";

		if(mp.find(a) == mp.end())
			mp[a] = cnt++;
		if(mp.find(b) == mp.end())
			mp[b] = cnt++;

		graph[mp[a]].push_back(mp[b]);
	}

	for(ll i=0;i<m;i++){
		string s;
		getline(cin, s);
		string a, b;

		for(ll i=0;i<s.size();i++)
			if(s[i] == ' '){
				a = s.substr(0, i);
				break;
			}


		for(ll i=s.size()-1;i>=0;i--)
			if(s[i] == ' '){
				b = s.substr(i+1, s.size() - i - 1);
				break;
			}

		// cout << a << ' ' << b << "\n";

		if(mp.find(a) == mp.end() || mp.find(b) == mp.end()){
			cout << "Pants on Fire\n";
			continue;
		}

		fill(vis, vis + 1000, 0);

		if(dfs(mp[a], mp[b])){
			cout << "Fact\n";
			continue;
		}

		fill(vis, vis + 1000, 0);
		if(dfs(mp[b], mp[a])){
			cout << "Alternative Fact\n";
			continue;
		}

		cout << "Pants on Fire\n";
	}
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