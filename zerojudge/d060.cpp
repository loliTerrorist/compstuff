#include <bits/stdc++.h>
using namespace std;
int main(){
    int m; cin >> m;
    //m<=25 -> 25-m
    //m>=25 -> 25+60-m
    int x = (25-m>=0)?(25-m):(85-m);
    cout<<x<<endl;
}