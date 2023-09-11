#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    int i, k, c = 0, l = str.length();
    vector<int> r;
    stringstream s(str);
    char ch;
    for(i=0;i<l;i++){
        if(str[i] == ','){
            c++;            
        }
    }
    for(i=0;i<c+1;i++){
        s >> k >> ch;
        r.push_back(k);
    }
    return r;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

