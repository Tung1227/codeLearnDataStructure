#include<iostream>
using namespace std;

int searchMin(int a[], int n){
    int min = 0;
    for(int i = 0; i < n; i++){
        if(min > a[i]) min = i;
    }
    return min;
}
int searchMax(int a[], int n){
    int max = 0;
    for(int i = 0; i < n; i++){
        if(a[max] < a[i]) max = i;
    }
    return max;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a[100001];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int k1 = searchMax(a,n);
    int k2 = searchMin(a,n);
    swap( &a[k1],&a[k2]);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    return 0;
}