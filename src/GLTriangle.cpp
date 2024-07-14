//
// Created by Kiana on 2024/7/12.
//


#include "GLTriangle.h"



GLTriangle::GLTriangle(QWidget *parent) {
    qDebug() << __FUNCTION__ ;
    // Vertex Shader
    vertexShaderSource =
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main() {\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z,1.0);\n"
            "}\0";

    // Fragment Shader
    fragmentShaderSource =
            "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main() {\n"
            "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n" // 金色
            "}\n\0";
}

GLTriangle::~GLTriangle() {
    qDebug() << __FUNCTION__ ;
    makeCurrent();
    glDeleteVertexArrays(1,&vbo);
    glDeleteBuffers(1,&vao);
    glDeleteProgram(shaderProgram);
    doneCurrent();
}

void GLTriangle::initializeGL() {
    qDebug() << __FUNCTION__; // 打印当前函数名到调试输出，用于调试目的

    initializeOpenGLFunctions(); // 初始化OpenGL函数指针，确保后续能够正确调用OpenGL的函数

    // 顶点数据，定义了一个三角形的三个顶点坐标
    // 每个顶点由三个浮点数表示（x, y, z），这里z为0表示在二维平面上
/*    float vertices[] = {
            -0.5f, -0.5f, 0.0f, // 左下角
            0.5f, -0.5f, 0.0f, // 右下角
            -0.5f,  0.5f, 0.0f, // 左上角

            -0.5f,  0.5f, 0.0f, // 左角
            0.5f, -0.5f, 0.0f, // 右下角
            0.5f, 0.5f, 0.0f,  // 右上角
    };*/
    float vertices[] = {
            -0.5f, -0.5f, 0.0f, // 左下角
            0.5f, -0.5f, 0.0f, // 右下角
            -0.5f,  0.5f, 0.0f, // 左上角
            0.5f, 0.5f, 0.0f,  // 右上角
    };

    unsigned int indices[] = {
            0,1,2,
            1,2,3
    };

    // 创建一个缓冲区对象（VBO）用于存储顶点数据
    glGenBuffers(1, &vbo); // 生成一个VBO，并将返回的标识符存储在vbo中

    // 绑定VBO，使其成为当前操作的目标
    glBindBuffer(GL_ARRAY_BUFFER, vbo);

    // 将顶点数据上传到GPU的VBO中
    // 第三个参数指定了数据的大小，第四个参数是数据的指针，第五个参数指定了数据的使用方式
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // 创建一个顶点数组对象（VAO）
    // VAO能够保存顶点数据的绑定状态（比如VBO的绑定和顶点属性的配置）
    glGenVertexArrays(1, &vao);

    // 绑定VAO，使其成为当前操作的目标
    glBindVertexArray(vao);

    // 启用顶点属性0的顶点数组
    // 在OpenGL中，顶点属性索引从0开始
    glEnableVertexAttribArray(0);

    // 配置顶点属性0的指针
    // 第一个参数是顶点属性索引，第二个参数是每个顶点属性的组件数量（这里是3个float表示一个坐标）
    // 第三个参数是数据类型，第四个参数是否归一化（这里不使用归一化），第五个参数是步长（每个顶点占用的字节数）
    // 第六个参数是数据在缓冲区中的偏移量（这里从缓冲区开始处）
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glGenBuffers(1,&ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices),indices,GL_STATIC_DRAW);


    // 解绑VBO和VAO，这不是必须的，但好习惯是在不需要它们时解绑
    // 这样可以避免在后续操作中意外修改它们的状态
    glBindBuffer(GL_ARRAY_BUFFER, 0); // 将ARRAY_BUFFER的绑定设置为0，即解绑当前VBO
    glBindVertexArray(0); // 将VERTEX_ARRAY的绑定设置为0，即解绑当前VAO

    // 顶点着色器
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // 检查编译是否成功
    int success; char infoLog[512];
    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    if(!success){
        glGetShaderInfoLog(vertexShader,512,NULL,infoLog);

    }

    // 片段着色器
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}

///绘画函数
void GLTriangle::paintGL() {
    qDebug() << __FUNCTION__ ;

    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glBindVertexArray(vao);
    //glDrawArrays(GL_TRIANGLES, 3, 6);
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,NULL);
}

/// 大小改变
/// \param width
/// \param height
void GLTriangle::resizeGL(int width, int height) {
    qDebug() << __FUNCTION__ ;
    //QOpenGLWidget::resizeGL(width, height);
    glViewport(0, 0, width, height);

}
