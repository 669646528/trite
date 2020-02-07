#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>


int time_on=1;//设置游戏状态
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < MAXX; i++)
       {
           for (int j = 0; j < MAXY; j++)
           {
               box[i][j] = 0;
           }
       }

       //初始化成员变量
       score = 0;
       for (int i = 0; i < MAXX; i++)
       {
           for (int j = 0; j < MAXY; j++)
           {
               box[i][j] = 0;
           }
       }
       for (int i = 0; i < COUNT; i++)
       {
           block.x[i] = (MAXX - 1) / 2;
           block.y[i] = -2;
       }
       block.centerX = (MAXX - 1) / 2;
       block.centerY = -2;
       block.ID = 0;

       //设置开始与暂停按钮
              //不直接使用UI是因为之前使用超时函数存在BUG，所以采用这种方式设置按钮
              //开始
             plays = new QPushButton(this);
             plays->setText("开始");
             plays->move(550,670);
             connect(plays,&QPushButton::pressed,this,&MainWindow::timestart);

             //暂停
             stops = new QPushButton(this);
             stops->setText("暂停");
             stops->move(550,720);
             connect(stops,&QPushButton::pressed,this,&MainWindow::timestop);

   }

void MainWindow::timestart()
{
       clear();
       score = 0;
       startTimerSlot();
       plays->setText("重新开始");
       time_on=1;
       stops->setText("暂停");
}
void MainWindow::timestop()
{
    if(time_on==1)
       {killTimer(refresh);
        startTimerSlot();
       stops->setText("继续游戏");
       time_on=0;
       }
       else{
            startTimerSlot();
            stops->setText("暂停");
           time_on=1;
           }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::clear()
{
    score = 0;
    for (int i = 0; i < MAXX; i++)
       {
           for (int j = 0; j < MAXY; j++)
           {
               box[i][j] = 0;
           }
       }

       //初始化成员变量

       for (int i = 0; i < MAXX; i++)
       {
           for (int j = 0; j < MAXY; j++)
           {
               box[i][j] = 0;
           }
       }
       for (int i = 0; i < COUNT; i++)
       {
           block.x[i] = (MAXX - 1) / 2;
           block.y[i] = -2;
       }
       block.centerX = (MAXX - 1) / 2;
       block.centerY = -2;
       block.ID = 0;
       ui->lcdNumber->display(score);
       //创建下一个方块
       scnextBlock();
       scBlock();

   }

void MainWindow::scnextBlock()
{
    int centerX = (MAXX - 1) / 2;

       int ID = rand() % 7;
       switch(ID){
       case 0:
             //##
             //##
             nextblock.x[0] = centerX;
             nextblock.x[1] = centerX;
             nextblock.x[2] = centerX + 1;
             nextblock.x[3] = centerX + 1;
             nextblock.y[0] = 1;
             nextblock.y[1] = 2;
             nextblock.y[2] = 1;
             nextblock.y[3] = 2;
             nextblock.centerX = 0;
             nextblock.centerY = 0;
             nextblock.ID = 0;
             break;
         case 1:
             //####
             //
             nextblock.x[0] = centerX - 1;
             nextblock.x[1] = centerX;
             nextblock.x[2] = centerX + 1;
             nextblock.x[3] = centerX + 2;
             nextblock.y[0] = 2;
             nextblock.y[1] = 2;
             nextblock.y[2] = 2;
             nextblock.y[3] = 2;
             nextblock.centerX = centerX;
             nextblock.centerY = 1;
             nextblock.ID = 1;
             break;
         case 2:
             //##
             // ##
             nextblock.x[0] = centerX - 1;
             nextblock.x[1] = centerX;
             nextblock.x[2] = centerX;
             nextblock.x[3] = centerX + 1;
             nextblock.y[0] = 1;
             nextblock.y[1] = 1;
             nextblock.y[2] = 2;
             nextblock.y[3] = 2;
             nextblock.centerX = centerX;
             nextblock.centerY = 1;
             nextblock.ID = 2;
             break;
         case 3:
             // ##
             //##
             nextblock.x[0] = centerX;
             nextblock.x[1] = centerX + 1;
             nextblock.x[2] = centerX - 1;
             nextblock.x[3] = centerX;
             nextblock.y[0] = 1;
             nextblock.y[1] = 1;
             nextblock.y[2] = 2;
             nextblock.y[3] = 2;
             nextblock.centerX = centerX;
             nextblock.centerY = 1;
             nextblock.ID = 3;
             break;
         case 4:
             //#
             //###
             nextblock.x[0] = centerX - 1;
             nextblock.x[1] = centerX - 1;
             nextblock.x[2] = centerX;
             nextblock.x[3] = centerX + 1;
             nextblock.y[0] = 1;
             nextblock.y[1] = 2;
             nextblock.y[2] = 2;
             nextblock.y[3] = 2;
             nextblock.centerX = centerX;
             nextblock.centerY = 1;
             nextblock.ID = 4;
             break;
         case 5:
              //  #
             //###
             nextblock.x[0] = centerX + 1;
             nextblock.x[1] = centerX - 1;
             nextblock.x[2] = centerX;
             nextblock.x[3] = centerX + 1;
             nextblock.y[0] = 1;
             nextblock.y[1] = 2;
             nextblock.y[2] = 2;
             nextblock.y[3] = 2;
             nextblock.centerX = centerX;
             nextblock.centerY = 2;
             nextblock.ID = 5;
             break;
         case 6:
             // #
             //###
             nextblock.x[0] = centerX;
             nextblock.x[1] = centerX - 1;
             nextblock.x[2] = centerX;
             nextblock.x[3] = centerX + 1;
             nextblock.y[0] = 1;
             nextblock.y[1] = 2;
             nextblock.y[2] = 2;
             nextblock.y[3] = 2;
             nextblock.centerX = centerX;
             nextblock.centerY = 1;
             nextblock.ID = 6;
             break;
         default:
           break;
        }


}
void MainWindow::scBlock()
{
    for(int i=0;i<COUNT;i++)
    {
        block.x[i]=nextblock.x[i];
        block.y[i]=nextblock.y[i];
    }
    block.centerX=nextblock.centerX;
    block.centerY=nextblock.centerY;
    block.ID=nextblock.ID;
    scnextBlock();

}
bool MainWindow::move(int dx, int dy)
{
    int NewX[COUNT] ;
       int NewY[COUNT] ;
       int newCenterX;
       int newCenterY;//定义移动后的坐标
        //碰撞检测
       //判段移动后是否会超出边界
       for(int i=0;i<COUNT;i++)
       {
           NewX[i] = block.x[i]+dx;
           NewY[i] = block.y[i]+dy;
           if(NewX[i]<0||NewX[i]>=MAXX)
           return false;// 左右边界限定
           if(NewY[i]>=MAXY)
           {
                   return false;//下边界限定，上边界是方块下落就没限定
           }
           else if(NewY[i]>=3&&NewY[i]<MAXY)
           {
               if(box[NewX[i]][NewY[i]]!=0)//判断变换后是否与方块碰撞
                   return false;
           }
       }
       //将新坐标赋值给旧坐标，刷新界面
         newCenterX = block.centerX+dx;
         newCenterY = block.centerY+dy;
         for(int i=0;i<COUNT;i++)
         {
             block.x[i] = NewX[i];
             block.y[i] = NewY[i];
         }
         block.centerX = newCenterX;
         block.centerY = newCenterY;
         update();
         return true;//更换移动后坐标
}
bool MainWindow::isRotatable()
{
    int newX[COUNT];
        int newY[COUNT];
        int newCenterX=block.centerX;
        int newCenterY=block.centerY;
        //田方块不需要转
         if (block.ID == 0)
        {
            return false;
        }
        //定义了中心焦点，旋转只需交换与焦点的坐标差
        for (int i = 0; i < COUNT; i++)
        {
            int newx = block.x[i] - block.centerX;
            int newy = block.y[i] - block.centerY;
            newX[i] =  block.centerX-newy;
            newY[i] = newx + block.centerY;
            //对变换后的坐标进行判定


            if (newX[i] < 0 || newX[i] >= MAXX)
            {
                return false;//左右边界限定
            }
            //已有方块位置限定
            if (newY[i] >=3 && newY[i] < MAXY)
            {
                if (box[newX[i]][newY[i]] == 1)
                {
                    return false;
                }
            }
            //下边界限定
            else if (newY[i] >= MAXY)
            {
                return false;
            }

        }

        //将新坐标赋值给旧坐标
        for (int i = 0; i < COUNT; i++)
        {
            block.x[i] = newX[i];
            block.y[i] = newY[i];
        }

        block.centerX = newCenterX;
        block.centerY = newCenterY;
        update();

        return true;
}
bool MainWindow::isend()
{
    for(int j=0;j<MAXX;j++)
       {if(box[j][2]==1)//判断第一行有方块赋值给棋盘
           {

               timestop();//停止计时
               time_on=2;


                   startTimerSlot();
                   killTimer(refresh);
                   stops->setText("游戏结束");


               //对话框提示游戏结束
               QMessageBox box(QMessageBox::Warning," ","游戏结束");
                box.setStandardButtons (QMessageBox::Ok);
                box.setButtonText (QMessageBox::Ok,QString("再来一次"));

                box.exec ();

           return true;}
       }
       return false;
   }
bool MainWindow::moveleft()
{
    if(time_on==1)//在游戏进行中
       {
       if(move(-1,0))
       {  return true;}
       else
           return false;
       }
       else
           return false;

}
bool MainWindow::moveright()
{
    if(time_on==1)
        {
        if(move(1,0)) {return true;}
        else
            return false;
        }
        else
            return false;
}
bool MainWindow::movedown()
{
    if(time_on==1)
       {
       if (!move(0, 1))
       {
           //移动不成功
         blocktobox();   //将当前方块复制到box中
           //判断是否结束
           if(isend())
           {
               return false;
           }
           else
           {
               scBlock();//生成下一方块
           }
       }
       }
       return true;
}
void MainWindow::blocktobox()
{
    for (int i = 0; i < 4; i++)
    {
        int x,y ;
        x = block.x[i];
        y = block.y[i];
        box[x][y] = 1;
        killline();//消行

    }
}
int MainWindow::getline()
{
    //因为要查看每行，故循环顺序换了一下
        for(int i=3;i<=MAXY;i++)
        {   int team=1;
            for(int j=0;j<MAXX;j++){
                if(box[j][i]!=1)//判断是否全为1
                 {   team=0;
                     break;
                }
            }


        if(team)
        {
            return i;//返回当前行
        }
    }
         return 0;

}
void MainWindow::killline()
{
    int count = 0;  //一次消掉的行数

        int temp = 0;//消掉行的y坐标
        //获取消除行，并将该行以上行赋值给下一行，实现方块整体下落
        if ((temp = getline()) !=0)
        {
            for (int j = temp; j >0; j--)
            {
                for (int i = 0; i < MAXX; i++)
                {
                    box[i][j] = box[i][j-1];
                }
            }
            count++;
        }
        //消行的分数奖励并显示得分
        score += count * 10;
        ui->lcdNumber->display(score);
}
//定时器，控制方块自动下落
void MainWindow::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == this->refresh)
          movedown();
           update();
}
//设置定时器时间
void MainWindow::startTimerSlot()
{
    //设置定时器，返回一个timerld.
            refresh = startTimer(500);
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
        case Qt::Key_A:
            moveleft();
            break;
        case Qt::Key_D:
            moveright();
            break;
        case Qt::Key_S:
            movedown();
            break;
        case Qt::Key_W:
            isRotatable();
            break;

        }
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter p;
    p.begin(this);
    QPen pen;
    pen.setWidth(1);//大小
    pen.setColor(QColor(20,20,20));//颜色
    p.setPen(pen);
    //棋盘边框
       p.drawRect(30,20,400,840);
       //下一方块棋盘边框
       p.drawRect(500,40,240,240);
       p.drawRect(500,420,240,220);
       //棋盘稳定方块上色
       p.setBrush(QBrush(QColor(192,192,192),Qt::SolidPattern));
       for(int i=0;i<MAXX;i++)
           for(int j=3;j<MAXY;j++)
             {  if(box[i][j]==1)
                   p.drawRect(40*i+30,40*j-60,39,39);
             }
       //下落方块上色
       p.setBrush(QBrush(QColor(190,190,190),Qt::SolidPattern));
       for (int i = 0; i < COUNT; i++)
           {
               int x = block.x[i];
               int y = block.y[i];
               p.drawRect(40*x+30,40*y-60,39,39);
           }
       //下一个方块上色,
      for (int i = 0; i <4; i++)
       {
           int x = nextblock.x[i];
           int y = nextblock.y[i];
           p.drawRect(x*40+430, y*40+80, 39, 39);
       }

        p.end();

}













