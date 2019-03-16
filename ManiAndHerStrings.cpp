#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;
ll f;

void te(){
	cin >> s;
	cin >> f;

	stack<pair<char, ll>> st;

	for(ll i=s.size()-1;i>=0;i--){
		if(st.size() > 0 && s[i] == st.top().first){
			
			
			pair<char, ll> last = st.top();
			if((last.second+1) == f){
				for(ll k=0;k<f-1;k++)
                    st.pop();
			}
			else
				st.push(make_pair(last.first, last.second+1));
		}
		else{
			st.push(make_pair(s[i], 1));
		}
	}	

	ll size = st.size();
	for(ll i=0;i<size;i++){
		cout << st.top().first;
		st.pop();
	}

	cout << "\n";
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