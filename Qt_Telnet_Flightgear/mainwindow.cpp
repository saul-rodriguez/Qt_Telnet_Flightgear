#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qmessagebox.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_IP->setText("192.168.0.13");
    ui->lineEdit_PORT->setText("5401");

    //Creation of QtTelnet object and connection of slots
    comm = new QtTelnet;
    connect(comm, SIGNAL(message(QString)),this, SLOT(telnetMessage(QString)));
    connect(comm, SIGNAL(connectionError(QAbstractSocket::SocketError)),
            this,SLOT(telnetConnectionError(QAbstractSocket::SocketError)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString IP = ui->lineEdit_IP->text();
    qDebug(IP.toAscii());

    QString Sport = ui->lineEdit_PORT->text();
    int port = Sport.toInt();

    comm->connectToHost(IP,port);
    comm->sendData("ls");
    comm->sendData("data");

}

void MainWindow::on_dial_valueChanged(int value)
{

    QVariant aux(value);
    QString command = "set /autopilot/settings/target-speed-kt ";
    command += aux.toString();

    comm->sendData(command);
}

void MainWindow::telnetMessage(const QString &msg)
{
    qDebug(msg.toAscii());
}

void MainWindow::telnetConnectionError(QAbstractSocket::SocketError)
{
    QMessageBox msg;
    msg.setText("Telnet connection error, try again");
    msg.exec();

}

