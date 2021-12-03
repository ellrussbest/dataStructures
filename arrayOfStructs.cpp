/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
struct student{
    int age;
    string name;
};

int main()
{
    int n;
    cout<<"please enter the number of students that are in the class "<<endl;
    cin>>n;
    struct student *arr = new struct student [n];
    cout<<"please enter the age and name of the students respectively "<<endl;
    
    for(int i=0; i<n; i++){
        cin>>(arr+i)->age;
        cin>>(arr+i)->name;
    }
    
    cout<<"the age and name of these students are "<<endl;
    for(int i=0; i<n; i++){
        cout<<(arr+i)->age;
        cout<<" ";
        cout<<(arr+i)->name;
        cout<<endl;
    }
    
    delete [] arr;

    return 0;
}
