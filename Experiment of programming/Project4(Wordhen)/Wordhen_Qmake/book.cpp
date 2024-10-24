#include "book.h"


Book::Book(QString _name)
{
    //命名
    name = _name;

    //打开文件
    QFile file(QString(":/book/build/Desktop_Qt_6_7_1_MSVC2019_64bit-Debug/%1.csv").arg(name));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
        return;
    }
    QTextStream in(&file);

    QString line;
    while (!in.atEnd())
    {
        line = in.readLine();
        QStringList relation = line.split("|"); // 根据逗号分隔符解析字段
        if (relation.size() != 5) // 确保每行数据只有两个字段
        {
            if(relation.size() != 3)
            {
                relation.append("0");
                relation.append("0");
            }
            else
                continue;
        }
        Word wordPair = Word(relation);
        if(wordPair.word == "")
            qDebug()<<"here";
        wordList[wordPair.word] = wordPair;
        if(wordPair.learnt)
        {
            learntList.append(&wordList[wordPair.word]);
        }
        else
        {
            unlearntList.append(&wordList[wordPair.word]);
        }
    }

    readFromCsv(starList, "star");
}
Book::Book(int index)
{
    QStringList namelist = {"HighSchool", "MiddleSchool", "PrimarySchool"};
    name = namelist[index];

    QFile file(QString(":/book/build/Desktop_Qt_6_7_1_MSVC2019_64bit-Debug/%1.csv").arg(name));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file";
        return;
    }
    QTextStream in(&file);

    QString line;
    while (!in.atEnd())
    {
        line = in.readLine();
        QStringList relation = line.split("|"); // 根据逗号分隔符解析字段
        if (relation.size() != 5) // 确保每行数据只有两个字段
        {
            if(relation.size() == 3)
            {
                relation.append("0");
                relation.append("0");
            }
            else
                continue;
        }
        Word wordPair = Word(relation);
        if(wordPair.word == "")
            qDebug()<<"here";
        wordList[wordPair.word] = wordPair;
        if(wordPair.learnt)
        {
            learntList.append(&wordList[wordPair.word]);
        }
        else
        {
            unlearntList.append(&wordList[wordPair.word]);
        }
    }

    readFromCsv(starList, "star");
}
bool Book::writeFile()
{
    QFile file(QString("%1.csv").arg(name));
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        for(auto a : wordList){
            out<<QString("%1|%2|%3|%4|%5\n").arg(a.word).arg(a.pronunciation).arg(a.meaning.join("#")).arg(a.learnt).arg(a.reviewtimes);
        }
        file.close();
    }

    QFile filestar(QString("star.csv"));
    if(filestar.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&filestar);
        for(auto a : starList){
            out<<QString("%1|%2|%3|%4|%5\n").arg(a.word).arg(a.pronunciation).arg(a.meaning.join("#")).arg(a.learnt).arg(a.reviewtimes);
        }
        filestar.close();
        return true;
    }
    else{
        return false;
    }

}

Book::~Book()
{
    writeFile();
}
