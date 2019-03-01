#include <iostream>
#include <stdio.h>
#include<string>
#include<algorithm>
using namespace std;

void T1001()
{
    double a,b,c;
    while(scanf("%lf %lf",&a,&b)!=EOF)
    {
        c=a+b;
        printf("%.4lf\n",c);
    }
}

struct grades
{
    int grades;
    string name;
};

bool cmp1(grades i,grades j)
{
    return i.grades<j.grades;
}

bool cmp2(grades i,grades j)
{
    return i.grades>j.grades;
}
int main()
{
   int n,h,g,i=0;
    cin>>n;
    cin>>h;
    string str;
    grades *l=new grades[n];
    while(cin>>str>>g)
    {
        l[i].name=str;
        l[i].grades=g;
        i++;
    }
    if(h==1)
        sort(l,l+n,cmp1);
    else
        sort(l,l+n,cmp2);
    for(int t=0;t<n;t++){
        cout<<l[t].name<<" "<<l[t].grades<<endl;
    }
    return 0;
}
