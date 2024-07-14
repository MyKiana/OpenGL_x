//
// Created by Kiana on 2024/7/12.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MyOpenGL.h" resolved

#include "MyOpenGL.h"
#include "ui_MyOpenGL.h"


MyOpenGL::MyOpenGL(QWidget *parent) :
        QWidget(parent), ui(new Ui::MyOpenGL) {
    ui->setupUi(this);

}

MyOpenGL::~MyOpenGL() {
    delete ui;
}
