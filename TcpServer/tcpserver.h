#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpServer; }
QT_END_NAMESPACE

class TcpServer : public QMainWindow
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = nullptr);
    ~TcpServer();
    void loadConfig();


private:
    Ui::TcpServer *ui;
    QString my_strIP;
    quint16 my_intPort;

};
#endif // TCPSERVER_H
