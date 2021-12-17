#include "Matrix.h"
using namespace std;
int main()
{
    int n;
    cout << "Input the number of athletes:";
    cin >> n;
    Matrix m(n);
    cout << "Input the weight M to F\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            m.container[i][j].weight = temp;
        }
    }
    Matrix f(n);
    cout << "Input the weight F to M\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            f.container[i][j].weight = temp;
        }
    }
    m.dotMul(f);
    m.print();
    //todo

    return 0;
}
