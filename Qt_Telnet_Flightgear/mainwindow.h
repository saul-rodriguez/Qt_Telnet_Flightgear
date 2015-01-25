#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../../Qtraspberrylib/qttelnet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButton_clicked();

    void on_dial_valueChanged(int value);

public slots:
    void telnetMessage(const QString &msg);
    void telnetConnectionError(QAbstractSocket::SocketError);

private:
    Ui::MainWindow *ui;

    QtTelnet *comm;
};

#endif // MAINWINDOW_H
