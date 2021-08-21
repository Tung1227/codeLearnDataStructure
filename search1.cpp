#include<iostream>
using namespace std;

void search(int a[], int n){
    int count = 0;
    for(int i =0; i < n; i+=2){
        if(a[i]&1){
            cout << a[i] << " ";
            count++;
        }
    }
    if(count == 0) cout << "NULL";
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    search(a,n);
    return 0;
}