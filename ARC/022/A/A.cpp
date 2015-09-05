#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
	string str;
	cin >> str;
	int p = 0;
	for(int i=0;i<str.size();i++){
		if(p == 0 && (str[i] == 'I' || str[i] == 'i')){
			p++;
		}
		if(p == 1 && (str[i] == 'C' || str[i] == 'c')){
			p++;
		}
		if(p == 2 && (str[i] == 'T' || str[i] == 't')){
			p++;
		}
	}
	cout << (p == 3 ? "YES" : "NO") << endl;
	return 0;
}
