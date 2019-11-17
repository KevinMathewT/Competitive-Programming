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

ll n, dp[100][100];
string a;

ll getNum(string s){
	ll j = 1;
	ll ret = 0;
	for(ll i=s.size()-1;i>=0;i--){
		ret += ((s[i] - '0') * j);
		j *= 2;
	}
	return ret;
}

void solve(){
	// cout << getNum("101001001") << "\n";
	cin >> n;
	cin.ignore(256, '\n');
	cin >> a;

	vector<char> tobin;

	ll t = n;
	while(t > 0){
		tobin.push_back('0' + (t % 2));
		t /= 2;
	}

	t = n;
	n--;

	string b = "";
	for(ll i=tobin.size() - 1;i>=0;i--){
		b.push_back(tobin[i]);
	}

	// cout << getNum(b) << " " << getNum(a) << "\n";

	if(getNum(b) >= getNum(a)){
		cout << 0 << "\n";
		return;
	}

	// cout << a << " " << b << "\n";

	ll p = 0, f = 0;
	for(ll i=0;i<b.size();i++){
		// cout << i << ' ' << p << "\n";
		if(p >= a.size())
			f = 1;
		if(b[i] == '1'){
			p++;
			continue;
		}

		while(p < a.size() && a[p] != '0')
			p++;
		p++;
		if(p >= a.size())
			f = 1;

		// cout << i << ' ' << p << " - \n";
	}


	if(f == 1)
		cout << (a.size() - b.size() + 1) << "\n";
	else
		cout << (a.size() - b.size()) << "\n";
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
