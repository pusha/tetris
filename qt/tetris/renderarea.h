#ifndef RENDERAREA_H
#define RENDERAREA_H

#include"tmatrix.h"

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

								static const int BRICKS_X = 10;            //-колво клеток горизонтально
								static const int BRICKS_Y = 20;            //-колво клеток вертикально

								static const int PW_START_X = 20;            //-начало прямоугольника стакана х
								static const int PW_START_Y = 20;            //-начало прямоугольника стакана y

								static const int PW_FRAME_THICKNESS = 2;  //-толщина внешней рамки
								static const int PW_FRAME_PADDING = 3;    //-пиксели между рамкой и внутри

								static const int PW_BRICK_SIZE = 10;        //-размер клетки в пикселях
								static const int PW_BRICK_PADDING = 2;     //-расстояние между клетками в пх


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
