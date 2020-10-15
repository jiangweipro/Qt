#include "Widget.h"
#include "ui_Widget.h"

#include <QPushButton>
#include <QDialog>


#include "teacher.h"
#include "student.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    // 设置窗口固定大小
    this->setFixedSize(1000, 500);
    ui->setupUi(this);

    // 创建按钮
    QPushButton *bnt = new QPushButton("下课啦", this);
    Teacher *t = new Teacher(this);
    Student *s = new Student(this);

    // 信号连接信号
    connect(bnt, &QPushButton::clicked, t, &Teacher::classIsOver);
    // 信号连接槽
    connect(t, &Teacher::classIsOver, s, &Student::listenTeacher);

    QPushButton *bnt2 = new QPushButton("关闭", this);
    // 设置按钮位置
    bnt2->move(200, 100);
    connect(bnt2, &QPushButton::clicked, this, [=](){this->close();});

    // 创建对话框
    QDialog *dialog = new QDialog(this);
    // 设置为非模态
    dialog->setModal(false);
    dialog->setFixedSize(200, 100);
    dialog->move(300, 100);
    QPushButton *bnt3 = new QPushButton("open", this);
    bnt3->move(400, 200);
    // 可使用lambda表达式
    connect(bnt3, &QPushButton::clicked, this, [=](){
        if(bnt3->text() == "open") {
            bnt3->setText("close");
            dialog->show();
            return;
        }
        bnt3->setText("open");
        dialog->close();
    });

}

Widget::~Widget()
{
    delete ui;
}

