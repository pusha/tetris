#ifndef TPIECE_H
#define TPIECE_H

#include<iostream>
#include<QPoint>

enum PieceType
{
				PieceT = 0,
				PieceJ = 1,
				PieceZ = 2,
				PieceO = 3,
				PieceS = 4,
				PieceL = 5,
				PieceI = 6,
} ; //-enum

const int PIECE_T_SPAN = 3;
const int PIECE_J_SPAN = 3;
const int PIECE_Z_SPAN = 3;
const int PIECE_O_SPAN = 2;
const int PIECE_S_SPAN = 3;
const int PIECE_L_SPAN = 3;
const int PIECE_I_SPAN = 4;

const int PIECE_T_POSITIONS = 4;
const int PIECE_J_POSITIONS = 4;
const int PIECE_Z_POSITIONS = 2;
const int PIECE_O_POSITIONS = 1;
const int PIECE_S_POSITIONS = 2;
const int PIECE_L_POSITIONS = 4;
const int PIECE_I_POSITIONS = 2;

//------------------------------------------------------------------------------
class TPiece
{

				public:
								//-T
								const bool PIECE_T[PIECE_T_POSITIONS][PIECE_T_SPAN][PIECE_T_SPAN] =
								{
												{
																{0, 1, 0},
																{0, 1, 1},
																{0, 1, 0},
												},
												{
																{0, 0, 0},
																{1, 1, 1},
																{0, 1, 0},
												},
												{
																{0, 1, 0},
																{1, 1, 0},
																{0, 1, 0},
												},
												{
																{0, 1, 0},
																{1, 1, 1},
																{0, 0, 0},
												},
								}; //-T

								//-J
								const bool PIECE_J[PIECE_J_POSITIONS][PIECE_J_SPAN][PIECE_J_SPAN] =
								{
												{
																{0, 0, 1},
																{1, 1, 1},
																{0, 0, 0},
												},
												{
																{0, 1, 0},
																{0, 1, 0},
																{0, 1, 1},
												},
												{
																{0, 0, 0},
																{1, 1, 1},
																{1, 0, 0},
												},
												{
																{1, 1, 0},
																{0, 1, 0},
																{0, 1, 0},
												},
								}; //-J

								//-Z
								const bool PIECE_Z[PIECE_Z_POSITIONS][PIECE_Z_SPAN][PIECE_Z_SPAN] =
								{
												{
																{1, 0, 0},
																{1, 1, 0},
																{0, 1, 0},
												},
												{
																{0, 1, 1},
																{1, 1, 0},
																{0, 0, 0},
												},
								}; //-Z

								const bool PIECE_O[PIECE_O_POSITIONS][PIECE_O_SPAN][PIECE_O_SPAN] =
								{
												{
																{1, 0},
																{1, 1},
												},
								}; //-O

								//-S
								const bool PIECE_S[PIECE_S_POSITIONS][PIECE_S_SPAN][PIECE_S_SPAN] =
								{
												{
																{0, 1, 0},
																{1, 1, 0},
																{1, 0, 0},
												},
												{
																{1, 1, 0},
																{0, 1, 1},
																{0, 0, 0},
												},
								}; //-S

								//-L
								const bool PIECE_L[PIECE_L_POSITIONS][PIECE_L_SPAN][PIECE_L_SPAN] =
								{
												{
																{0, 0, 0},
																{1, 1, 1},
																{0, 0, 1},
												},
												{
																{0, 1, 0},
																{0, 1, 0},
																{1, 1, 0},
												},
												{
																{1, 0, 0},
																{1, 1, 1},
																{0, 0, 0},
												},
												{
																{0, 1, 1},
																{0, 1, 0},
																{0, 1, 0},
												},
								}; //-L

								const bool PIECE_I[PIECE_I_POSITIONS][PIECE_I_SPAN][PIECE_I_SPAN] =
								{
												{
																{0, 0, 1, 0},
																{0, 0, 1, 0},
																{0, 0, 1, 0},
																{0, 0, 1, 0},
												},
												{
																{0, 0, 0, 0},
																{0, 0, 0, 0},
																{1, 1, 1, 1},
																{0, 0, 0, 0},
												},
								}; //-I

								TPiece(){std::cout << "TPiece constructor cannot be empty.";};
								TPiece(const PieceType);

				private:
								bool* arr;
								QPoint start;

}; //-class TPiece






#endif // TPIECE_H
