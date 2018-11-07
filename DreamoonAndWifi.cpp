#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll fact(ll n){
	if(n == 0) return 1;
	if(n == 1) return 1;
	return n * fact(n-1);
}

void te(){
	string s1, s2;
	cin >> s1;
	cin >> s2;

	ll p1 = 0, m1 = 0, p2 = 0, m2 = 0, q = 0;
	
	for(ll i=0;i<s1.size();i++){
		if(s1[i] == '+')
			p1++;
		if(s1[i] == '-')
			m1++;
	}

	for(ll i=0;i<s1.size();i++){
		if(s2[i] == '+')
			p2++;
		if(s2[i] == '-')
			m2++;
		if(s2[i] == '?')
			q++;
	}

	if(p2 > p1 || m2 > m1){
		cout << 0.000000000000 << "\n";
		return;
	}

	ll p = p1 - p2, m = m1 - m2;
	ll num = fact(p + m);
	ll den = fact(p) * fact(m);

	ld prob = ((ld) num / (ld) den) / ((ld) pow(2, p + m));

	cout << prob << "\n";
}

int main()
{
	// freopen("input.txt", "r", stdin);		//Comment
	// freopen("output.txt", "w", stdout);		//this out.
	ios::sync_with_stdio(false);			//Not
	cin.tie(NULL);							//this.
	cout.tie(0);							//or this.
	cout << fixed << setprecision(12);

	te();

	return 0;
}