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
            if (temp == 0)
            {
                m.container[i][j].weight = temp;
                m.container[i][j].validity = false;
            }
            else
            {
                m.container[i][j].weight = temp;
            }
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
            if (temp == 0)
            {
                f.container[i][j].weight = temp;
                f.container[i][j].validity = false;
            }
            f.container[i][j].weight = temp;
        }
    }
    m.dotMul(f);
    //m.print();
    m.findMin(0);
    m.findMin(1);
    while (true)
    {
        m.findZero();
        m.print();
        if (m.getNum() >= n)
            break;
        if (m.anyZeroLeft())
            m.uncoverFind();
        else
            m.findMin(2);
        m.print();
    }
    m.print();
    m.output();
    return 0;
}
