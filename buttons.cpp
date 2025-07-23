#include "buttons.h"

buttons::buttons(QWidget *parrent):QPushButton(parrent)
{
    tikladinmi=false;
    kacirdinmi=true;
    connect(this,&QPushButton::clicked,this,&buttons::click);
}

void buttons::click()
{
    tikladinmi=!tikladinmi;
    kacirdinmi=false;
}



