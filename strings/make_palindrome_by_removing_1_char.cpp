#include <iostream>
using namespace std;

bool isPalindrome(string s,int low,int high){
   while(low<high && s[low]==s[high]){
       low++;
       high--;
   }

   if(low>=high)
       return true;

   return false;

}

int canMakePalindrome(string s){
    int low =0;
    int high  = s.length()-1;

    while(low<high){

        if(s[low]==s[high]){
            low++;
            high--;
        }else{

            if(isPalindrome(s,low+1,high))
                return low;

            if(isPalindrome(s,low,high-1))
                return high;


            return -1;
        }

    }

    if(low==high)
        return low;

    return -2;

}


int main(){
    string str = "abecbea";

    cout<<canMakePalindrome(str)<<endl;

    return 0;
}
