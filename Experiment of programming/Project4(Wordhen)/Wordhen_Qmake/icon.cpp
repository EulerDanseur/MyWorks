#include "icon.h"
#include <QFontDatabase>
#include <QStringList>
FontAwesomeIcons &FontAwesomeIcons::Instance() {
    static FontAwesomeIcons _instance;
    return _instance;
}

FontAwesomeIcons::FontAwesomeIcons() {
    int fontId = QFontDatabase::addApplicationFont("D:\\MyWorks\\MyWorks\\Experiment of programming\\Project4(Wordhen)\\Wordhen/fontawesome-webfont.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);

    this->font.setFamily(fontFamilies.at(0));
    this->font.setPointSize(10);
}

QFont FontAwesomeIcons::getFont() {
    return this->font;
}

QChar FontAwesomeIcons::getIconChar(FontAwesomeIcons::IconIdentity code) {
    return QChar(static_cast<int>(code));
}


