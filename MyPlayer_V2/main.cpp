#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font;
    font.setFamily("微软雅黑");
    font.setPointSize(10);
    QPalette palette;
    palette.setColor(QPalette::WindowText,Qt::lightGray);
    a.setFont(font);
    a.setPalette(palette);
    Widget w;
    w.show();

    return a.exec();
}
