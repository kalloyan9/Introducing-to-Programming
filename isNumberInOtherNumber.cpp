///sudurja li se edno chislo v drugo by recursion
#include<iostream>
using namespace std;

bool isInside(int a, int b)
{
    if(a==b) return true;
    if(a==0) return false;

    if(b%10 == a%10)
    {
        return isInside(a/10, b/10);
    }
    else return isInside(a/10, b);

}

int main()
{
    int a,b;
    cin >> a >>b;
    int max = a>b?a:b;
    int min = a<b?a:b;
    cout<<isInside(max,min);

    return 0;
}
