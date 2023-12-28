//randomly generate the 2, 4
int RandomNum();
//randomly set the place
int RandomPlace();
//generate the number in the place
void GenerateNum(int vacantOrder[], int range);
//count the amount of 0
int VacantAmount(int vacantOrder[16], int indexVacant);
//check if combinable
bool IfCombinable();
//check if reach 2048
bool If2048();


//inlines
inline int PlaceToOrder(int row, int col)
{
    return (row) * 4 + col;
}

inline int OrderToRow(int order)
{
    return order / 4;
}

inline int OrderToCol(int order)
{
    return order % 4;
}