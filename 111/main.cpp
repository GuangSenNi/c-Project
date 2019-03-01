#include <iostream>

using namespace std;

int main()
{
    int m=0;
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        int n=(int)str[i]-48;
        m=m+n*(str.size()-i);
        cout<<n;
    }

}
