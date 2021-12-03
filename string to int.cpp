#include <iostream>
#include <sstream>
using namespace std;

int main()
{
   int c;
   cout<<"enter the thing to be evaluated "<<endl;
   cin>>c;
   string str;

   stringstream s;
   s<<c;
   s>>str;
   int i = 0;
   int n = 0;

   while(str[i]){
       n = n + str[i]-48;
       i++;
   }

    cout<<"the sum of the two values is "<<n;
    return 0;
}
