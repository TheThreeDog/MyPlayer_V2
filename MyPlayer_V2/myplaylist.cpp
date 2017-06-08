/**************************************************************
 * File Name   : myplaylist.cpp
 * Author      : ThreeDog
 * Date        : Wed Jun 07 14:26:00 2017
 * Description : 播放列表类，用于显示播放器中央的播放列表。
 *
 **************************************************************/

#include "myplaylist.h"
#include <QBitmap>
#include <QDebug>
MyPlayList::MyPlayList(QWidget *parent)
    :TDListWidget(parent)
{
    //先把子窗体移动到一个标签的位置，保证新加入的标签不会放到最上面而被遮盖
    sub_widget->move(0,32);
    this->setFixedSize(370,470);
    this->setSpacing(0);
    //先设置此播放列表的遮罩。
    QPixmap pic;
    pic.load(":/image/music_item_mask.png");
    this->setMask(pic.mask());

//    for(int i = 0; i < 20; i++){
//        MyPlayListItem * item = new MyPlayListItem(this);
//        item->setText("薛之谦-王子和公主");
//        this->addItem(item);
//    }
}

MyPlayList::~MyPlayList()
{

}

void MyPlayList::wheelEvent(QWheelEvent *e)
{
    if(e->orientation() == Qt::Vertical){
        if(e->delta() > 0){//滚动角度大于0
            //首先labels不能为空
            //如果子窗体的坐标的y小于0，则说明往下移动的过多，则不能移动
            if(this->getCount() != 0 && sub_widget->pos().y() < 32)//-32一个标签的长度
                sub_widget->move(sub_widget->pos().x(),sub_widget->pos().y()+20);
        }
        else{
            //同理 如果子窗体的坐标的y（底角坐标）大于height，则说明往上移动的过多，则不能移动
            if(this->getCount()!=0&&sub_widget->y()+sub_widget->height() > this->height()-50)
                sub_widget->move(sub_widget->pos().x(),sub_widget->pos().y()-20);
        }
    }
    e->accept();

}
