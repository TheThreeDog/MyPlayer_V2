#ifndef WIDGET_H
#define WIDGET_H
#include "ThreeDog/tdwidget.h"
#include "ThreeDog/tdslider.h"
#include "ThreeDog/tdlistwidget.h"
#include "ThreeDog/tdpushbutton.h"
#include "ThreeDog/tdstackbutton.h"
#include "ThreeDog/tdtoolbar.h"
#include <QWidget>
#include <QIcon>
#include <QStandardPaths>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QSystemTrayIcon>
#include <QLabel>
#include <QBitmap>
class Widget : public TDWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    //界面初始化函数
    void initInterface();
    //读取播放列表
    void readMusicList(QStringList list);
    //加载按钮
    void loadButtons();
    ~Widget();
private :
    //用户自定义播放列表的播放路径
    QString m_sSavePath;
    int m_iVolume;  //音量
    QMediaPlayer * m_pPlayer;//播放器
    QMediaPlaylist * m_pPlayList;//播放列表
    QSystemTrayIcon *m_pTrayIcon;//系统托盘图标
    QLabel *m_pMusicInfo;//音乐信息
    QTimer *m_pTimer;//定时器
    QLabel *m_pLeftMusicTime;//播放时间
    QLabel *m_pRightMusicTime;//歌曲时间
    QMenu *systray_menu;//托盘按钮
    QAction *open_mainwindow;//打开主窗体动作
    QAction *exit;//关闭动作

    TDSlider * m_pMusicSlider;//歌曲播放进度条
    TDSlider * m_pVolumeSlider;//音量槽
    TDListWidget *m_pMusicList;//自定义音乐列表
    //Cube *cube;
    //MyLrc *lrc;
    //QMap<qint64, QString> lrc_map;
    //判断是否能够切换模式
    //bool change_mode;
    //bool network_start;

    TDPushButton *m_pPlayButton;
    TDPushButton *m_pNextButton;
    TDPushButton *m_pPreviousButton;
    TDPushButton *m_pAddButton;
    TDPushButton *m_pCloseButton;
    TDToolbar    *m_pLyricButton;
    TDPushButton *m_pMiniButton;
    TDPushButton *m_pPauseButton;
    TDToolbar    *m_pRemoteControlButton;
    TDPushButton *m_pSearchButton;
    TDPushButton *m_pSettingButton;
    TDStackButton * m_pPlayModeButton;
};

#endif // WIDGET_H
