#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string s;
    string m;

    cin>>s;
    cin>>m;

    int arr[256]={0};

    for(int i=0;i<m.length();i++){
        arr[m[i]]=1;
    }

    for(int i=0;i<s.length();i++)
        if(!arr[s[i]])
            cout<<s[i];

    cout<<endl;

    return 0;
}
