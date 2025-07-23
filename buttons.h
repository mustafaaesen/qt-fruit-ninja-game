#ifndef BUTTONS_H
#define BUTTONS_H

#include <QPushButton>
#include <QObject>
#include <QWidget>


class buttons : public QPushButton
{
    Q_OBJECT
public:
    buttons(QWidget *parrent=0);
    bool tikladinmi;
    bool kacirdinmi;
public slots:
    void click();
};



#endif // BUTTONS_H
