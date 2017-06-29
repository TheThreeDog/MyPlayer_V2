/**************************************************************
 * File Name   : widget.cpp
 * Author      : ThreeDog
 * Date        : Fri Jun 02 09:46:52 2017
 * Description : 音乐播放器的主文件，主要的控件加载和业务逻辑的处理都在此类中进行。
 *
 **************************************************************/

#include "widget.h"
#include <QDebug>
#include <QDir>
#include <QFileDialog>
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
    m_pVolumnSlider->setFixedSize(30,80);
    m_pVolumnSlider->move(351,603);
    m_pVolumnSlider->setFrontColor(QColor(241,101,40));
    m_pVolumnSlider->show();
    m_pVolumnSlider->setValue(100);
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

    //设置播放模式为随机播放
    m_ePlayMode = RANDOM;

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
    m_pAddButton->setCallback(this,my_selector(addMusic));
    m_pSettingButton = new TDPushButton(":/image/setting_normal.png",":/image/setting_hover.png",":/image/setting_press.png",this);
    m_pSettingButton->move(261,72);
    m_pSearchButton = new TDPushButton(":/image/serch_normal.png",":/image/serch_hover.png",":/image/serch_press.png",this);
    m_pSearchButton->move(217,141);
    m_pCloseButton = new TDPushButton(":/image/close_normal.png",":/image/close_hover.png",":/image/close_press.png",this);
    m_pCloseButton->move(344,72);
    m_pMinisizeButton = new TDPushButton(":/image/mini_normal.png",":/image/mini_hover.png",":/image/mini_press.png",this);
    m_pMinisizeButton->move(301,90);
    m_pRemoteButton = new TDToolbar(":/image/remote_open.png",":/image/remote_close.png",this);
    m_pRemoteButton->move(180,117);
    m_pLyricButton = new TDToolbar(":/image/lyric_open_normal.png",":/image/lyric_close_normal.png",this);
    m_pLyricButton->move(301,145);

    m_pModeButton1 = new TDPushButton(":/image/mode_go.png",":/image/mode_go.png",":/image/mode_go.png",this);
    m_pModeButton1->setToolTip("顺序播放");
    m_pModeButton1->setCallback(this,my_selector(changeMode));
    m_pModeButton2 = new TDPushButton(":/image/mode_loop.png",":/image/mode_loop.png",":/image/mode_loop.png",this);
    m_pModeButton2->setToolTip("循环播放");
    m_pModeButton2->setCallback(this,my_selector(changeMode));
    m_pModeButton3 = new TDPushButton(":/image/mode_oneloop.png",":/image/mode_oneloop.png",":/image/mode_oneloop.png",this);
    m_pModeButton3->setToolTip("单曲循环");
    m_pModeButton3->setCallback(this,my_selector(changeMode));
    m_pModeButton4 = new TDPushButton(":/image/mode_random.png",":/image/mode_random.png",":/image/mode_random.png",this);
    m_pModeButton4->setToolTip("随机播放");
    m_pModeButton4->setCallback(this,my_selector(changeMode));
    m_pPlayModeButton = new TDStackButton(this);
    m_pPlayModeButton->addButton(m_pModeButton1);
    m_pPlayModeButton->addButton(m_pModeButton2);
    m_pPlayModeButton->addButton(m_pModeButton3);
    m_pPlayModeButton->addButton(m_pModeButton4);
    m_pPlayModeButton->move(260,120);
}

void Widget::changeMode()
{
    switch (m_ePlayMode) {
    case GO:
        m_ePlayMode = LOOP;
        break;
    case LOOP:
        m_ePlayMode = ONELOOP;
        break;
    case ONELOOP:
        m_ePlayMode = RANDOM;
        break;
    case RANDOM:
        m_ePlayMode = GO;
        break;
    default:
        break;
    }
}

Widget::~Widget()
{

}

void Widget::addMusic()
{
    //添加音乐，默认从家目录开始
    QString inital_name = QDir::homePath();
    QStringList path_list = QFileDialog::getOpenFileNames(this,"选择文件",inital_name,"*.mp3");
    //如果得到的列表不为空，读取音乐信息。
    if(!path_list.isEmpty() && path_list.at(0)!="")
        readMusicList(path_list);
}

void Widget::readMusicList(QStringList list)
{
    //i获取当前列表中条目的数量，从列表处开始添加。
    int i = this->m_pMyPlayList->getCount();
    //用music_num遍历获取到的列表曲目连续添加
    int music_num = 0;
    for(; music_num < list.size(); music_num++){
        QString path = QDir::toNativeSeparators(list.at(music_num));
        if(!path.isEmpty()){
            bool isExist = false;
            //检测到路径，但要保证此路径在列表中不存在、
            //即过滤掉重复项
            for(int t = 0; t < m_pMyPlayList->getCount();t++){
                if(path == ((MyPlayListItem *)(m_pMyPlayList->getItem(t)))->getPath()){
                    isExist = true;
                    break;
                }
            }
            //将新歌曲添加到播放列表中，两者通过相同的index联系！
            //play_list_->addMedia(QUrl::fromLocalFile(path));
            //if(player_->state() == QMediaPlayer::StoppedState)
            //    play_list_->setCurrentIndex(i);
            //将新歌曲添加到自定义的显示列表中
            if(!isExist){
            QString file_name = path.split("\\").last();
            MyPlayListItem * new_music = new MyPlayListItem(m_pMyPlayList);
            new_music->setPath(path);
            new_music->setText(file_name.split(".").front());
            new_music->setIndex(i);

            m_pMyPlayList->addItem(new_music);//添加至播放列表
            //将条目的双击信号与槽函数关联
            connect(new_music,SIGNAL(doubleClick(int)),this,SLOT(play(int)));
            //列表右键菜单触发事件
            //记得每次也要将i++，i还作为歌曲index传入！
            i++;
            }
        }
    }
    //  右键菜单中的槽函数们
    if(music_num == 0) return ; //如果没有打开任何文件，就不连接这些槽函数
  /*connect(this->table_widget->getLabels()->at(0)->getRightKeyMenu(),
            SIGNAL(playBtnClick(int)),
            this,
            SLOT(playTo(int)));
    connect(this->table_widget->getLabels()->at(0)->getRightKeyMenu(),
            SIGNAL(removeMusicSignal(int)),
            this,
            SLOT(removeMusic(int )));
    connect(this->table_widget->getLabels()->at(0)->getRightKeyMenu(),
            SIGNAL(addNewMusic()),
            this,
            SLOT(openFile()));
    connect(this->table_widget->getLabels()->at(0)->getRightKeyMenu(),
            SIGNAL(playModeChanged()),
            this,
            SLOT(playModeChange()));
    connect(this->table_widget->getLabels()->at(0)->getRightKeyMenu(),
            SIGNAL(changeToCubeMode()),
            this,
            SLOT(showCube()));
    connect(this->table_widget->getLabels()->at(0)->getRightKeyMenu(),
            SIGNAL(setWindowTop()),
            this,
            SLOT(setWindowOnTop()));
    connect(this->table_widget->getLabels()->at(0)->getRightKeyMenu(),
            SIGNAL(clearListorder()),
            this,
            SLOT(removeAllMusic()));
    */
}

void Widget::play()
{

}

void Widget::play(int i)
{

}

void Widget::pause()
{

}

void Widget::playNext()
{

}

void Widget::playPrevious()
{

}
