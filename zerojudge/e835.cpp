#include <iostream>
using namespace std;
int main(){
    int x; cin>>x;
    int area, row, seat;
    //表演分為三大區，每區共有 100 排：一、三大區為普通區各有 2,500 席，每排各有 25 人。 第二大區為搖滾區有 5,000 席，每排各有 50 人。編號按照大區順序，由第一區開始由左至右、 由前至後，再接續第二、三大區。
    //area 1, 3: num row = 100, seats per row = 25, 
    if(x>2500){
        if(x-2500>5000){
            area = 3;
            x-=2500;
            x-=5000;
            row = (x-1)/25+1;
            x-=(row-1)*25;
            seat = x;
        }else{
            area = 2;
            x-=2500;
            row = (x-1)/50+1;
            x-=(row-1)*50;
            seat = x;
        }
    }else{
        area = 1;
        row = (x-1)/25+1;
        seat = x-25*(row-1);

    }
    cout<<area<<" "<<row<<' '<<seat<<endl;
    //2 93 50
    //2500+93*50+50
}