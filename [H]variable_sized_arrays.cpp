#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q, i, j, s, t;
    scanf("%d %d",&n,&q);
    vector<vector<int>> a;
    for(i=0;i<n;i++){
        vector<int> v1;
        scanf("%d",&s);
        for(j=0;j<s;j++){
            scanf("%d",&t);
            v1.push_back(t);
        }
        a.push_back(v1);
    }
    for(t=0;t<q;t++){
        scanf("%d %d",&i,&j);
        cout << a[i][j] << endl;
    }
    return 0;
}

