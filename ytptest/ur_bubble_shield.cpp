#include <bits/stdc++.h>
#define int long long
#define float double
using namespace std;
double round_double(double a, int precision){
    if(a<0){
        a *= -1;
        a *= pow(10,precision);
        a = round(a);
        a = a/(double)pow(10, precision);
        a = a*((double)-1);
    
    }else{
        a *= pow(10,precision);
        a = round(a);
        a = a/(double)pow(10, precision);
    }
    return a;
}
signed main(){
    vector<int> ai;
    int temp;
    while(cin>>temp){
        ai.push_back(temp);
    }
    int n = ai.size()-1;
    function<float(float)> f = [&](float xn){
        float ret = 0;
        float temp = 1;
        for(int i = 0; i<=n; i++){
            ret += ai[n-i]*temp;
            temp *= xn;
        }
        return ret;
    };
    function<float(float)> fprime = [&](float xn){
        float ret = 0;
        float temp = 1;
        float counter = 1;
        for(int i = 1; i<=n; i++){
            ret += ai[n-i]*temp*counter;
            counter+=1;
            temp *= xn;
        }
        return ret;
    };
    float x = 0;
    while(abs(f(x))>0.0001){
        x = x - f(x)/fprime(x);
    }
    cout<<fixed<<setprecision(2)<<round_double(x, 2)<<endl;


}