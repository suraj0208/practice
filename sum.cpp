#include <iostream>

using namespace std;

int main(){
    int arr[155]={1};


    int n;
    int j=0;
    int carry=0;
    cin>>n;

    for(int current=1;current<=n;current++){
        int i=current;
        j=0;

        while(i!=0){
            arr[j]=arr[j]*i;
            carry=arr[j]/10;


            arr[j]=arr[j]%10;

            cout<<"arr[j] "<<arr[j]<<endl;

            cout<<"carry "<<carry<<endl;
            j++;
            i/=10;
        }

        while(carry!=0)
        {
            arr[j++]=carry;
            carry/=10;
        }
    }

    while(carry!=0)
    {
        arr[j++]=carry;
        carry/=10;
    }


    for(int j=0;j<10;j++)
    {
        cout<<arr[j]<<endl;
    }

    return 0;
}
