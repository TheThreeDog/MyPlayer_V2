/**************************************************************
 * File Name   : myplaylist.h
 * Author      : ThreeDog
 * Date        : Wed Jun 07 14:26:00 2017
 * Description : 播放列表类用于显示在中央的播放列表
 *
 **************************************************************/
#ifndef _MYPLAYLIST_H_ 
#define _MYPLAYLIST_H_ 
#include "ThreeDog/tdlistwidget.h"
#include "myplaylistitem.h"
class MyPlayList : public TDListWidget
{
public:
    MyPlayList(QWidget* parent = 0);
    ~MyPlayList();
protected:
    void wheelEvent(QWheelEvent *e);
};

#endif  //MYPLAYLIST
