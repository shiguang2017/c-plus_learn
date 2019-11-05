#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"

class Rectang:private Point    //派生类定义部分
{
    public:
        void initRectangle(float x,float y,float w,float h)  //新增公有成员函数
        {
            initPoint(x,y);   //调用基类公有成员函数
            this->w=w;
            this->h=h;
        }
        void move(float offX,float offY){Point::move(offX,offY);}
        float getX()const{return Point::getX();}
        float getY()const{return Point::getY();}
        float getH()const{return h;}
        float getW()const{return w;}
    private:   //新增私有数据成员
        float w,h;
};

#endif // RECTANGLE_H
