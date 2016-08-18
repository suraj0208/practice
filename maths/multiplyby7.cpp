#include <iostream>
#include <cmath>

using namespace std;

int mulby7(int n){
    return (n<<3)-n;

}

int main(){
    int n;
    cin>>n;

    cout<<mulby7(n)<<endl;
}
