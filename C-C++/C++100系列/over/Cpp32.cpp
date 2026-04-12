//求数，在1-500中，找出同时满足用/3···2  和 用/5···3的数 和 用/7···2的数

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> num;
    vector<int> temp;
    
    for (int i=1;i+2<=500;i++)
        num.push_back(3*i+2);
    for (int i=0;i<num.size();i++)
        if (num[i]%5==3) temp.push_back(num[i]);
    for (int i=0;i<temp.size();i++)
        if (temp[i]%7==2) cout << temp[i] << '\n';
        


    return 0;
}



















