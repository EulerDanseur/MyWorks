#include "network.h"
#include<QList>
#include<QDesktopServices>
netWork::netWork(QObject *parent) :
    QObject(parent)
{
    http=new QNetworkAccessManager(this);
    http->setCookieJar(new QNetworkCookieJar(this));
    connect(http,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyfinished(QNetworkReply*)));//将finished信号与我们定义的槽关联，每当网络应答结束时，都会发射这个信号
    isBusy=true;

}

QString netWork::getCookie(const QString &name)//用于获得SessionId
{
    foreach(QNetworkCookie cookie , http->cookieJar()->cookiesForUrl(QUrl("http://www.shanbay.com/")))
    {
        if(cookie.name()==name)
        {
            qDebug()<<"csrftoken:"<<cookie.value();
            return cookie.value();
        }
    }
    return "";
}
void netWork::connectNet(QString username, QString password)//连接网络,使用默认的用户名和密码
{
    this->username=username;
    this->password=password;
    QNetworkRequest request;
    request.setUrl(QUrl("http://www.shanbay.com/accounts/login/"));
    request.setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    request.setRawHeader("Accept-Language","zh-CN,zh;q=0.8");
    request.setRawHeader("Cache-Control","max-age=0");
    request.setRawHeader("Connection","keep-alive");
    request.setRawHeader("Host","www.shanbay.com");
    request.setRawHeader("User-Agent","Mozilla/5.0 (Windows NT 6.1) AppleWebKit/535.7 (KHTML, like Gecko) Chrome/16.0.912.63 Safari/535.7");
    httpAction=GetSessionidAction;
    http->get(request);
}

void netWork::replyfinished(QNetworkReply *reply)//每当执行网站应答结束后，就会执行该槽函数
{
    QVariant status_code=reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    qDebug()<<"code_state="<<status_code;//网络状态,200代表正常，302代表重定向，404：not found等等
    if(status_code==QVariant::Invalid)//判断是否连接到网站,即当前设备能否上网
        emit NetState(false);
    else
        emit NetState(true);

    switch(httpAction)//根据我们都进行了什么网络请求
    {
    case NoAction:
        break;
    case GetSessionidAction://获取SessionId
        sessionid=getCookie("csrftoken");
        if(!sessionid.isEmpty())
        {
            emit connectSuccess();
            qDebug()<<("已经连接扇贝网，正在验证用户名密码...");
            loginShanbay();
        }else
        {
            emit connectFail();

            qDebug()<<("Cannot connect to the website!");
        }

        break;
    case LoginAction: //进行登录操作
        httpAction=NoAction;
        if(0==reply->readAll().size())
        {
            QString nickname=QUrl::fromPercentEncoding(getCookie("username").toLatin1());
            emit verifySuccess();

            qDebug()<<"Successfully Login"<<nickname;
            queryWord("hello");
        }else
        {
            emit verifyFail();
            qDebug()<<"Failed to login!";
        }
        break;

    case QueryWordAction://查词操作
        qDebug()<<"----query word----";
        qDebug()<<reply->readAll();//读取查词结果

        addWord("hello");//添加单词到单词本
        break;
    case AddWordAction://添词操作
        qDebug()<<"---add word----";
        qDebug()<<reply->readAll();//返回添加词语的learning_id
        break;
    default:break;
    }
}

void netWork::loginShanbay()//账户密码的登录操作
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://www.shanbay.com/accounts/login/"));
    request.setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    request.setRawHeader("Accept-Language","zh-CN,zh;q=0.8");
    request.setRawHeader("Cache-Control","max-age=0");
    request.setRawHeader("Connection","keep-alive");
    request.setRawHeader("Host","www.shanbay.com");
    request.setRawHeader("User-Agent","Mozilla/5.0 (Windows NT 6.1) AppleWebKit/535.7 (KHTML, like Gecko) Chrome/16.0.912.63 Safari/535.7");
    request.setRawHeader("Origin","http//www.shanbay.com");
    request.setRawHeader("Referer","http://www.shanbay.com/accounts/login/");
    request.setRawHeader("Host","www.shanbay.com");
    request.setRawHeader("Content-Type","application/x-www-form-urlencoded");
    QByteArray postData;
    postData.append(QString("csrfmiddlewaretoken=%1&").arg(sessionid).toUtf8());
    postData.append(QString("username=%1&password=%2&").arg(QUrl::toPercentEncoding(username).constData()).arg(password).toUtf8());
    postData.append("login=登录&continue=home&u=1&next=");
    request.setHeader(QNetworkRequest::ContentLengthHeader,postData.size());
    httpAction=LoginAction;
    http->post(request,postData);

}

void netWork::queryWord(const QString &word)//查词操作
{
    QNetworkRequest request;
    request.setUrl(QUrl("http://www.shanbay.com/api/word/"+word));
    request.setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    request.setRawHeader("Accept-Charset","GBK,utf-8;q=0.7,*;q=0.3");
    request.setRawHeader("Accept-Language","zh-CN,zh;q=0.8");
    request.setRawHeader("Cache-Control","max-age=0");
    request.setRawHeader("Connection","keep-alive");
    request.setRawHeader("Host","www.shanbay.com");
    request.setRawHeader("User-Agent","Mozilla/5.0 (Windows NT 6.1) AppleWebKit/535.7 (KHTML, like Gecko) Chrome/16.0.912.63 Safari/535.7");
    httpAction=QueryWordAction;
    http->get(request);
}



void netWork::addWord(const QString &word)//添词操作
{
    if(word.isEmpty())
        qDebug()<<"你的输入有误";
    else
    {
        QNetworkRequest request;
        request.setUrl(QUrl("http://www.shanbay.com/api/learning/add/"+word));
        request.setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
        request.setRawHeader("Accept-Charset","GBK,utf-8;q=0.7,*;q=0.3");
        request.setRawHeader("Accept-Language","zh-CN,zh;q=0.8");
        request.setRawHeader("Cache-Control","max-age=0");
        request.setRawHeader("Connection","keep-alive");
        request.setRawHeader("Host","www.shanbay.com");
        request.setRawHeader("User-Agent","Mozilla/5.0 (Windows NT 6.1) AppleWebKit/535.7 (KHTML, like Gecko) Chrome/16.0.912.63 Safari/535.7");
        httpAction=AddWordAction;
        http->get(request);
    }
}
