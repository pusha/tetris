#include "renderarea.h"
#include "QPaintEvent"
#include "QPainter"

//-the_Constructor (sure enough)
RenderArea::RenderArea(QWidget *parent) :
  QWidget(parent),
  mBackgroundColor(0xff0000),
  mShapeColor(0xffffff),
  mShape (Astroid)
{
  //-calling this event once to initialize the picture
  on_shape_changed();
}

QSize RenderArea::minimumSizeHint() const
{
  return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
  return QSize(400, 400);
}

//------------------------------------------------------------------------------
void RenderArea::on_shape_changed()
{
  switch (mShape)
  {
    case Astroid:
      mScale = 40;
      mIntervalLength = 2 * M_PI;
      mStepCount = 512;
      break;

    case Cycloid:
      mScale = 4;
      mIntervalLength = 6 * M_PI;
      mStepCount = 512;
        break;

    case HuygensCycloid:
      mScale = 4;
      mIntervalLength = 4 * M_PI;
      mStepCount = 512;
      break;

    case HypoCycloid:
      mScale = 15;
      mIntervalLength = 2 * M_PI;
      mStepCount = 512;
      break;

    case FutureCurve:
      break;

    default:
      break;

  } //-switch
} //-on_shape_changed()

//------------------------------------------------------------------------------
QPointF RenderArea::compute(float t)
{
  switch (mShape)
  {
    case Astroid:
      return compute_astroid(t);
      break;

    case Cycloid:
      return compute_cycloid(t);
      break;

    case HuygensCycloid:
      return compute_huygens(t);
      break;

    case HypoCycloid:
      return compute_hypo(t);
      break;

    case FutureCurve:
      return compute_future_curve(t);
      break;

    default:
      return QPointF(0, 0);
      break;

  } //-switch

} //-compute_astroid()

//------------------------------------------------------------------------------
QPointF RenderArea::compute_astroid(float t)
{
  float cos_t = cos(t);
  float sin_t = sin(t);

  float x = 2 * cos_t * cos_t * cos_t;
  float y = 2 * sin_t * sin_t * sin_t;

  return QPointF(x, y);
} //-compute_astroid()

//------------------------------------------------------------------------------
QPointF RenderArea::compute_cycloid(float t)
{
  return QPointF(
        1.5 * (1-cos(t)),
        1.5 * (t-sin(t))
        );
} //-compute_cycloid()

//------------------------------------------------------------------------------
QPointF RenderArea::compute_huygens(float t)
{
  return QPointF(
        4*(3*cos(t) - cos(3*t)),
        4*(3*sin(t) - sin(3*t))
       );
} //-compute_huygens()

//------------------------------------------------------------------------------
QPointF RenderArea::compute_hypo(float t)
{
  return QPointF(
        1.5 * (2*cos(t)+cos(2*t)),
        1.5 * (2*sin(t)-sin(2*t))
        );
} //-compute_hypo()

//------------------------------------------------------------------------------
QPointF RenderArea::compute_future_curve(float t)
{
  return QPointF(0, 0);
} //-compute_future_curve()

//------------------------------------------------------------------------------
void RenderArea::paintEvent(QPaintEvent *event)
{
  Q_UNUSED(event);
  QPainter painter(this);

  painter.setRenderHint(QPainter::Antialiasing, true);

  switch (mShape)
    {
    case Astroid:
      {
        mBackgroundColor = Qt::red;
        break;
      }
    case Cycloid:
      {
        mBackgroundColor = Qt::green;
        break;
      }
    case HuygensCycloid:
      {
        mBackgroundColor = Qt::blue;
        break;
      }
    case HypoCycloid:
      {
        mBackgroundColor = Qt::yellow;
        break;
      }
    default:
      {
//        mBackgroundColor = Qt::cyan;
//      exit(EXIT_FAILURE);
        break;
      }
    } //switch mShape


  painter.setBrush(mBackgroundColor);
  painter.setPen(mShapeColor);

  // drawing area
  painter.drawRect(this->rect());


  //-var inits
  QPoint  center = this->rect().center();
  float   step = mIntervalLength / mStepCount;

  for(float t = 0; t < mIntervalLength;  t += step)
  {
      QPointF point = compute(t);

      QPoint pixel;
      float x = point.x() * mScale + center.x();
      float y = point.y() * mScale + center.y();

      pixel.setX(x);
      pixel.setY(y);

      painter.drawPoint(pixel);
  }

} //-RenderArea::paintEvent()


