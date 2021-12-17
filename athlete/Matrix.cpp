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
    if (index == 0)//找行最小的
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
    else if (index == 1)//找列最小的
    {

    }
    else if (index == 2)//找未标记中的最小的
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

void Matrix::findZero()
{
    //find row
    for (int  i = 0; i < n; i++)
    {
        if (countZero(container[i]) == 1)
        {
            cover(container[i]);
        }
    }
    
}

int countZero(vector<Cell> ls)
{
    int n = 0;
    for (int i = 0; i < ls.size(); i++)
    {
        if (ls[i].weight == 0&&ls[i].coverd == 0)
            n++;
    }
    return n;
}

void cover(vector<Cell> &ls)
{
    for (int i = 0; i < ls.size(); i++)
    {
        ls[i].coverd++;
    }
}
