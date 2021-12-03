/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct point{
    int x;
    int y;
};

//below is a function of type struct point
struct point edit(struct point *p){
    (p->x)++;
    p->y=p->y + 5;
    return *p;
}

void print(struct point *p){
    cout<<p->x<<" "<<p->y<<endl;
}

int main()
{
    struct point p1= {23, 45};
    struct point p2= {56, 90};
    p1 = edit(&p1);
    p2 = edit(&p2);
    print(&p1);
    print(&p2);
    return 0;
}
