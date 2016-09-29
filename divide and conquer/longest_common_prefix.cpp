#include <iostream>

using namespace std;

string findCommon(string left,string right){
    int i=0;

    string res;

    while(i<left.length() && i<right.length()){
        if(left[i]!=right[i])
            break;

        res.push_back(left[i]);
        i++;
    }
    return res;

}

string findprefix(string arr[],int low,int high){
    if(low>high)
        return string("");

    if(low==high)
        return arr[low];


    int mid= (low+high)/2;
    string left = findprefix(arr,0,mid);
    string right = findprefix(arr,mid+1,high);

    return findCommon(left,right);

}


int main(){
    string arr[] =  { "abcd", "abcdef", "abchjl","abklk"};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<findprefix(arr,0,n-1)<<endl;

    return 0;

}
