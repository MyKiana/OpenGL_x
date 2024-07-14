//
// Created by Kiana on 2024/7/12.
//

#ifndef OPENGL_S_MYOPENGL_H
#define OPENGL_S_MYOPENGL_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class MyOpenGL; }
QT_END_NAMESPACE

class MyOpenGL : public QWidget {
Q_OBJECT

public:
    explicit MyOpenGL(QWidget *parent = nullptr);

    ~MyOpenGL() override;


private:
    Ui::MyOpenGL *ui;


};


#endif //OPENGL_S_MYOPENGL_H
