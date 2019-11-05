#ifndef POINT_H
#define POINT_H


class Point        //类定义
{
    public:        //外部接口
        Point();
        Point(int x,int y);
        ~Point();
        void move(int newX,int newY);
        int getX() const{return x;}
        int getY() const{return y;}
        static void showCount();      //静态函数
    private:    //私有数据成员
        int x,y;
};

#endif // POINT_H
