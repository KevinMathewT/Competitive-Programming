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

string a, b;
ll fa[10], fb[10], temp[10];

string nextLarger(string s){
    ll i, j, n = s.size();
    for(i=n-1;i>0;i--)
        if(s[i] > s[i-1]) 
           break;
    if(i==0)
        return "-1"; 
    ll x = s[i-1], smallest = i; 
    for (j=i+1;j<n;j++) 
        if (s[j] > x && s[j] < s[smallest]) 
            smallest = j;
    swap(s[smallest], s[i-1]);
    sort(s.begin() + i, s.end());
    return s;
} 

void solve(){
	cin >> a >> b;
	sort(a.begin(), a.end());

	while(true){
		if(a == "-1" || stoll(a) > stoll(b)){
			cout << stoll(a) << "\n";
			return;
		}

		a = nextLarger(a);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.

	// solve();
	unsigned long long number = 18014398509481982; // example
	ll targetlevel = 0;
	while (number >>= 1) ++targetlevel;

	cout << targetlevel << "\n";

	return 0;
}