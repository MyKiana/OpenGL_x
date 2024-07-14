//
// Created by Kiana on 2024/7/12.
//

#ifndef OPENGL_S_GLTRIANGLE_H
#define OPENGL_S_GLTRIANGLE_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QDebug>
#include <gl/GLU.h>
#include <gl/GL.h>
#include <QOpenGLVertexArrayObject>

class GLTriangle : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
Q_OBJECT
public:
    explicit GLTriangle(QWidget *parent = nullptr);
    ~GLTriangle() override;
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

private:
    GLuint vao;
    GLuint vbo;
    GLuint ebo;

    // 顶点着色器
    GLuint vertexShader;
    // 片段着色器
    GLuint fragmentShader;
    // 着色器程序
    GLuint shaderProgram;


    char *vertexShaderSource;
    char *fragmentShaderSource;


};

#endif //OPENGL_S_GLTRIANGLE_H
