#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int k;
    cin >> n >> k;
    string s;
    cin >> s;

    if(k==0){
        string rev=s;
        reverse(rev.begin(),rev.end());
        if(rev==s)
            cout<<s;
        else
            cout<<-1;
        return 0;
    }


    int i=n/2-1;
    int j;

    if(n%2)
        j=i+2;
    else
        j=i+1;


    int diff=0;

    while(i>=0 && j<n){
        if(s[i]!=s[j])
            diff++;
        i--;
        j++;

    }

    if(k<diff){
        cout<<-1<<endl;
        return 0;
    }



    i=0;
    j=n-1;

    while(i<j && k>0){
        if(s[i]==s[j]){
            if(s[i]!='9'){
                if((k-2)>=(diff-1) && k>1 ){
                    s[i]='9';
                    s[j]='9';
                    k-=2;
                }
            }
        }else{
            if((k-2)>=(diff-1)){
                if(s[i]=='9'||s[j]=='9')
                    k-=1;
                else
                    k-=2;

                s[i]='9';
                s[j]='9';

                diff--;
            }else{
                int max=fmax(s[i],s[j]);
                s[i]=max;
                s[j]=max;
                k--;
                diff--;
            }
        }


        i++;
        j--;

    }



    if(k>0 && n%2)
        s[n/2]='9';
    cout<<s<<endl;



    return 0;
}
