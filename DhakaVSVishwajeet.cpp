#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;

void te(){
	cin >> s;
	ll moves = 0;

	stack<char> st;

	for(ll i=0;i<s.size();i++){
		if(st.size() > 0){
			if(st.top() == s[i]){
				// cout << s[i] << " ";
				st.pop();
				moves++;
				continue;
			}
		}

		st.push(s[i]);
	}
	// cout << "\n";

	// cout << moves << "\n";
	if(moves % 2 == 0)
		cout << "Vishwajeet beat Dhaka\n";
	else
		cout << "Dhaka beat Vishwajeet\n";
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