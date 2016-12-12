/*
 * Given a matrix of distinct values and a sum. The task is to find all the pairs in
 * whose summation is equal to given sum. Each element of pair must be from different rows
 * i.e; pair must not lie in same row.
 * */

#include <iostream>
#include <algorithm>

using namespace std;

void printPairs(int* mat, int m, int n,int sum){

    for(int i=0;i<m;i++)
        sort(mat+i*n,mat+i*n+n);

    int left;
    int right;
    int curr_sum;

    for(int i=0;i<m;i++){
        left=i*n;

        for(int j=i+1;j<m;j++){
            int next=j*n;

            int l_off=0;
            int r_off=n-1;

            while(l_off<n && r_off>=0){
                int curr_sum = *(mat+left+l_off)+*(mat+next+r_off);

                if(curr_sum<sum)
                    l_off++;
                else if(curr_sum>sum)
                    r_off--;
                else{
                    cout<<*(mat+left+l_off)<<" "<<*(mat+next+r_off)<<endl;
                    l_off++;
                    r_off--;
                }
            }
        }
    }
}

int main(){
    int arr[][4] = {{1, 3, 2, 4},
                    {5, 8, 7, 6},
                    {9, 10, 13, 11},
                    {12, 0, 14, 15}};

    printPairs((int*)arr,4,4,11);


    return 0;
}
