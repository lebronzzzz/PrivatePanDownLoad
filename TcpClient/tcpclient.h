#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QMainWindow>
#include <QFile>
#include<QTcpSocket>
QT_BEGIN_NAMESPACE
namespace Ui { class TcpClient; }
QT_END_NAMESPACE

class TcpClient : public QMainWindow
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();
    void loadConfig();
    //在类中定义这个类，直接使用他的方法
    //体现了C++中封装和继承的重要性
    QTcpSocket my_tcpSocket;

public slots:
    void  showConnect();

private slots:
    void on_send_clicked();

private:
    Ui::TcpClient *ui;
    QString my_strIP;
    quint16 my_intPort;

};
#endif // TCPCLIENT_H
