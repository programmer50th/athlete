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
        for (int j = 0; j < n; j++)
        {
            int min = container[0][j].weight;
            for (int i = 0; i < n; i++)
            {
                if (container[i][j].weight < min)
                    min = container[i][j].weight;
            }
            for (int i = 0; i < n; i++)
                container[i][j].weight -= min;
        }
    }
    else if (index == 2)//找未标记中的最小的
    {
        int min = 20000;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(container[i][j].coverd==0 && min>container[i][j].weight)
                    min=container[i][j].weight;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(container[i][j].coverd==0)
                    container[i][j].weight-=min;
                else if(container[i][j].coverd==2)
                    container[i][j].weight+=min;
            }
        }
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
            int index = 0;
            for (int j = 0; j < container[i].size(); j++)
            {
                if (container[i][j].weight == 0 && container[i][j].coverd == 0)
                {
                    index = j;
                    break;
                }
            }
            for (int i = 0; i < n; i++)
            {
                container[i][index].coverd++;
            }
        }
    }
    //find column
    for (int j = 0; j < n; j++)
    {
        int cnt=0;
        int index;
        for (int i = 0; i < n; i++)
        {
            if (container[i][j].weight == 0 && container[i][j].coverd == 0)
            {
                cnt++;
                index = i;
            }
        }
        if (cnt == 1)
        {
            cover(container[index]);
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

int Matrix::getNum()
{
    int num=0;
    for(int i=0;i<n;i++)
        num+=container[i][i].coverd;
    return num;
}