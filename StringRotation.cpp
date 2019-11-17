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

string s, s1, t;

void solve(){
	cin >> s;
	t = s;

	ll curr = 0;

	ll q;
	cin >> q;
	while(q--){
		char c;
		ll rot;
		cin >> c >> rot;
		rot = rot % s.size();
		// cout << c << " " << rot << " " << s.size() << "\n";

		if(c == 'L'){
			for(ll i=0;i<rot;i++){
				// cout << t << "\n";
				char ch = t[0];
				// cout << ch << " ";
				t = t.substr(1, t.size() - 1);
				t.push_back(ch);
				// cout << t << "\n";
			}
		}
		if(c == 'R'){
			for(ll i=0;i<rot;i++){
				// cout << rot << " ";
				// cout << t << "-\n";
				char hg[1];
				string u;
				u.push_back(t[t.size() - 1]);
				// cout << hg[0] << " ";
				t = t.substr(0, t.size() - 1);
				// cout << t << "\n";
				// cout << u << "\n";
				t = u + t;
				// cout << t << "-\n";
			}
		}

		// cout << "\n";
		// cout << curr << "\n";

		s1.push_back(t[0]);
	}

	cout << s1 << " " << s << "\n";
	ll a[26], b[26];

	for(ll i=0;i<26;i++)
		a[i] = b[i] = 0;
	for(ll i=0;i<s.size();i++)
		a[s[i] - 'a']++;
	for(ll i=0;i<s1.size();i++)
		b[s1[i] - 'a']++;

	bool ans = true;
	for(ll i=0;i<26;i++)
		if(a[i] != b[i])
			ans = false;

	if(ans)
		cout << "YES\n";
	else
		cout << "NO\n";
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