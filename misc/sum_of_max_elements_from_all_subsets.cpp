#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

/* An efficient solution is based on one thing, how many subsets of array have a particular element
as their maximum. As in above example, four subsets have 5 as their maximum,
two subsets have 3 as their maximum and one subset has 2 as its maximum.
The idea is to compute these frequencies corresponding to each element of array.
Once we have frequencies, we can just multiply them with array values and sum them all,
which will lead to our final result.
To find frequencies, first we sort the array in non-increasing order
and when we are standing at a[i] we know, all element from a[i + 1] to a[N-1] are smaller than a[i],
so any subset made by these element will choose a[i] as its maximum so count of such subsets
corresponding to a[i] will be, 2^(N – i – 1) (total subset made by array elements from a[i + 1] to a[N]).
If same procedure is applied for all elements of array, we will get our final answer */

int sum_of_max_elements_from_all_subsets(int arr[],int n){
    sort(arr,arr+n,greater<int>());

    int sum = 0;

    for(int i=0;i<n;i++){

        sum=sum+arr[i]*pow(2,n-i-1);

    }
    return sum;

}

int main(){
    int arr[] = {3,2,5};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<sum_of_max_elements_from_all_subsets(arr,n)<<endl;


    return 0;
}
