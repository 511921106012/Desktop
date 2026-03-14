/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    reverse(v.begin(), v.end());

    for (int x : v)
        cout << x << " ";

    return 0;
}*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> v = {1,2,4,3};
    sort(v.begin(), v.end(), greater<int>());

    for(int x : v)
    cout << x << " ";
    return 0;
}