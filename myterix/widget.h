#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QTime>





const int BLOCK_SIZE=30; //单个方块单元的边长
const int MARGIN=5; //场景边距
const int AREA_ROW=21; //场景行数
const int AREA_COL=10; //场景列数


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    void InitGame();
    void GetBlock(int block[4][4],int id);//生成方块


public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();




protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
   // void keyPressEvent(QKeyEvent *);


private:
    Ui::Widget *ui;
      QTimer *timer;
    int block[4][4];//当前方块
    //int nextblock[4][4]；// 下一方块


   // QTime gametime();
    QTime painttime;//计时器
private slots:
   // viod timeout();//定时溢出处理函数



    void on_play_released();

    void on_play_clicked();
};

#endif // WIDGET_H
