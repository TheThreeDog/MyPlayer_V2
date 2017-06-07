/**************************************************************
 * File Name   : widget.cpp
 * Author      : ThreeDog
 * Date        : Fri Jun 02 09:46:52 2017
 * Description : 音乐播放器的主文件，主要的控件加载和业务逻辑的处理都在此类中进行。
 *
 **************************************************************/

#include "widget.h"
Widget::Widget(QWidget *parent)
    : TDWidget(":/image/main_interface.png",parent)
{
    InitInterface();
}

void Widget::InitInterface()
{
    loadButtons();
    //音乐播放进度槽
    m_pMusicSlider = new TDSlider(this);
    m_pMusicSlider->setFixedSize(180,10);
    m_pMusicSlider->move(145,640);
    m_pMusicSlider->setFrontColor(QColor(241,101,40));
    m_pMusicSlider->show();
    //音量槽
    m_pVolumnSlider = new TDSlider(this,Qt::Vertical);
    m_pVolumnSlider->setMaximum(100);
    m_pVolumnSlider->setValue(10);
    m_pVolumnSlider->setFixedSize(30,80);
    m_pVolumnSlider->move(351,603);
    m_pVolumnSlider->setFrontColor(QColor(241,101,40));
    m_pVolumnSlider->show();
    //通过调色板QPalette设置文字颜色
    QPalette palette ;
    palette.setColor(QPalette::WindowText,Qt::lightGray);
    //音乐名显示标签
    m_pMusicInfo = new QLabel(this);
    m_pMusicInfo->setText("MyPlayer");
    m_pMusicInfo->setFixedSize(180,30);
    m_pMusicInfo->move(140,610);
    m_pMusicInfo->setPalette(palette);

    //音乐时间标签
    palette.setColor(QPalette::WindowText,QColor(241,101,40));
    m_pLeftMusicTime = new QLabel(this);
    m_pLeftMusicTime->setText("00:00");
    m_pLeftMusicTime->setFixedSize(50,30);
    m_pLeftMusicTime->move(176,590);
    m_pLeftMusicTime->setPalette(palette);
    m_pRightMusicTime = new QLabel(this);
    m_pRightMusicTime->setText("00:00");
    m_pRightMusicTime->setFixedSize(50,30);
    m_pRightMusicTime->move(259,590);
    m_pRightMusicTime->setPalette(palette);

    //生成播放列表
    m_pMyPlayList = new MyPlayList(this);
    m_pMyPlayList->move(30,150);
}

void Widget::loadButtons()
{
    m_pPlayButton = new TDPushButton(":/image/play_normal.png",":/image/play_hover.png",":/image/play_press.png",this);
    m_pPlayButton->move(96,596);
    m_pPauseButton = new TDPushButton(":/image/pause_normal.png",":/image/pause_hover.png",":/image/pause_press.png",this);
    m_pPauseButton->move(96,596);
    m_pPauseButton->hide();
    m_pPreviousButton = new TDPushButton(":/image/previous_normal.png",":/image/previous_hover.png",":/image/previous_press.png",this);
    m_pPreviousButton->move(53,572);
    m_pNextButton = new TDPushButton(":/image/next_normal.png",":/image/next_hover.png",":/image/next_press.png",this);
    m_pNextButton->move(53,620);
    m_pAddButton = new TDPushButton(":/image/add_normal.png",":/image/add_hover.png",":/image/add_press.png",this);
    m_pAddButton->move(137,141);
    m_pSettingButton = new TDPushButton(":/image/setting_normal.png",":/image/setting_hover.png",":/image/setting_press.png",this);
    m_pSettingButton->move(261,72);
    m_pSearchButton = new TDPushButton(":/image/serch_normal.png",":/image/serch_hover.png",":/image/serch_press.png",this);
    m_pSearchButton->move(217,141);
    m_pCloseButton = new TDPushButton(":/image/close_normal.png",":/image/close_hover.png",":/image/close_press.png",this);
    m_pCloseButton->move(344,72);
    m_pMinisizeButton = new TDPushButton(":/image/mini_nromal.png",":/image/mini_hover.png",":/image/mini_press.png",this);
    m_pMinisizeButton->move(301,90);
    m_pRemoteButton = new TDToolbar(":/image/remote_open.png",":/image/remote_close.png",this);
    m_pRemoteButton->move(180,117);
    m_pLyricButton = new TDToolbar(":/image/lyric_open_normal.png",":/image/lyric_close_normal.png",this);
    m_pLyricButton->move(301,145);

    m_pModeButton1 = new TDPushButton(":/image/mode_go.png",":/image/mode_go.png",":/image/mode_go.png",this);
    m_pModeButton2 = new TDPushButton(":/image/mode_loop.png",":/image/mode_loop.png",":/image/mode_loop.png",this);
    m_pModeButton3 = new TDPushButton(":/image/mode_oneloop.png",":/image/mode_oneloop.png",":/image/mode_oneloop.png",this);
    m_pModeButton4 = new TDPushButton(":/image/mode_random.png",":/image/mode_random.png",":/image/mode_random.png",this);

    m_pPlayModeButton = new TDStackButton(this);
    m_pPlayModeButton->addButton(m_pModeButton1);
    m_pPlayModeButton->addButton(m_pModeButton2);
    m_pPlayModeButton->addButton(m_pModeButton3);
    m_pPlayModeButton->addButton(m_pModeButton4);
    m_pPlayModeButton->move(260,120);
}

Widget::~Widget()
{

}
