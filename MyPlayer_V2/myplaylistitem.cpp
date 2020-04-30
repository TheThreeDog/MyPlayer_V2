/**************************************************************
 * File Name   : myplaylistitem.cpp
 * Author      : ThreeDog 
 * Date        : Wed Jun 07 15:04:46 2017
 * Description : 播放列表的条目类
 *
 **************************************************************/

#include "myplaylistitem.h"
#include <QFileInfo>
#include <QHBoxLayout>
MyPlayListItem::MyPlayListItem(QWidget *parent)
    :TDListWidgetItem("",parent)
{
    //通过鼠标单击获取焦点
    this->setFocusPolicy(Qt::ClickFocus);
    this->m_bIsSelected = false;
    this->setAutoFillBackground(true);
    this->setMouseTracking(true);
    //设置背景透明
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/trans.png")));
    this->setPalette(palette);

    this->setFixedSize(360,34);

    //r = RightKeyMenu::shareRightKeyMenu(0,QString(""),this);

    QHBoxLayout * h = new QHBoxLayout;
    m_pLeftLabel = new QLabel(this);
    m_pLeftLabel->setFixedWidth(260);
    h->addStretch(1);
    h->addWidget(m_pLeftLabel,6,Qt::AlignLeft);
    h->addStretch(3);
    m_pMVButton = NULL;
    this->setLayout(h);
}

void MyPlayListItem::setText(const QString &text)
{
    this->m_pLeftLabel->setText(text);
}

QString MyPlayListItem::getLeftText()
{
    return m_pLeftLabel->text();
}

void MyPlayListItem::setPath(const QString &path)
{
    this->m_sPath = path;
    //同时指定以下歌曲的MV名称。
    m_sMVName = m_sPath.remove(path.right(3)) + "wmv";
}

void MyPlayListItem::setMusicIndex(const int &index)
{
    this->m_iMusicIndex = index;
}

int MyPlayListItem::getMusicIndex()
{
    return this->m_iMusicIndex;
}

QString MyPlayListItem::getPath()
{
    return this->m_sPath;
}

void MyPlayListItem::openMV()
{

}

MyPlayListItem::~MyPlayListItem()
{

}


void MyPlayListItem::mouseDoubleClickEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
        emit doubleClick(this->m_iMusicIndex);
}
//空函数体，无效化父类的此函数！
void MyPlayListItem::mousePressEvent(QMouseEvent *)
{

}

void MyPlayListItem::mouseReleaseEvent(QMouseEvent *e)
{
/*    if(e->button()==Qt::RightButton){
        r = RightKeyMenu::shareRightKeyMenu(this->music_index,this->path,this);

        QDesktopWidget *desktop_widget =
                QApplication::desktop();
        //得到客户区矩形
        QRect client_rect = desktop_widget->availableGeometry();
        //得到应用程序矩形
        //QRect application_rect = desktop_widget->screenGeometry();
        int win_width = client_rect.width();
        int win_height = client_rect.height();
        if((e->globalY()+r->height()>win_height)&&(e->globalX()+r->width()>win_width)){
            r->move(win_width-r->width(),win_height-r->height());
            r->show();
            r->setFocus();
            return ;
        }
        if(e->globalY()+r->height()>win_height){
            r->move(e->globalX(),win_height-r->height());
            r->show();
            r->setFocus();
            return ;
        }
        if(e->globalX()+r->width()>win_width){
            r->move(win_width-r->width(),e->globalY());
            r->show();
            r->setFocus();
            return ;
        }
        r->move(e->globalPos());
        r->show();
        r->setFocus();
        return ;
    }
*/
}

void MyPlayListItem::focusInEvent(QFocusEvent *)
{
    m_bIsSelected = true;
    QPalette palette;
    palette.setColor(QPalette::Background, QColor("#80585858"));
    this->setPalette(palette);
}

void MyPlayListItem::focusOutEvent(QFocusEvent *)
{
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/trans.png")));
    this->setPalette(palette);
    m_pMVButton->hide();
    m_bIsSelected = false;
}

void MyPlayListItem::enterEvent(QEvent *)
{
    if(!m_bIsSelected){
        QPalette palette;
        palette.setColor(QPalette::Background, QColor("#802a2a2a"));
        this->setPalette(palette);

        //通过MV是否存在生成对应按钮
        QFileInfo fi(m_sMVName);
        if(fi.exists()){
            if(m_pMVButton == NULL){
                m_pMVButton = new TDPushButton(":/image/mv_normal.png",
                                      ":/image/mv_hover.png",
                                      ":/image/mv_press.png",
                                      this);
                m_pMVButton->move(300,2);
                m_pMVButton->setCallback(this,my_selector(MyPlayListItem::openMV));
            }
        }else {
            if(NULL == m_pMVButton){
                m_pMVButton = new TDPushButton(":/image/mvdisable.png",
                                      ":/image/mvdisable.png",
                                      ":/image/mvdisable.png",
                                      this);
                m_pMVButton->move(300,2);
            }
        }
        m_pMVButton->show();
    }
}

void MyPlayListItem::leaveEvent(QEvent *)
{
    if(!m_bIsSelected){
        QPalette palette;
        palette.setBrush(QPalette::Background, QBrush(QPixmap(":/image/trans.png")));
        this->setPalette(palette);
        m_pMVButton->hide();
    }
}

