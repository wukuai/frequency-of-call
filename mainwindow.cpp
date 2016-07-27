#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdio.h"
#include "vector"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon("hf64.ico"));
    file="";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textBrowser->clear();
    file= QFileDialog::getOpenFileName(this);
    if(file.length()<=2){
        QMessageBox *fail=new QMessageBox;
        fail->setWindowTitle("提示");
        fail->setText("请选择文件！");
        fail->exec();
    }

    else if(!file.endsWith(".txt")){
        QMessageBox *fail=new QMessageBox;
        fail->setWindowTitle("提示");
        fail->setText("请打开txt文件！");
        fail->exec();
    }
    else{
        QFile file(this->file);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
             qDebug()<<"Can't open the file!"<<endl;
         }
         while(!file.atEnd()) {
             QByteArray line = file.readLine();
             QString str(line);
             str.remove("\n");
             ui->textBrowser->append(str);
         }
    }

//    qDebug()<<file;
}

void MainWindow::on_pushButton_2_clicked()
{ 
   if(file.length()<=2){
       QMessageBox *fail=new QMessageBox;
       fail->setWindowTitle("提示");
       fail->setText("请选择文件！");
       fail->exec();
   }
   else if(!file.endsWith(".txt")){
       QMessageBox *fail=new QMessageBox;
       fail->setWindowTitle("提示");
       fail->setText("请打开txt文件！");
       fail->exec();
   }
   else{
       QFile outfile("out.txt");
       if (!outfile.open(QIODevice::WriteOnly | QIODevice::Text))
             return;
       QTextStream out(&outfile);


        QFile file(this->file);
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug()<<"Can't open the file!"<<endl;
        }

        QMap<QString,int> scoreMap;

        while(!file.atEnd()) {
            QByteArray line = file.readLine();
            QString str(line);
    //        qDebug()<< str;
            str.remove("\n");
            scoreMap[str]++;
//          ui->textBrowser->append(str);
        }

        QMap<QString, int>::const_iterator i;
        int value_max=0;
        for (i = scoreMap.constBegin(); i != scoreMap.constEnd(); ++i) {
            qDebug() << i.key() << ":" << i.value();
            if(i.value()>value_max) value_max=i.value();
        }

        int cnt;

        ui->textBrowser->clear();

        for(cnt=value_max;cnt>=0;cnt--){
            for(i = scoreMap.constBegin(); i != scoreMap.constEnd(); ++i)
            {
                if(cnt==i.value()){
                    out<<i.key()<<" "<<i.value()<<"\n";
                    ui->textBrowser->append(i.key()+" "+QString::number(i.value()));
                }
            }
        }

        QMessageBox *success =new QMessageBox;
        success->setWindowTitle("导出成功");
        success->setText("统计完成并已导出到\n"
                        "本软件根目录out.txt中");
        success->exec();
   }

}

void MainWindow::on_textBrowser_destroyed()
{

}
