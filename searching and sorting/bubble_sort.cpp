#include <iostream>

using namespace std;

void bubble_sort(int arr[],int n){
    bool issorted=false;

    for(int i=0;i<n-1;i++){
        issorted=true;

        for(int j=0;j<n-i-1;j++){

            if(arr[j]>arr[j+1]){
                issorted=false;
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }

        }

        if(issorted)
            break;

    }
}

int main(){
    int arr[] = {2,1,3,4,5,6,7,0,10};

    int n = sizeof(arr)/sizeof(arr[0]);

    bubble_sort(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}
