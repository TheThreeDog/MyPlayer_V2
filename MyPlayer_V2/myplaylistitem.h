/**************************************************************
 * File Name   : myplaylistitem.h
 * Author      : ThreeDog
 * Date        : Wed Jun 07 15:04:46 2017
 * Description : 播放列表的条目类
 *
 **************************************************************/
#ifndef _MYPLAYLISTITEM_H_ 
#define _MYPLAYLISTITEM_H_ 
#include "ThreeDog/tdlistwidget.h"
#include "ThreeDog/tdpushbutton.h"
class MyPlayListItem : public TDListWidgetItem
{
    Q_OBJECT
public:
    MyPlayListItem(QWidget *parent = 0);
    void setText(const QString &text);          //设置左部分所显示的文字
    QString getLeftText();                      //获取左侧的文字信息
    void setPath(const QString & path);         //设置该条目录对应的歌曲路径
    QString getPath();                          //获取该条目对应的歌曲路径
    void setMusicIndex(const int & index);      //设置音乐的下标号
    int getMusicIndex();                        //设置条目对应的音乐的下标号
    //RightKeyMenu * getRightKeyMenu();
    void openMV();                              //播放MV
    ~MyPlayListItem();
protected:
    void mouseDoubleClickEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *e);
    void focusInEvent(QFocusEvent *);
    void focusOutEvent(QFocusEvent *);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
signals:
    void doubleClick(int index);
private:
    QLabel * m_pLeftLabel;                      //左侧显示文字
    QString m_sPath;                            //歌曲文件的路径
    int m_iMusicIndex;                          //音乐的下标号
    bool m_bIsSelected;                         //鼠标是否被按下的标识
    //RightKeyMenu * r;
    TDPushButton *m_pMVButton;                  //右侧播放MV的按钮
    QString m_sMVName;                          //MV文件的文件名
};

#endif  //MYPLAYLISTITEM
