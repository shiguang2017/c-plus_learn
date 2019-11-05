#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Point.h"

class Rectang:public Point    //派生类定义部分
{
    public:
        void initRectangle(float x,float y,float w,float h)  //新增公有成员函数
        {
            initPoint(x,y);   //调用基类公有成员函数
            this->w=w;
            this->h=h;
        }
        float getH()const{return h;}
        float getW()const{return w;}
    private:   //新增私有数据成员
        float w,h;
};

#endif // RECTANGLE_H
