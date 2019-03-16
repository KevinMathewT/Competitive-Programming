#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

ll n; string ans;
ll rem[20000];

ll getRem(string s){
	ll remainder = 0;
	// for(ll i=0;i<s.size();i++)
	// 	cout << s[i] - '0' << "\n";
	for(ll i=0;i<s.size();i++)
		remainder = ((remainder * 10) + (s[i] - '0')) % n;

	// cout << remainder << "\n";
	return remainder;
}

void te(){
	cin >> n;
	// for(ll i=0;i<=20000;i++)
	// 	rem[i] = 0;

	queue<string> q;
	q.push("1");

	while(!q.empty()){
		string t = q.front();
		q.pop();

		ll remainder = getRem(t);
		if(remainder == 0){	
			cout << t << "\n";
			return;
		}

		if(rem[remainder] == 0){
			rem[remainder] == 1;
			q.push(t + "0");
			q.push(t + "1");
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

	ll T;
	cin >> T;
	while(T--)
		te();

	return 0;
}