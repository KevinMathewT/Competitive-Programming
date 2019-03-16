#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll firstNotSame(string s1, string s2){
	for(ll i=0;i<min(s1.size(), s2.size());i++)
		if(s1[i] != s2[i])
			return i;

	return -1;
}

void te(){
	ll n, m;
	cin >> n >> m;

	unordered_map<string, string> u_map;

	for(ll i=0;i<n;i++){
		string s;
		cin >> s;
		for(ll j=1;j<=s.size();j++){
			// cout << s.substr(0, j) << " " << s << "\n";
			if(u_map[s.substr(0, j)] == "")
				u_map[s.substr(0, j)] = s;
		}
	}

	while(m--){
		string query;
		cin >> query;

		priority_queue<pair<ll, string> > q;
		q.push(make_pair(1, query.substr(0, 1)));

		while(!q.empty()){
			pair<ll, string> p = q.top();
			q.pop();
			string s = p.second;
			ll moves = p.first;

			cout << s << " " << moves << "\n";
			if(moves > 10)
				break;

			if(s == query){
				cout << "\n" << moves << "\n";
				break;
			}

			if(firstNotSame(s, query) != -1){
				q.push(make_pair(moves+1, s.substr(0, s.size()-1)));
			}

			// pos = s.size();
			//tab

			// cout << s << "-\n";

			// cout << u_map[s] << "\n";
			if(u_map[s] != ""){
				q.push(make_pair(moves+1, u_map[s]));
			}

			if(firstNotSame(s, query) == -1)
				q.push(make_pair(moves+1, query.substr(0, firstNotSame(s, query))));
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	te();

	return 0;
}