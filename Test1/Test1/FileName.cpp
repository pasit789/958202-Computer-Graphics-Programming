#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/glut.h>
#include <cmath>

constexpr float DEG2RAD = 3.14159265f / 180.0f;

void drawCircle(float radius)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; ++i) {
        const float degInRad = i * DEG2RAD;
        glVertex2f(std::cos(degInRad) * radius, std::sin(degInRad) * radius);
    }
    glEnd();
}

void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCircle(5.0f);
    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 320);
    glutCreateWindow("GLUT Tutorial");
    init();
    glutDisplayFunc(RenderScene);
    glutMainLoop();
    return 0;
}