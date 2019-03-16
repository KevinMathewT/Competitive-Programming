#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Author - Kevin Mathew
// Birla Institute of Technology, Mesra

string s;
vector<ll> moves;
vector<ll> states;
ll possibilities[1000][2];

void te(){
	moves.clear();
	states.clear();
	cin >> s;

	ll winOrLose = 0;
	ll last = -1;

	for(ll i=0;i<s.size();i++)
		if(s[i] == '.'){
			last = i;
			break;
		}

	if(last == -1){
		cout << "No\n";
		return;
	}

	for(ll i=last;i<s.size();i++){
		if(s[i] == 'P'){
			moves.push_back(i-last);
			last++;
		}
	}

	if(moves.size() == 0){
		cout << "No\n";
		return;
	}

	for(ll i=0;i<moves.size();i++){
		ll a = (moves[i] % 3);
		states.push_back(a);
	}
	// for(ll i=0;i<moves.size();i++)
	// 	cout << states[i] << " " ;
	// cout << "\n";
	if(states[states.size()-1] == 2){
		cout << "Yes\n";
		return;
	}

	for(ll i=states.size()-2;i>=0;i--){
		if(states[i] == 2){
			ll curr = 0;
			for(ll j=i+1;j<states.size();j++){
				if(states[j] == 2){
					if(possibilities[i][0] == possibilities[i][1])
						if(curr == 0)
							possibilities[i][0] = possibilities[i][1] = possibilities[i][0];
						else
							possibilities[i][0] = possibilities[i][1] = 1 - possibilities[i][0];

					else
						
				}
				if(curr == 0)
					curr = states[i];
				else
					curr = 1 - states[i];
			}
		}
	}

	if(states[states.size()-1])
		cout << "Yes\n";
	else
		cout << "No\n";
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