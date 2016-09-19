#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>

using namespace std;

int main(){
    int n;
    int m;

    cin>>n>>m;

    ostringstream ss;
    ss<<n;

    string s = ss.str();


    int i=0;

    ostringstream right;

    while(i<m){
        right<<0;
        i++;
    }
    int j=0;


    while(i<s.length()){
        right<<s[j];
        j++;
        i++;
    }
    cout<<right.str()<<endl;

     i=0;

    ostringstream left;


    while((m+i)<s.length()){
        left<<s[m+i];
        i++;
    }

    while(i<s.length()){
        left<<0;
        i++;
    }

    cout<<left.str()<<endl;

    double temp;
    char s1[20];
    sscanf("1234.567","%s",s1);

    cout<<s1<<endl;


    return 0;
}
