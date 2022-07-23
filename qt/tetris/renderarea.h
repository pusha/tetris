#ifndef RENDERAREA_H
#define RENDERAREA_H

#include"global_constants.h"
#include"tmatrix.h"
#include"tpiece.h"

#include<iostream>
#include<QWidget>
#include<QApplication>
#include<QColor>
#include<QKeyEvent>
#include<QPaintEvent>
#include<QPainter>

class RenderArea : public QWidget
{
								Q_OBJECT
				public:

								static const int PW_WIDTH =
																PW_FRAME_PADDING * 2 +
																(PW_BRICK_SIZE + PW_BRICK_PADDING * 2) * BRICKS_X;

								static const int PW_HEIGHT =
																PW_FRAME_PADDING * 2 +
																(PW_BRICK_SIZE + PW_BRICK_PADDING * 2) * BRICKS_Y;

								explicit RenderArea(QWidget *parent = nullptr);

								//attempt to override two public methods inherited from class QWidget
								QSize minimumSizeHint() const Q_DECL_OVERRIDE;
								QSize sizeHint() const Q_DECL_OVERRIDE;

								void setBackgroundColor (QColor color) {mBackgroundColor = color;}  //setter
								QColor backgroundColor () const {return mBackgroundColor;}          //getter

								//-draw this shit!
								void drawPlayingWindow(QPainter *painter);

				protected:
								//override a protected method paintEvent, the central method of painting
								void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

								//-override a default keypress method for our needs
								void keyPressEvent(QKeyEvent *event) override;

				signals:

				private:
								QColor mBackgroundColor = 0xb2b0aa;     //-custom light gray color

								bool the_matrix[BRICKS_X][BRICKS_Y];
								TPiece* the_piece;                      //-the falling piece
//								TMatrix the_matrix;

								//-test default matrix
//								bool the_matrix[BRICKS_X][BRICKS_Y] = {
//												/*top left*/
//												{1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,},
//												{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,},
//												{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
//												{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
//												{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
//												{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
//												{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
//												{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
//												{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
//												{1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
//								};                                              /*right bottom*/

								void  drawBrick(QPainter *painter, const int i, const int j);    //-draws a brick on the PW with the given coords

}; //-class RenderArea

#endif // RENDERAREA_H
