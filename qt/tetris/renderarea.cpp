#include"renderarea.h"

//------------------------------------------------------------------------------
//-the_Constructor (sure enough)
RenderArea::RenderArea(QWidget *parent) :
				QWidget(parent),
				mBackgroundColor(Qt::green)
{
				//-set the focus to the main window to read keypresses
				//-enum	FocusPolicy { TabFocus, ClickFocus, StrongFocus, WheelFocus, NoFocus }
				setFocusPolicy(Qt::StrongFocus);//-for both Tab and Click focus

} //RenderArea::constructor()


//------------------------------------------------------------------------------
QSize RenderArea :: minimumSizeHint() const
{
				return QSize(450, 400);
}

//------------------------------------------------------------------------------
QSize RenderArea::sizeHint() const
{
				return QSize(450, 400);
}



//------------------------------------------------------------------------------
void RenderArea::paintEvent(QPaintEvent *event)
{
				Q_UNUSED(event);

				//-let's create a painter for joy of mind
				QPainter painter(this);
				this->resize(450, 320);         //-this is the default size of painting area

				painter.setRenderHint(QPainter::Antialiasing, true);

				painter.setBrush(mBackgroundColor);
				painter.setPen(Qt::blue);

				// drawing area
				//  painter.drawRect(this->rect());
				painter.drawRect(this->rect());


				//-setting the color of the main window
				QPalette pal = this->palette();
				pal.setColor(this->backgroundRole(), Qt::gray);
				this->setPalette(pal);

				//-рисуем оригнальную картинку тетриса (ТМ)
				QImage img("d:/PGM/qt/tetris/misc/brick-game-small.gif");
				painter.drawImage(200, 200, img);

				this->drawPlayingWindow(&painter);

} //-RenderArea::paintEvent()

//------------------------------------------------------------------------------
void RenderArea::drawBrick(QPainter *painter, const int i, const int j)
{
				//some inits
				int START_X = PW_START_X + PW_FRAME_THICKNESS + PW_FRAME_PADDING;
		int START_Y = PW_START_Y + PW_FRAME_THICKNESS + PW_FRAME_PADDING;

		if(this->the_matrix[i][j])
		{
						painter->drawRect(
			START_X + (PW_BRICK_PADDING * 2 + PW_BRICK_SIZE) * i,
			START_Y + (PW_BRICK_PADDING * 2 + PW_BRICK_SIZE) * j,
			PW_BRICK_SIZE,
			PW_BRICK_SIZE
			);

			painter->drawRect(
			START_X + (PW_BRICK_PADDING * 2 + PW_BRICK_SIZE) * i + 3,
			START_Y + (PW_BRICK_PADDING * 2 + PW_BRICK_SIZE) * j + 3,
			PW_BRICK_SIZE - 6,
			PW_BRICK_SIZE - 6
			);

			painter->drawRect(
			START_X + (PW_BRICK_PADDING * 2 + PW_BRICK_SIZE) * i + 4,
			START_Y + (PW_BRICK_PADDING * 2 + PW_BRICK_SIZE) * j + 4,
			PW_BRICK_SIZE - 8,
			PW_BRICK_SIZE - 8
			);
		}
		else
		{
		}
} //drawBrick

//------------------------------------------------------------------------------
void RenderArea::drawPlayingWindow(QPainter *painter)
{
				//-setting the color of the main window
				QPalette pal = this->palette();
		pal.setColor(this->backgroundRole(), Qt::gray);
		this->setPalette(pal);

		//-drawing the playing field
		painter->drawRect(PW_START_X, PW_START_Y,
		PW_WIDTH, PW_HEIGHT);
		//-выведем массив в текст, удостоверимся
//		printMatrix();

		//-draw matrix of bricks
		for (int j = 0; j< BRICKS_Y; j++)
		{
						for (int i = 0; i< BRICKS_X; i++)
			{
							this->drawBrick(painter, i, j);
			}
		}

		return;
} //RenderArea::drawGameScreen


//------------------------------------------------------------------------------
void RenderArea::keyPressEvent( QKeyEvent* event )
{
				switch (event->key())
				{
								case (Qt::Key_Up):
								{
												std::cout << "key up!\n";
												//up
												break;
								}

								case (Qt::Key_Left):
								{
												std::cout << "key left!\n";
												//left
												break;
								}

								case (Qt::Key_Right):
								{
												std::cout << "key right!\n";
												//right
												break;
								}

								case (Qt::Key_Down):
								{
												std::cout << "key down!\n";
												//down
												break;
								}

								case (Qt::Key_X):          //-on X-press
								{
												if (event->modifiers() & Qt::AltModifier)
												{
																QApplication::quit();   //-exit
												}
												break;
								}

								case Qt::Key_Space:
								{
												//-pause
												break;
								}

								default:
								{
												event->ignore();  //-puts up the flag of "to be processed by the parent"
												break;
								} //-default
				} //-switch

} //-RenderArea::keyPressEvent()
