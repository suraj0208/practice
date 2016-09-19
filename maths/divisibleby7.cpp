#include <iostream>
using namespace std;


int main(){
    int i;

    for(int i=1;i<142;i++){
        int n=i;

        n=(n<<3)-n;


        if(n&1)
            continue;

        int sum=0;

        int bk=n;

        while(n!=0){
            sum+=n%10;
            n/=10;
        }

        if(sum!=7)
            continue;

        cout<<bk<<endl;
    }

    return 0;
}
