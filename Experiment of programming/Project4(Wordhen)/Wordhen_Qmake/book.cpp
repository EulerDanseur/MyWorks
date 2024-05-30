#include "book.h"


Book::Book(QString _name)
{
    name = _name;

    QFile file(QString(":/book/%1.csv").arg(name));
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
            if(relation.size()==3)
            {
                relation.append("0");
                relation.append("0");
            }
            else
            {
                continue;
            }
        }
        Word wordPair = Word(relation);
        wordList[wordPair.word] = wordPair;
        if(wordPair.learnt)
        {
            learntList.append(&wordList[wordPair.word]);
        }
        else
        {
            unlearnList.append(&wordList[wordPair.word]);
        }
    }

    readFromCsv(starList, "star");
}

bool Book::writeFile()
{
    QFile file(QString("D:\\MyWorks\\MyWorks\\Experiment of programming\\Project4(Wordhen)\\Wordhen_Qmake\\%1.csv").arg(name));
    if(file.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        for(auto a : wordList){
            //out << i;
            qDebug()<<QString("%1|%2|%3|%4|%5\n").arg(a.word).arg(a.pronunciation).arg(a.meaning).arg(a.learnt).arg(a.reviewtimes);

            out<<QString("%1|%2|%3|%4|%5\n").arg(a.word).arg(a.pronunciation).arg(a.meaning).arg(a.learnt).arg(a.reviewtimes);
        }
        file.close();
        return true;
    }
    else{
        return false;
    }

    QFile filestar(QString("star.csv"));
    if(filestar.open(QIODevice::WriteOnly|QIODevice::Text)){
        QTextStream out(&file);
        for(auto i : wordList){
            out << i;
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
