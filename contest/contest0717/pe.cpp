#include <bits/stdc++.h>
using namespace std;
/*


1 2 4 5 6 7 8 9 


*/
signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, k, e;
    cin >> n >> k >> e;
    int f = n-k-e;



    if(k!=e&&k!=f&&e!=f){
        cout<<0<<endl;
    }

    if(k==e&&e<f){
        if(e-1>1){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
    }
    if(k==f&&f<e){
        if(f-1>1){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
    }

    if(e==f&&f<k){
        if(f-1>1||k==n){
            cout<<0<<endl;
        }else{
            cout<<1<<endl;
        }
    }

    if(k<e&&e==f){
        if(e>=5){
            cout<<0<<endl;
        }else{
            if(e==4){
                if(k==2){
                    cout<<0<<endl;
                }else{
                    cout<<1<<endl;
                }
            }
            if(e==3){
                cout<<k<<endl;
            }
            if(e==2){
                cout<<2<<endl;
            }
        }
    }

    if(e<k&&k==f){
        if(f>=5){
            cout<<0<<endl;
        }
        if(f==4){
            if(e==2){
                cout<<0<<endl;
            }else{
                cout<<1<<endl;
            }
            
        }
        if(f==3){
            cout<<e<<endl;
        }
        if(f==2){
            cout<<2<<endl;
        }
        
        
    }

    if(f<k&&k==e){
        if(e>=5){
            cout<<0<<endl;
        }
        if(e==4){
            if(f==2){
                cout<<0<<endl;
            }else{
                cout<<1<<endl;
            }
            
        }
        if(e==3){
            cout<<f<<endl;
        }
        if(e==2){
            cout<<2<<endl;
        }
    }
    
    if(k==f&&f==e){
        if(k>=5){
            cout<<0<<endl;
        }else{
            if(k==4){
                cout<<2<<endl;
            }
            if(k==3){
                cout<<3<<endl;
            }
            if(k==2){
                cout<<3<<endl;
            }
            if(k==1){
                cout<<2<<endl;
            }
        }
        
    }


    // int eo = e; int fo = f;
    // vector<int> tileso(n+1);
    // vector<int> tiles(n+1);
    // for(int i = 0; i<=n; i++){
    //     tiles[i] = i;
    // }
    // int ans;
    // tiles[k] = 0;
    // tileso = tiles;
    // int index = e;
    // while(e>0&&index>0){
    //     if(e-tiles[index]>0){
    //         e -= tiles[index];
    //         tiles[index] = 0;
    //     }else if(e-tiles[index]==0){
    //         e -= tiles[index];
    //         tiles[index] = 0;
    //         break;
    //     }
        
    //     index--;
    // }
    // index = f;
    // while(f>0&&index>0){
    //     if(f-tiles[index]>0){
    //         f -= tiles[index];
    //         tiles[index] = 0;
    //     }else if(f-tiles[index]==0){
    //         f -= tiles[index];
    //         tiles[index] = 0;
    //         break;
    //     }
        
    //     index--;
    // }
    // ans = e+f;
    // f = fo;
    // e = eo;
    // tiles = tileso;
    // index = f;
    // while(f>0&&index>0){
    //     if(f-tiles[index]>0){
    //         f -= tiles[index];
    //         tiles[index] = 0;
    //     }else if(f-tiles[index]==0){
    //         f -= tiles[index];
    //         tiles[index] = 0;
    //         break;
    //     }
        
    //     index--;
    // }

    // index = e;
    // while(e>0&&index>0){
    //     if(e-tiles[index]>0){
    //         e -= tiles[index];
    //         tiles[index] = 0;
    //     }else if(e-tiles[index]==0){
    //         e -= tiles[index];
    //         tiles[index] = 0;
    //         break;
    //     }
        
    //     index--;
    // }
    // ans = min(e+f, ans);
    
    // cout<<ans<<endl;
    
    
}