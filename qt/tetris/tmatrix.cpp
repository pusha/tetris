#include "tmatrix.h"

//------------------------------------------------------------------------------
TMatrix::TMatrix()
{

} //TMatrix::constructor()

//------------------------------------------------------------------------------
void TMatrix::printMatrix()
{
				for (int j = 0; j< RenderArea::BRICKS_Y; j++)
				{
								std::cout << "#" << j << "\t";
								for (int i = 0; i< RenderArea::BRICKS_X; i++)
								{
//												std::cout << (bool)this->arr[i][j] << " ";
								}

								std::cout << "\n";
				}
				std::cout << "---------------------------------------------------------\n";
} //-printMatrix


