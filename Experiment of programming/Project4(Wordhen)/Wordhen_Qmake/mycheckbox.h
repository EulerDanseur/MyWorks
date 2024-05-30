#ifndef MYCHECKBOX_H
#define MYCHECKBOX_H

#include <QCheckBox>

class MyCheckBox : public QCheckBox
{
public:
    MyCheckBox(QString text,QWidget *parent)
        : QCheckBox(text,parent)
    {}


    MyCheckBox(QWidget *parent)
        : QCheckBox(parent)
    {

    }


protected:


    void mouseReleaseEvent(QMouseEvent *e)
    {
        setChecked(!isChecked());
        emit clicked(isChecked());
    }

};

#endif // MYCHECKBOX_H

