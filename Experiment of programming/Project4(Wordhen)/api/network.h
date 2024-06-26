#ifndef NETWORK_H
#define NETWORK_H


#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkReply>
#include<QtNetwork/QNetworkRequest>
#include<QtNetwork/QNetworkCookie>
#include<QtNetwork/QNetworkCookieJar>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include<QString>
#include<QDebug>
#include<QList>
#include<QUrl>
#include<QByteArray>

class netWork : public QObject //由于程序文件直接摘自整个项目文件，所以程序中有关的定义或函数没有使用，但是这个程序可以单独运行
{
    Q_OBJECT
public:
    explicit netWork(QObject *parent = 0);
    //   ~netWork();


    enum HttpAction{NoAction,NetStudy,GetSessionidAction,LoginAction,QueryWordAction,AddWordAction,AddExampleAction,QueryWordExamplesAction};
    HttpAction httpAction;
    QNetworkAccessManager * http;
    QString sessionid;
    QString queryword;//要查询的单词
    QString nickname;
    QString username;
    QString password;
    bool isBusy;


    QString getCookie(const QString &name);

    void loginShanbay();
    void queryWord(const QString &word);
    void queryExamples(QString learningid);
    void connectNet(QString username="nineheadedbird", QString password="123456");
    void addWord(const QString &word);

signals://这里的信号都没有用到

    void connectSuccess();
    void connectFail();
    void verifySuccess();
    void verifyFail();
    void NetState(bool);
public slots:
    void replyfinished(QNetworkReply*);

};

#endif // NETWORK_H
