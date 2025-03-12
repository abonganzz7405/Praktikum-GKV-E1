#include <GL/glew.h>
#include <GLFW/glfw3.h>

void drawShapes() {
    glLineWidth(2.0f);
    
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(-0.3f, 0.7f);
    glVertex2f(-0.1f, 0.5f);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.3f, 0.5f);
    glVertex2f(0.5f, 0.7f);
    glVertex2f(0.7f, 0.5f);
    glEnd();
    
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(-0.1f, -0.4f);
    glVertex2f(0.1f, -0.4f);
    glVertex2f(0.2f, -0.5f);
    glVertex2f(-0.2f, -0.5f);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.3f, -0.5f);
    glVertex2f(-0.3f, -0.7f);
    glVertex2f(-0.5f, -0.7f);
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Gambar OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawShapes();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
