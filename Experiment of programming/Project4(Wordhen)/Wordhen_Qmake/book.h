#ifndef BOOK_H
#define BOOK_H
#include <QVector>
//#include <string>
#include <QString>
#include <QFile>
#include <QWidget>

using namespace std;

class Word
{
public:
    QString word;
    QString pronunciation;
    QStringList meaning;
    bool learnt;
    int reviewtimes;

    Word()
        :word(""), pronunciation(""), meaning(""), learnt(0), reviewtimes(0){}
    Word(QString _word, QString _pronunciation, QString _meaning, bool _memorised, int _reviewtimes)
        :word(_word), pronunciation(_pronunciation), meaning(_meaning.split("#")), learnt(_memorised), reviewtimes(_reviewtimes){}
    Word(QStringList list)
        :word(list[0]), pronunciation(list[1]), meaning(list[2].split("#")), learnt(list[3].toInt()), reviewtimes(list[4].toInt()){}
    bool operator==(const Word &b)
    {
        return word==b.word && pronunciation == b.pronunciation && meaning == b.meaning;
    }
    Word & operator=(const Word &b)
    {
        word = b.word;
        pronunciation = b.pronunciation;
        meaning = b.meaning;
        learnt = b.learnt;
        reviewtimes = b.reviewtimes;
        return *this;
    }
};

inline void operator<<(QTextStream &out, Word a)
{
    out<< QString("%1|%2|%3|%4|%5\n").arg(a.word).arg(a.pronunciation).arg(a.meaning.join("#")).arg(a.learnt).arg(a.reviewtimes);
    return;
}

class Book
{
public:
    QString name;
    QMap<QString, Word> wordList;
    QVector<Word *> unlearntList;
    QVector<Word *> learntList;
    QVector<Word> starList;

    Book(QString name = "HighSchool");
    Book(int index);
    ~Book();
    bool writeFile();
};

inline void readFromCsv(QVector<Word> & list, QString name)
{
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
        Word word = Word(relation);
        list.push_back(word);
    }

}

#endif // BOOK_H
