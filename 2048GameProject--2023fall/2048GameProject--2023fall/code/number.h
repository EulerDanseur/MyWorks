#pragma once
//the transformation between orders and coordinates
int PlaceToOrder(int row, int col);

int OrderToRow(int order);

int OrderToCol(int order);


//randomly generate a 2 or 4
int RandomNum();

//randomly generate a order
int RandomOrder(int vacantOrder[], int range);

// generate a number in the place
void GenerateNum(int vacantOrder[], int range);

//check the vacant, using vacantorder to restore the vacant, return the vacant amount
int VacantAmount(int vacantOrder[], int indexVacant);

//check the combinability
bool IfCombinable();

//check if reach 2048
bool If2048();




