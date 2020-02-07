#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <ctime>
#include <QKeyEvent>
#include <QPushButton>
#include <QMessageBox>

#define MAXX 10
#define MAXY 23
#define WIDTH 40
#define HEIGTH 40
#define COUNT 4

struct Block
{
    int x[COUNT];
    int y[COUNT];
    int centerX;
    int centerY;
    int ID;

};//方块结构体

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void scBlock();//生成方块
    void scnextBlock();
    bool moveleft();
    bool moveright();
    bool movedown();//移动
    void clear();//初始化
    bool move(int dx,int dy);//移动
    void blocktobox();//方块固定
    bool isRotatable();//旋转判断
    bool isend();//结束判断
    int getline();//获取一行
    void killline();//消除一行
    void timestop();//时间暂停
    void timestart();//计时开始


protected:
    void timerEvent(QTimerEvent *event);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);


private:
    Ui::MainWindow *ui;
    int score;//分数
    Block block;
    Block nextblock;//方块
    int box[MAXX+5][MAXY+5];//棋盘
    int refresh;//定时器ID

    QPushButton *plays;
    QPushButton *stops;
private slots:
    void startTimerSlot();

};

#endif // MAINWINDOW_H
