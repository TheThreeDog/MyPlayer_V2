/**************************************************************
 * File Name   : widget.h
 * Author      : ThreeDog
 * Date        : Fri Jun 02 09:46:52 2017
 * Description : 音乐播放器的主文件，主要的控件加载和业务逻辑的处理都在此类中进行。
 *
 **************************************************************/

#ifndef WIDGET_H
#define WIDGET_H
#include "ThreeDog/tdwidget.h"
#include "ThreeDog/tdpushbutton.h"
#include "ThreeDog/tdtoolbar.h"
#include "ThreeDog/tdstackbutton.h"
#include "ThreeDog/tdslider.h"
#include "myplaylist.h"
#include <QMediaPlayer>
enum PLAYMODE { GO,LOOP,ONELOOP,RANDOM };
class Widget : public TDWidget
{

    Q_OBJECT

public:
    Widget(QWidget *parent = 0);         //构造函数
    void InitInterface();                //初始化界面
    void loadButtons();                  //加载按钮
    void readMusicList(QStringList list);//读取音乐信息
    ~Widget();
public slots:
    void addMusic();                     //添加歌曲
    void play();                         //播放
    void play(int i);                    //播放指定下标的音乐
    void pause();                        //暂停
    void playNext();                     //下一曲
    void playPrevious();                 //上一曲
    void changeMode();                   //切换播放模式
private :
    TDPushButton  *m_pPlayButton;        //播放按钮
    TDPushButton  *m_pPauseButton;       //暂停按钮
    TDPushButton  *m_pPreviousButton;    //上一曲按钮
    TDPushButton  *m_pNextButton;        //下一曲按钮
    TDPushButton  *m_pAddButton;         //添加按钮
    TDPushButton  *m_pSettingButton;     //设置按钮
    TDPushButton  *m_pSearchButton;      //查询按钮
    TDPushButton  *m_pCloseButton;       //关闭按钮
    TDPushButton  *m_pMinisizeButton;    //最小化按钮
    TDToolbar     *m_pRemoteButton;      //遥控按钮
    TDToolbar     *m_pLyricButton;       //歌词按钮
    TDStackButton *m_pPlayModeButton;    //播放模式按钮
    TDPushButton  *m_pModeButton1;       //顺序播放
    TDPushButton  *m_pModeButton2;       //列表循环
    TDPushButton  *m_pModeButton3;       //单曲循环
    TDPushButton  *m_pModeButton4;       //随机播放

    TDSlider      *m_pMusicSlider;       //音乐进度槽
    TDSlider      *m_pVolumnSlider;      //音量槽

    QLabel        *m_pMusicInfo;         //音乐名标签
    QLabel        *m_pLeftMusicTime;     //左侧音乐时间
    QLabel        *m_pRightMusicTime;    //右侧音乐时间

    MyPlayList    *m_pMyPlayList;        //显示的播放列表
    PLAYMODE       m_ePlayMode;          //播放模式
    QMediaPlayer  *m_pPlayer;            //播放器
};

#endif // WIDGET_H
