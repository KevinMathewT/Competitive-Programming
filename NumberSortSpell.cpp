#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;

// Kevin Mathew T
// Birla Institute of Technology, Mesra
// GitHub - https://github.com/KevinMathewT
// CodeForces - https://codeforces.com/profile/KevinMathew
// CodeChef - https://www.codechef.com/users/KevinMathew
// HackerRank - https://www.hackerrank.com/KevinMathew

string ones[] = { "", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ",  "Sixteen ", "Seventeen ", "Eighteen ",  "Nineteen " };
string tens[] = { "", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety " };

inline std::string trim(const std::string &s){
   auto wsfront = find_if_not(s.begin(), s.end(), [](int c) { return isspace(c); });
   auto wsback = find_if_not(s.rbegin(), s.rend(), [](int c) { return isspace(c); }).base();
   return (wsback <= wsfront ? string() :string(wsfront, wsback));
}

string d2w(ll n, string s) { 
    string t = "";
    if (n > 19)
        t += tens[n / 10] + ones[n % 10]; 
    else
        t += ones[n];
    if (n) 
        t += s;
    return t; 
}

string n2w(ll n){
    string ret;  
    ret += d2w(((n / 1000) % 100), "Thousand ");
    ret += d2w(((n / 100) % 10), "Hundred ");
    ret += d2w((n % 100), "");
    return ret;
}

ll a, b;

bool sameOrNot(string a, string b){
	bool ret = true;
	if(a.size() != b.size())
		return false;
	for(ll i=0;i<(ll)a.size();i++)
		if(a[i] != b[i])
			return false;

	return true;
}

void solve(){
	cin >> a >> b;
		
	while(true){
		if(a == b){
			cout << a;
			return;
		}

		ll c, d;

		string s[2];
		if(a == 0)
			s[0] = "Zero";
		else
			s[0] = trim(n2w(a));

		if(b == 0)
			s[1] = "Zero";
		else
			s[1] = trim(n2w(b));

		// cout << s[0] << "\n" << s[1] << "\n";

		sort(s, s + 2);
		if(sameOrNot(trim(n2w(a)), s[1])){
			c = b;
			d = a;
		}
		else{
			c = a;
			d = b;
		}

		a = a + c;
		b = b + d;

		if(a > 99999 || b > 99999){
			cout << "Out of bounds";
			return;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this ret.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	solve();

	return 0;
}