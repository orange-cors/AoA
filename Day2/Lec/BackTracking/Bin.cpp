#include <iostream>
using namespace std;

int n;
int a[100];

void quaylui(int i){
    
    for(int j=0;j<=1;j++){
        
        a[i]=j;
        
        if(i==n){
            for(int k=1;k<=n;k++)
                cout<<a[k];
            cout<<endl;
        }
        else{
            quaylui(i+1);
        }
        
    }
}

int main(){
    
    cin>>n;
    
    quaylui(1);
}