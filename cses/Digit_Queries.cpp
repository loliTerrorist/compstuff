#include <bits/stdc++.h>
#define int unsigned long long
#define pb push_back
using namespace std;
//1~9, 10~99, 100~999, 1000~9999, 10^n~ 10^(n+1)-1
//(10^1-10^0)*1, (10^2-10^1)*2...
//9, 90, 900, 
signed main(){
    // freopen("C:\\Users\\user\\Downloads\\test_input (5).txt", "r", stdin);
    int q; cin>>q;
    while(q--){
        int k; cin>>k;
        int tenpow = 0;
        int tenpownumcum=0;

        auto mypow = [](int a, int b){
            int ans = 1;
            for(int i = 0; i<b; i++){
                ans*=a;
            }
            return ans;
        };
        
        //mypow(base, power)
        // function<int(int,int)> mypow = [&](int a, int b){
        //     int ans = 1;
        //     if(b==0){
        //         return (int)1;
        //     }else{
        //         if(b%2){
        //             int temp = mypow(a,b/2);
        //             ans = a*temp*temp;
        //         }else{
        //             int temp = mypow(a,b/2);
        //             ans = temp*temp;
        //         }
        //     }

        //     return ans;
        // };
        
        for(int i = 0; tenpownumcum+(mypow(10,i+1)-mypow(10,i))*(i+1)<k; i+=1){
            tenpow++;
            tenpownumcum+=(mypow(10,i+1)-mypow(10,i))*(i+1);
        }
        //11
        k-=(tenpownumcum); //tenpownumcum = 9
        
        //k = 2
        if(tenpow==0){
            cout<<k<<endl;
        }else{  
            k--; //k=1
            // 100101102103104105106107108
            // 123456789012345678901234567 (digits starting from tenpownumcum)
            // 012345678901234567890123456 
            // 0         1         2      
            // 0  1  2  3  4  5  6  7  8  
            //starting from 10^tenpow, how many digits till k
            //numbers of digits per one number = tenpow+1
            //find which number k falls in
            int number = mypow(10,tenpow)+k/(tenpow+1);
            // find which digit in that number                   1095102592571150092
            k %= (tenpow+1); 
            //108
            //012
            //tenpow, tenpow-1, ..., 0
            int numbertenpow = 0;
            int numbertenpowval = 1;
            for(; numbertenpowval<=number; numbertenpowval*=10){
                numbertenpow++;
            }
            numbertenpow--;
            int ans = number%(mypow(10, numbertenpow+1-k))/mypow(10,numbertenpow-k);
            cout<<ans<<endl;
        }
        

       

    }
}