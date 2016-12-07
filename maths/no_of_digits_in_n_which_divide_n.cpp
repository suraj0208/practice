#include <iostream>

using namespace std;

int no_of_digits_in_n_which_divide_n(int n){
    int arr[10]={0};

    int bn=n;

    while(n){
        int curr = n%10;

        if(curr!=0 && bn%curr==0){
            arr[curr]+=1;
        }

        n/=10;

    }
    int count=0;

    for(int i=0;i<10;i++){
            count+=arr[i];
    }

    return count;

}


int main(){
    int n=122324;

    cout<<no_of_digits_in_n_which_divide_n(n)<<endl;

}
