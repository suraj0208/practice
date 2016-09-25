#include <iostream>

using namespace std;

void findfreq(int arr[],int freq[],int low,int high){

    if(low>high)
        return;

    if(arr[low]==arr[high]){
        freq[arr[low]]+=high-low+1;
        return;
    }
    int mid = (low+high)/2;

    findfreq(arr,freq,low,mid);
    findfreq(arr,freq,mid+1,high);


}

int main(){
    int arr[]={ 1,1,1,2,3,3,5,5,8,8,8,9,9,10 };
    int freq[20] = {0};

    findfreq(arr,freq,0,(sizeof(arr)/sizeof(arr[0]))-1);

    for(int i=0;i<10;i++)
        cout<<i<<" "<<freq[i]<<endl;

    return 0;

}
