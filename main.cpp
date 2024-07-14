#include <QApplication>
#include <QPushButton>
#include "./src/MyOpenGL.h"
#include <QOpenGLContext>
#include <QOffscreenSurface>
#include <QDebug>
#include <QOpenGLFunctions>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QOffscreenSurface surf;
    surf.create();
    QOpenGLContext ctx;
    ctx.create();
    ctx.makeCurrent(&surf);

    // 使用OpenGL的API获取版本信息
    ctx.functions()->glGetString(GL_VERSION); // 获取完整的版本字符串
    GLint major, minor;
    ctx.functions()->glGetIntegerv(GL_MAJOR_VERSION, &major); // 获取主版本号
    ctx.functions()->glGetIntegerv(GL_MINOR_VERSION, &minor); // 获取次版本号

    qDebug() << "OpenGL Version Info:" << (const char*)ctx.functions()->glGetString(GL_VERSION);
    qDebug() << "OpenGL Version Major:" << major << "OpenGL Version Minor:" << minor;

    ctx.doneCurrent();
    MyOpenGL myOpenGl;
    myOpenGl.show();
    return QApplication::exec();
}
