#pragma once
class Cell
{
public:
    int weight;//对应边的权值
    int coverd;//0表示未覆盖，1表示覆盖
    bool validity;//0表示边不存在，1表示存在
    Cell();
};

