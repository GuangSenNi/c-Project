#include <iostream>
#include <stack>
#include <map>
#include<string>
using namespace std;

int arr[26]={};
string jiao(string s1,string s2)
    {
       // cout<<s1<<"***"<<s2<<endl;
        for(int i=0;i<26;i++){
                arr[i]=0;
            }
        string sout="";
            for(int j=0;j<s1.length();j++){
                if(s1[j]>='a'&&s1[j]<='z'){
                    int temp=s1[j]-'a';
                    arr[temp]++;
                }
            }

            for(int j=0;j<s2.length();j++){
                if(s2[j]>='a'&&s2[j]<='z'){
                    int temp=s2[j]-'a';
                    if(arr[temp]>0){
                        arr[temp]=-1;
                    }
                }
            }
            for(int j=0;j<26;j++){
                if(arr[j]==-1){
                    char c=j+'a';
                    sout=sout+c;
                }
            }

            cout<<"����:"<<sout<<endl<<endl;
            return sout;

    }
    string bing(string s1,string s2)
    {
        for(int i=0;i<26;i++){
                arr[i]=0;
            }
        string sout="";
            for(int j=0;j<s1.length();j++){
                if(s1[j]>='a'&&s1[j]<='z'){
                    int temp=s1[j]-'a';
                    arr[temp]++;
                }
            }
            for(int j=0;j<s2.length();j++){
                if(s2[j]>='a'&&s2[j]<='z'){
                    int temp=s2[j]-'a';
                    arr[temp]++;
                }
            }
            for(int j=0;j<26;j++){
                if(arr[j]>0){
                    char c=j+'a';
                    sout=sout+c;
                }
            }
            cout<<"����:"<<sout<<endl<<endl;
            return sout;

    }
    string bu(string s1,string s2)
    {
        for(int i=0;i<26;i++){
                arr[i]=0;
            }
        string sout="";
            for(int j=0;j<s1.length();j++){
                if(s1[j]>='a'&&s1[j]<='z'){
                    int temp=s1[j]-'a';
                    arr[temp]++;
                }
            }
            for(int j=0;j<26;j++){
                if(arr[j]==0){
                    char c=j+'a';
                    sout=sout+c;
                }
            }
            cout<<"����:"<<sout<<endl<<endl;
            return sout;
    }
    string cha(string s1,string s2)
    {
        for(int i=0;i<26;i++){
                arr[i]=0;
            }
        string sout="";
            for(int j=0;j<s1.length();j++){
                if(s1[j]>='a'&&s1[j]<='z'){
                    int temp=s1[j]-'a';
                    arr[temp]++;
                }
            }
            for(int j=0;j<s2.length();j++){
                if(s2[j]>='a'&&s2[j]<='z'){
                    int temp=s2[j]-'a';
                    if(arr[temp]>0){
                        arr[temp]=0;
                    }
                }
            }
            for(int j=0;j<26;j++){
                if(arr[j]>0){
                    char c=j+'a';
                    sout=sout+c;
                }
            }
            cout<<"�:"<<sout<<endl<<endl;
            return sout;
    }
    string jisuan(string s1,string s2,int s3)
    {
        if(s3==3){
            //cout<<s1<<"***"<<s2<<endl;
            return jiao(s1,s2);
        }else if(s3==1){
            return bing(s1,s2);
        }else{
            return cha(s1,s2);
        }

    }
    void hunhe()
    {
        int fuhao[4]={0,1,1,2};
        stack<string> datastack;
        stack<int> caculatestack;
        caculatestack.push(0);
        string sout="";
        cout<< "�������ַ�������" << endl;
        int i;
        cin>>i;
        for(int j=0;j<i;j++){
            cout<< "�������ַ���" << j<<endl;
            string temp0="";
            cin>>temp0;

            if(j==i-1){

                //cout<<s4<<"#######"<<endl;
                //cout<<caculatestack.top()<<"#######"<<endl;
                string s5="";
                while(caculatestack.size()>1){
                    string s4=datastack.top();
                    s5=jisuan(s4,temp0,caculatestack.top());
                    datastack.pop();
                    caculatestack.pop();
                    temp0=s5;
                }

                cout<<"���"<<s5<<endl;
                return;
            }else{
                cout<<  "��ѡ����㷽ʽ:" << endl;
                cout<< "1������" << endl;
                cout<< "2������" << endl;
                cout<< "3���" << endl;
                int m;
                cin>>m;
                switch(m){
                    case 1:
                    {
                        int t1=fuhao[caculatestack.top()];
                        cout<<t1<<"########";
                        if(t1>=2){
                            string s4=datastack.top();
                            datastack.pop();
                            string s5=jisuan(s4,temp0,caculatestack.top());
                            datastack.push(s5);
                            caculatestack.push(3);
                        }else{
                            datastack.push(temp0);
                            caculatestack.push(3);
                        }
                        //cout<<datastack.top()<<"#######"<<endl;
                        //cout<<caculatestack.top()<<"#######"<<endl;
                        break;
                    }
                    case 2:
                        {
                        int t1=fuhao[caculatestack.top()];
                        if(t1>=1){
                             string s4=datastack.top();
                            datastack.pop();
                            string s5=jisuan(s4,temp0,caculatestack.top());
                            datastack.push(s5);
                            caculatestack.push(1);
                        }else{
                            datastack.push(temp0);
                            caculatestack.push(1);
                        }
                        break;
                        }

                    case 3:
                        {
                         int t1=fuhao[caculatestack.top()];
                        if(t1>=1){
                             string s4=datastack.top();
                            datastack.pop();
                            string s5=jisuan(s4,temp0,caculatestack.top());
                            datastack.push(s5);
                            caculatestack.push(2);
                        }else{
                            datastack.push(temp0);
                            caculatestack.push(2);
                        }
                        break;
                        }

                    default:
                        cout<<"�Ƿ����룬��ѡ��123"<<endl;
                        return;
                }
                //datastack.push(temp0);
            }
        }
    }

int main()
{

    string s1,s2;

    while(true){

        cout<<  "��ѡ����㷽ʽ:" << endl;
        cout<< "0���˳�" << endl;
        cout<< "1������" << endl;
        cout<< "2������" << endl;
        cout<< "3���" << endl;
        cout<< "4������" << endl;
        cout<< "5�������ַ���" << endl;
        cout<< "6���������" << endl;
        int i;
        cin>>i;

        switch(i)
        {
        case 0:
            return 0;
        case 1:
            jiao(s1,s2);
            break;
        case 2:
            bing(s1,s2);
            break;
        case 3:
            cha(s1,s2);
            break;
        case 4:
            bu(s1,s2);
            break;
        case 5:
            cout << "�������ַ���S1" << endl;
            cin>>s1;
            cout<< "�������ַ���S2" << endl;
            cin>>s2;
            break;
        case 6:
            hunhe();
            break;
        default:
            cout<<"�Ƿ����룬��ѡ��0123456"<<endl;
            break;
        }

        }
        return 0;
    }






