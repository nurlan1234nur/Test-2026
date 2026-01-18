#include <iostream>
using namespace std;

//linear search
int linearSearcher( int a[], int size){
    
    int number;
    cout << "haih too:";
    cin >> number;
    if(size == 0) return -1;
    for (int i = 0; i < size; i++){
        if( number == a[i]) return i; 
    }

    return -1;
}

//hoyrtiin hailt
int binarySearch(int a[], int size){

    int number, left = 0, right = size - 1;
    cout << "Haih toog oruulna uu: " << endl;
    cin >> number;

    while(left <= right){
        int mid = left + (right -left)/ 2;
        if(number == a[mid]){
            return mid;
        }
        else if(number < a[mid]){
            right = mid - 1;
        }
        else left = mid + 1;
    }
    return 0;

}


int main(){
    int size;
    cout <<"size: "<< endl;
    cin >> size;

    if(size == 0){
        cout << " array hooson!!";
        return 0;
    }

    int *a = new int[size];

    cout <<"Elementuud: "<< endl;

    for(int i = 0; i < size;i++)  cin >> a[i]; 
    

    cout << "Odoo haina"<< endl;

    int n = binarySearch(a, size);
    
    if(!n)
        cout << "ene too oldsongui!!";
    else
        cout << "Oldson";


    delete[] a;
  
    return 0;
}
