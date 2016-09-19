#include <iostream>

using namespace std;

int main(){
    int x,y;
    char c;
    string s;

    cin>>x>>y>>c>>s;

    char* cstr = (char*) s.c_str();

    /*
      | 1
      -> 2
      | 3
      <- 4
*/

    int dir;

    if(c=='N')
        dir=0;
    else if(c=='E')
        dir=1;
    else if(c=='S')
        dir=2;
    else if (c=='W')
        dir=3;

    for(int i=0;i<s.length();i++){
        if(cstr[i]=='L')
            dir=(dir-1+4)%4;
        else if (cstr[i]=='R')
            dir=(dir+1)%4;
        else{
            if(dir==0)
                y++;
            else if(dir==1)
                x++;
            else if(dir==2)
                y--;
            else
                x--;
        }
    }

    cout<<x<< " "<<y<<" ";

    switch (dir) {
    case 0:
        cout<<"N"<<endl;
        break;
    case 1:
        cout<<"E"<<endl;
        break;
    case 2:
        cout<<"S"<<endl;
        break;
    case 3:
        cout<<"W"<<endl;
        break;
    }

}
