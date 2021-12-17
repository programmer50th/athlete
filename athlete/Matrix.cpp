#include "Matrix.h"

Matrix::Matrix(int n)
{
    this->n = n;
    container.resize(n);
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        it->resize(n);
    }
}

void Matrix::dotMul(Matrix m)
{
    auto itm = m.container.begin();
    for (auto it = container.begin(); it != container.end(); ++it)
    {
        auto im = itm->begin();
        for (auto i = it->begin(); i != it->end(); ++i)
        {
            i->weight = i->weight * im->weight;
            ++im;
        }
        ++itm;
    }
}

void Matrix::findMin(int index)
{
    if (index == 0)//������С��
    {
        for (int i = 0; i < n; i++)
        {
            int min = container[i][0].weight;
            for (int j = 0; j < n; j++)
            {
                if (container[i][j].weight < min)
                    min = container[i][j].weight;
            }
            for (int j = 0; j < n; j++)
                container[i][j].weight -= min;
        }

    }
    else if (index == 1)//������С��
    {

    }
    else if (index == 2)//��δ����е���С��
    {

    }

}
void Matrix::print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << container[i][j].weight << " ";
        }
        cout << endl;

    }
}