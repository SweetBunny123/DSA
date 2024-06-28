#include<bits/stdc++.h>
using namespace std;

int count_it(int r){
    int count = 0;
    int x = 0;
    int y = r;
    while(x <= r){
        if(sqrt(pow(x, 2) + pow(y, 2)) < r+1){
            count += y;
            x++;
        }
        else{
            y--;
        }
    }
    return 4*count;
}

int main(){
    int test;
    cin >> test;
    for(int i = 0; i<test; i++){
        int r;
        cin >> r;
        cout << count_it(r) - count_it(r-1) << endl;
    }
    return 0;
}