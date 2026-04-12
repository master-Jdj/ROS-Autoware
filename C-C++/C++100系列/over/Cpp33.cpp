//4位反序数，求N的9倍恰好式N的反序数

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    for (int i=1000; i<=9999; i++)
    {
        vector<int> num;
        int fan;
        num.push_back(i/1000);   
        num.push_back(i/100%10);
        num.push_back(i/10%10);
        num.push_back(i%10);
        fan = num[3]*1000 + num[2]*100 + num[1]*10 + num[0];
        if (i*9 == fan) cout << i << '\n';


    }

    return 0;
}
