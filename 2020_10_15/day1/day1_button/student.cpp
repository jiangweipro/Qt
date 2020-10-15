#include "student.h"

#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::listenTeacher()
{
    qDebug("吃饭啦");
}
