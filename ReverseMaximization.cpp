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

string s;

string reverse(string s){
	string ret = "";
	ll flag = 0;

	for(ll i=s.size()-1;i>=0;i--){
		if(s[i] == '0' && flag == 0)
			continue;
		flag = 1;
		ret.push_back(s[i]);
	}

	return ret;
}

string trim(string s){
	string ret = "";
	ll flag = 0;

	for(ll i=0;i<s.size();i++)
		if(s[i] == '0' && flag == 0)
			continue;
		else{
			flag = 1;
			ret.push_back(s[i]);
		}

	return ret;
}

void solve(){
	cin >> s;

	string ns = s;

	if(s.size() == 1){
		cout << s << "\n";
		return;
	}

	vector<pair<ll, string> > ret(0);
	ret.push_back(make_pair(reverse(s).size(), reverse(s)));

	ns[0] -= 1;

	for(ll i=1;i<s.size();i++){
		ns[i] = '9';
	}

	ns = trim(ns);

	// cout << s << "-\n";

	ret.push_back(make_pair(reverse(ns).size(), reverse(ns)));

	ns = s;
	ll flag = 0;
	for(ll i=1;i<s.size();i++){
		if(flag){
			ns[i] = '9';
			continue;
		}
		if(s[i] != '0'){
			ns[i] = ns[i] - 1;
			flag = 1;
			continue;
		}
		ns[i] = s[i];
	}

	ret.push_back(make_pair(reverse(ns).size(), reverse(ns)));

	sort(ret.begin(), ret.end());

	cout << ret[2].second << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	ll T;
	cin >> T;
	while(T--)
		solve();

	return 0;
}