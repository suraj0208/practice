#include <iostream>
#include <climits>
using namespace std;

struct minmax{
    int min;
    int max;
};

minmax findminmax(int arr[],int n){
    minmax temp;

    int i=0;

    if(n&1){
        temp.max=arr[0];
        temp.min=arr[0];
        i++;
    }else{

        if(arr[0]>arr[1]){
            temp.max=arr[0];
            temp.min=arr[1];
        }else{
            temp.max=arr[1];
            temp.min=arr[0];
        }
        i+=2;
    }

    while(i<n-1){
        if(arr[i]>arr[i+1]){

            if(arr[i]>temp.max)
                temp.max=arr[i];

            if(arr[i+1]<temp.min)
                temp.min=arr[i+1];

        }else{

            if(arr[i+1]>temp.max)
                temp.max=arr[i+1];

            if(arr[i]<temp.min)
                temp.min=arr[i];

        }

        i+=2;
    }

    return temp;
}


int main(){
    int arr[]={ 1000,11,445,1,330,3000 };

    int n = sizeof(arr)/sizeof(arr[0]);

    minmax mm = findminmax(arr,n);

    cout<<mm.max<<" "<<mm.min<<endl;
    return 0;

}
