#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QDebug>
#include <QTextStream>
#include <stdio.h>
#include <QMap>
#include <QVector>
#include <algorithm>
#include <QPair>
#include <QFile>
#include <QMessageBox>
#include <QTextEdit>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString file;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_textBrowser_destroyed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
