#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>
#include <math.h>
#include <iostream>
#include <iomanip>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    //attempt to override two public methods inherited from class QWidget
    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType {Astroid, Cycloid, HuygensCycloid, HypoCycloid, FutureCurve};

    void setBackgroundColor (QColor color) {mBackgroundColor = color;}  //setter
    QColor backgroundColor () const {return mBackgroundColor;}          //getter

    //getter and setter for
    void setShape(ShapeType shape) {mShape = shape; on_shape_changed();}
    ShapeType shape () const {return mShape;}


protected:
    //override a protected method paintEvent, without which we can't paint successfully
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

private:
    void    on_shape_changed();
    QPointF compute(float t);         //-dispatch function based on mShape type
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens(float t);
    QPointF compute_hypo(float t);
    QPointF compute_future_curve(float t);

private:
    QColor mBackgroundColor;
    QColor mShapeColor;
    ShapeType mShape;

    float mIntervalLength;
    float mScale;
    int   mStepCount;
};

#endif // RENDERAREA_H
