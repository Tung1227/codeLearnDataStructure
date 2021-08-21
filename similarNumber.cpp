#include<iostream>
using namespace std;

int search(int a[], int n, int x){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == x) count++;
    }
    return count;
}
int main() {
    int n, x;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> x; 
    cout << search(a,n,x);
    return 0;
}