/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main(){
    int n, *p, sum=0, i;
    cout<<"enter the number of people that are going to be in the class"<<endl;
    cin>>n;
    p= new int[n];
    cout<<"key in the number of each person"<<endl;
    
    if(p==NULL){
        cout<<"the memory has not been allocated"<<endl;
        exit(1);
    }
    
    for(i=0;i<n;i++){
        cin>>*(p+i);
    }
    cout<<"the numbers that you entered are "<<endl;
    
    for(i=0;i<n;i++){
        cout<<*(p+i)<<endl;
    }
    cout<<endl;
    cout<<"the sum of those number are ";
    for(i=0;i<n;i++){
        sum+=*(p+i);
    }
    cout<<sum<<endl;
    delete []p;
    return 0;
}
