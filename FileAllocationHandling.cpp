#include <bits/stdc++.h>
using namespace std;

stack<int> st;
int memory[61], randomGen[61];
map<string, int> um;

int main()
{
	freopen("input.txt", "r", stdin);		//Comment
	freopen("output.txt", "w", stdout);		//this out.

	srand(time(0));

	for(int i=60;i>=1;i--){
		randomGen[i-1] = i;
	}

	random_shuffle(randomGen, randomGen+60);

	for(int i=0;i<60;i++)
		st.push(randomGen[i]);

	for(int i=1;i<=60;i++)
		memory[i] = -2;

	int loop = 1;

	while(loop){
		string s;
		cin >> s;

		if(s == "break")
			break;

		int size;
		cin >> size;

		int start = st.top();
		st.pop();
		um[s] = start;

		for(int i=1;i<size;i++){
			int next = st.top();
			st.pop();
			memory[start] = next;
			start = next;
		}

		memory[start] = -1;
	}

	for(auto i : um){
		cout << i.first << ": ";
		int start = i.second;

		while(start != -1){
			cout << start << " ";
			start = memory[start];
		}
		cout << "\n";
	}

	return 0;
}