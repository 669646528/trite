#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPen>
#include <QTimer>
#include <QTime>
#include <QKeyEvent>


Widget::Widget(QWidget *parent) :

    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //调整窗口尺寸布局
    //resize(AREA_COL*BLOCK_SIZE+MARGIN*4+4*BLOCK_SIZE,AREA_ROW*BLOCK_SIZE+MARGIN*2);
    //初始化游戏
    //InitGame();
    //窗口大小
    // setWindowTitle("game");
    setMinimumSize(1004, 860);



}


Widget::~Widget()
{
    delete ui;
}
//定义方块
    int item1[4][4]=
    {
        {0,0,0,0},
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    //右L
    int item2[4][4]=
    {
        {0,1,0,0},
        {0,1,0,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    //左L
    int item3[4][4]=
    {
        {0,0,1,0},
        {0,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };
    //右S
    int item4[4][4]=
    {
        {0,1,0,0},
        {0,1,1,0},
        {0,0,1,0},
        {0,0,0,0}
    };
    //左S
    int item5[4][4]=
    {
        {0,0,1,0},
        {0,1,1,0},
        {0,1,0,0},
        {0,0,0,0}
    };
    //山形
    int item6[4][4]=
    {
        {0,0,0,0},
        {0,0,1,0},
        {0,1,1,1},
        {0,0,0,0}
    };
    //长条
    int item7[4][4]=
    {
        {0,0,1,0},
        {0,0,1,0},
        {0,0,1,0},
        {0,0,1,0}
    };

    //拷贝方块图案
    inline void block_cpy(int dblock[4][4],int sblock[4][4])
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                dblock[i][j]=sblock[i][j];
    }






    //绘画
    void Widget::paintEvent(QPaintEvent *)
    {
       QPainter p;
       p.begin(this);

       //p.drawPixmap(0,0,width(),height(),QPixmap("../bj.jpg"));
       p.drawPixmap(rect(),QPixmap("://bj.jpg"));



        QPen pen;
       pen.setWidth(1);//大小
      // pen.setColor(Qt::red);
        pen.setColor(QColor(6,6,6));//颜色
        //pen.setStyle(1);


       p.setPen(pen);

        //直线
      //矩形
       p.drawRect(250,20,360,720);
       p.drawRect(650,60,220,190);




       //画方块
       p.setBrush(QBrush(Qt::red,Qt::SolidPattern));
       for(int i=0;i<4;i++)
           for(int j=0;j<4;j++)
               if(block[i][j]==1)
                   p.drawRect(30*j+380,30*i+30,30,30);










       p.end();
    }

    void Widget::on_play_released()
    {
        painttime.start();

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
                block[i][j]=0;
        }


        //随机数
               QTime time;
               time= QTime::currentTime();
               qsrand(time.msec()+time.second()*1000);
               int id = qrand() % 7;


                   switch (id)
                   {
                   case 0:
                       block_cpy(block,item1);
                       break;
                   case 1:
                       block_cpy(block,item2);
                       break;
                   case 2:
                       block_cpy(block,item3);
                       break;
                   case 3:
                       block_cpy(block,item4);
                       break;
                   case 4:
                       block_cpy(block,item5);
                       break;
                   case 5:
                       block_cpy(block,item6);
                       break;
                   case 6:
                       block_cpy(block,item7);
                       break;
                   default:
                       break;
                   }




    }


    /*
void Widget::timerEvent(QTimerEvent *)
    {
    if(event->timeId()==)
}


//键盘活动
void Widget::keyPressEvent(QKeyEvent *)
{
   switch(event->key()){
    case Qt::Key_Left:{
        move(-30,0);
        }
        break;
    default:
        break;
    }

}


*/

void Widget::on_play_clicked()
{

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
                block[i][j]=0;
        }


        //随机数
               QTime time;
               time= QTime::currentTime();
               qsrand(time.msec()+time.second()*1000);
               int id = qrand() % 7;


                   switch (id)
                   {
                   case 0:
                       block_cpy(block,item1);
                       break;
                   case 1:
                       block_cpy(block,item2);
                       break;
                   case 2:
                       block_cpy(block,item3);
                       break;
                   case 3:
                       block_cpy(block,item4);
                       break;
                   case 4:
                       block_cpy(block,item5);
                       break;
                   case 5:
                       block_cpy(block,item6);
                       break;
                   case 6:
                       block_cpy(block,item7);
                       break;
                   default:
                       break;
                   }





}
