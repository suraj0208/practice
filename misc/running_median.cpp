#include <iostream>
#include <stdio.h>

using namespace std;


class MaxHeap{

public:
    int *a;
    int n;

    MaxHeap(int s){
        a=new int[s];
        n=0;
    }

    void heapify1( int i){
        int right = i*2+2;

        int left = i*2+1;

        int max=left;

        if(right<=n){
            if(a[right]>a[max]){
                max=right;
            }
        }

        if(left>n){
            max=i;
        }

        if(a[i]<a[max]){
            int temp=a[max];
            a[max]=a[i];
            a[i]=temp;
            heapify1(max);
        }

    }

    void heapify( int i){
        int right = i*2+2;

        int left = i*2+1;

        int max=left;

        if(right<=n){
            if(a[right]>a[max]){
                max=right;
            }
        }

        if(left>n){
            max=i;
        }

        if(a[i]<a[max]){
            int temp=a[max];
            a[max]=a[i];
            a[i]=temp;
            heapify((i-1)/2);
        }

    }

    void insert(int x){
        a[n]=x;

        heapify((n-1)/2);
        n++;
    }

    int extractMax(){
        int max = a[0];

        n--;

        a[0]=a[n];


        heapify1(0);

        return max;
    }


};

class MinHeap{

public:
    int *a;
    int n;

    MinHeap(int s){
        a=new int[s];
        n=0;
    }

    void heapify1( int i){
        int right = i*2+2;

        int left = i*2+1;

        int min=left;

        if(right<=n){
            if(a[right]<a[min]){
                min=right;
            }
        }

        if(left>n){
            min=i;
        }

        if(a[i]>a[min]){
            int temp=a[min];
            a[min]=a[i];
            a[i]=temp;
            heapify1(min);
        }

    }

    void heapify( int i){
        int right = i*2+2;

        int left = i*2+1;

        int min=left;

        if(right<=n){
            if(a[right]<a[min]){
                min=right;
            }
        }

        if(left>n){
            min=i;
        }

        if(a[i]>a[min]){
            int temp=a[min];
            a[min]=a[i];
            a[i]=temp;
            heapify((i-1)/2);
        }

    }

    void insert(int x){
        a[n]=x;

        heapify((n-1)/2);
        n++;
    }

    int extractMin(){
        int min = a[0];

        n--;

        a[0]=a[n];


        heapify1(0);

        return min;
    }


};




float handleQuery(float prev,int next,MaxHeap& maxheap,MinHeap& minheap){

    if(next>prev){
        if(minheap.n>maxheap.n){
            maxheap.insert(minheap.extractMin());
        }

        minheap.insert(next);
    }else{
        if(maxheap.n>minheap.n){
            minheap.insert(maxheap.extractMax());
        }
        maxheap.insert(next);
    }

    if((maxheap.n+minheap.n)%2==0){


        float l = maxheap.a[0];
        float r = minheap.a[0];

        return (l+r)/2;

    }else{

        if(maxheap.n>minheap.n)
            return maxheap.a[0];

        return minheap.a[0];
    }


}

int main(){
    int s;
    cin >> s;
    int temp;

    int *arr = new int[s];

    MaxHeap maxheap(s);
    MinHeap minheap(s);

    float prev=0;

    for(int a_i = 0;a_i <s;a_i++){
        cin >>arr[a_i];
    }

    if(s<2){
        printf("%.1f\n",(float)arr[0]);
        return 0;
    }

    if(arr[1]>arr[0]){
        maxheap.insert(arr[0]);
        minheap.insert(arr[1]);
    }else{
        maxheap.insert(arr[1]);
        minheap.insert(arr[0]);
    }

    printf("%.1f\n",(float)arr[0]);

    prev=(float)(arr[0]+arr[1])/2;

    printf("%.1f\n",prev);

    for(int i=2;i<s;i++){
        prev=handleQuery(prev,arr[i],maxheap,minheap);
        printf("%.1f\n",prev);

    }

    return 0;
}
