#include <iostream>
#include <stdlib.h>

using namespace std;

int cmp(const void *a, const void *b){

    return (*(int*)a)-*((int*)b);

}


int main(){
    int arr[] = {5,3,2,1,10,223,123,4};

    int n = sizeof(arr)/sizeof(arr[0]);

    qsort(arr,n,sizeof(n),cmp);


    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

    return 0;
}
