#include<iostream>
using namespace std;

int binarySearch(int a[], int n, int x){
    int mid, l = 0, r = n -1;
    if(n == 1) if(a[0] == x) return 0;
    while(l < r ){
        mid = (l + r)/2;
         if(a[mid] < x){
             l = mid + 1;
        }else{ r = mid ;}
    }
    if(a[l] == x) return l;
    return -1;
}
int main(){
    int n, x;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> x;
    cout << binarySearch(a,n,x);
    return 0;
}