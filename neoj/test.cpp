#include <bits/stdc++.h>
using namespace std;

int main(){
    auto l = [&](){
        return 1;
    };
    cout<<typeid(l).name()<<endl;
}