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

ll n;
ld f[1000], l[1000];
string names[1000];

void solve(){
	cin >> n;
	for(ll i=0;i<n;i++){
		string a, b;
		cin >> names[i];
		cin >> a;
		cin >> b;

		f[i] = stof(a);
		l[i] = stof(b);
	}

	ld best = 1000000000;
	vector<string> selected;

	for(ll i=0;i<n;i++){
		ld tot = f[i];
		vector<ll> curr;
		curr.clear();
		curr.push_back(i);
		vector<pair<ld, ll> > sec;
		sec.clear();

		for(ll j=0;j<n;j++)
			if(j != i)
				sec.push_back({l[j], j});

		sort(sec.begin(), sec.end());

		for(ll j=0;j<3;j++){
			curr.push_back(sec[j].second);
			tot += sec[j].first;
		}

		if(tot < best){
			best = tot;
			selected.clear();
			for(ll j=0;j<curr.size();j++)
				selected.push_back(names[curr[j]]);
		}
	}
	cout << best << "\n";
	for(ll i=0;i<selected.size();i++)
		cout << selected[i] << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();
	// cout << "Hello\n";

	return 0;
}