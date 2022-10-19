#include <bits\stdc++.h>
using namespace std;

bool is_operand(char p){
	if (p=='/' || p=='*' ||p=='+' || p=='-' || p=='(' ||p==')') return false;
	else return true;
}

int priority (char p){
	if ( p=='(' ||p==')') return 0;
	else if ( p=='/' ||p=='*') return 2;
	else if ( p=='+' ||p=='-') return 1;

}
int main(){
	int t;
    cin >> t;
    for (int q = 0; q < t; q++){
		string s;
		cin>>s;
		// s = "7*(9-1)/5*4-2";
	// cout<<"hihi";
// 	return 0;
		int i=0;
		vector <char> v;
		stack<char> st;
		// cout<<s;
		bool inbrac=false;
		while (s[i]!='\0'){
			if (is_operand(s[i])){
				v.push_back(s[i]);
			}
			else {
				if(st.empty() || s[i]=='(' || priority(s[i])>priority(st.top())) st.push(s[i]);
				// else if (s[i]=='('){
				// 	st.push(s[i]);
				// 	inbrac=true
				// }
				else if (s[i]==')'){
					while(st.top()!='('){
						v.push_back(st.top());
						st.pop();
					}
					st.pop();
				}
				else if (!st.empty() && priority(s[i])<=priority(st.top())){
					while (!st.empty() && priority (st.top())>=priority(s[i])){
						v.push_back(st.top());
						st.pop();
					}
					st.push(s[i]);
				}
			}
			i++;

		}
		while (!st.empty()){
			v.push_back(st.top());
			st.pop();
		}
		for (char val:v){
			cout<<val;
		}
		cout<<'\n';
	}
	return 0;
}