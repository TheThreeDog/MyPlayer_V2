#include "widget.h"
#include <QDir>
Widget::Widget(QWidget *parent)
    : TDWidget(":/image/main_interface.png",parent)
{
    initInterface();

}

void Widget::initInterface()
{
    this->setWindowIcon(QIcon(":/image/ico.png"));
    //创建系统托盘图标
    //this->createStstemTrayIcon();
    //加载播放列表路径
    m_sSavePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    m_iVolume = 80;

    m_pPlayList = new QMediaPlaylist;
    //设置播放模式为列表循环
    m_pPlayList->setPlaybackMode(QMediaPlaylist::Loop);

    //初始化播放器
    m_pPlayer = new QMediaPlayer;
    m_pPlayer->setPlaylist(m_pPlayList);//为播放器绑定播放列表
    m_pPlayer->setVolume(m_iVolume);

//    //初始化魔方
//    cube = new Cube;
//    cube->setWidget(this);
//    cube->getButtons().at(0)->setCallback(this,my_selector(playOrPause));
//    cube->getButtons().at(1)->setCallback(this,my_selector(playOrPause));
//    cube->getButtons().at(2)->setCallback(this,my_selector(playPrevious));
//    cube->getButtons().at(3)->setCallback(this,my_selector(playNext));
//    cube->getButtons().at(4)->setCallback(this,my_selector(volumeSub));
//    cube->getButtons().at(5)->setCallback(this,my_selector(volumeAdd));
//    //桌面歌词的开关
//    cube->getButtons().at(6)->setCallback(this,my_selector(setLyricShown));

//    //初始化lrc歌词类
//    lrc = new MyLrc;
//    lrc->hide();
//    //lrc->show();
    //音量调节槽
    m_pVolumeSlider = new TDSlider(this,Qt::Vertical);
    m_pVolumeSlider->setMaximum(100);
    m_pVolumeSlider->setValue(4);
    m_pVolumeSlider->setFixedSize(30,80);
    m_pVolumeSlider->move(351,600);
    m_pVolumeSlider->setFrontColor(QColor(241,101,40));
    m_pVolumeSlider->show();
    //音乐播放进度条
    m_pMusicSlider = new TDSlider(this);
    m_pMusicSlider->setFixedSize(180,10);
    m_pMusicSlider->move(145,640);
    m_pMusicSlider->setFrontColor(QColor(241,101,40));
    m_pMusicSlider->show();
    //播放列表的显示区域
    m_pMusicList = new TDListWidget(this);
    m_pMusicList->move(30,150);
    m_pMusicList->setFixedSize(360,470);
    //设置播放列表部分的遮罩！
    QPixmap pic;
    pic.load(":/image/music_item_mask.png");
    m_pMusicList->setMask(pic.mask());
    //在这里读入用户的播放列表文件
    QFile file(m_sSavePath+".list");
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QTextStream in(&file);
        QStringList path_list;
        while(!in.atEnd()){
            QString item ;
            item = in.readLine();
            path_list.append(item);
        }
        if(!path_list.isEmpty()&&path_list.at(0)!="")
            readMusicList(path_list);
    }
    //设置字体颜色
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
    m_pLeftMusicTime->move(175,590);
    m_pLeftMusicTime->setPalette(palette);
    m_pRightMusicTime = new QLabel(this);
    m_pRightMusicTime->setText("00:00");
    m_pRightMusicTime->setFixedSize(50,30);
    m_pRightMusicTime->move(258,590);
    m_pRightMusicTime->setPalette(palette);
    //加载按钮
    loadButtons();

}

void Widget::readMusicList(QStringList list)
{
    //i获取当前列表中条目的数量，从列表处开始添加。
    int i = this->m_pMusicList->getCount();
    //用music_num遍历获取到的列表曲目继续添加
    int music_num = 0;
    for(;music_num < list.size();music_num++){
        QString path = QDir::toNativeSeparators(list.at(music_num));
        if(!path.isEmpty()){
            //将新歌曲添加到播放列表中，两者通过相同的index关联
            m_pPlayList->addMedia(QUrl::fromLocalFile(path));
            if(QMediaPlayer::StoppedState == m_pPlayer->state())
                m_pPlayList->setCurrentIndex(i);
            //将新歌曲添加到自定义的显示列表中
            QString file_name = path.split("\\").last();
            TDListWidgetItem * new_music = new TDListWidgetItem(file_name.split(".").front(),m_pMusicList);
            //new_music->setIndex();
        }
    }
}

void Widget::loadButtons()
{
    m_pPlayButton = new TDPushButton(":/image/play_normal.png",
                            ":/image/play_hover.png",
                            ":/image/play_press.png",
                            this);
    m_pPlayButton->move(96,596);
    m_pPreviousButton = new TDPushButton(":/image/previous_normal.png",
                                ":/image/previous_hover.png",
                                ":/image/previous_press.png",
                                this);
    m_pPreviousButton->move(53,572);

    m_pNextButton = new TDPushButton(":/image/next_normal.png",
                            ":/image/next_hover.png",
                            ":/image/next_press.png",
                            this);
    m_pNextButton->move(53,620);

    m_pAddButton = new TDPushButton(":/image/add_normal.png",
                           ":/image/add_hover.png",
                           ":/image/add_press.png",
                           this);
    m_pAddButton->move(137,141);

    m_pCloseButton = new TDPushButton(":/image/close_normal.png",
                             ":/image/close_hover.png",
                             ":/image/close_press.png",
                             this);
    m_pCloseButton->move(344,72);

    m_pLyricButton = new TDToolbar(":/image/lyric_close_normal.png",
                             ":/image/lyric_open_normal.png",
                             this);
    m_pLyricButton->move(301,145);

    m_pMiniButton = new TDPushButton(":/image/mini_normal.png",
                            ":/image/mini_hover.png",
                            ":/image/mini_press.png",
                            this);
    m_pMiniButton->move(301,90);

    m_pPauseButton = new TDPushButton(":/image/pause_normal.png",
                             ":/image/pause_hover.png",
                             ":/image/pause_press.png",
                             this);
    m_pPauseButton->move(96,596);

    m_pPauseButton->hide();

    m_pRemoteControlButton = new TDToolbar(":/image/remote_close.png",
                             ":/image/remote_open.png",
                             this);
    m_pRemoteControlButton->move(180,117);

    m_pSearchButton = new TDPushButton(":/image/serch_normal.png",
                             ":/image/serch_hover.png",
                             ":/image/serch_press.png",
                             this);
    m_pSearchButton->move(217,141);

    m_pSettingButton = new TDPushButton(":/image/setting_normal.png",
                               ":/image/setting_hover.png",
                               ":/image/setting_press.png",
                               this);
    m_pSettingButton->move(262,72);

    //播放状态按钮暂无
    //play_mode_btn = new PlayModeButton(this);
    //play_mode_btn->move(260,120);

}

Widget::~Widget()
{

}
