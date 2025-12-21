

#include <GL/glut.h>

/* زاویه‌ها */
GLfloat angle = 0.0, angle1 = 0.0, angle2 = 0.0; /*تعریف متغیر های گلوبال از نوع فلوت مخصوص اوپن جی ال*/


GLfloat speedSun = 0.02;
GLfloat speedPlanet = 0.01;
GLfloat speedMoon = 0.05;

/* رنگ‌ها (دیفالت) */
GLfloat sunColor[3] = { 1.0, 1.0, 0.0 };   // زرد
GLfloat venusColor[3] = { 1.0, 0.5, 0.0 };   // نارنجی
GLfloat earthColor[3] = { 0.0, 0.0, 1.0 };   // آبی
GLfloat moonColor[3] = { 0.6, 0.6, 0.6 };   // طوسی

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    /* زهره */
    glLoadIdentity();
    glColor3fv(venusColor);
    glRotatef(angle1, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 3.0, 0.0);
    glRotatef(angle2, 0.0, 0.0, 1.0);
    glScalef(0.3, 0.3, 0.3);
    glutWireDodecahedron();

    /* زمین */
    glLoadIdentity();
    glColor3fv(earthColor);
    glRotatef(angle1, 0.0, 0.0, 1.0);
    glTranslatef(7.0, 0.0, 0.0);
    glutWireTeapot(0.7);

    /* ماه */
    glColor3fv(moonColor);
    glRotatef(angle2, 0.0, 0.0, 1.0);
    glTranslatef(2.0, 0.0, 0.0);
    glutWireSphere(0.5, 6, 6);

    /* خورشید */
    glLoadIdentity();
    glColor3fv(sunColor);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glutWireTorus(0.3, 0.7, 10, 10);

    glutSwapBuffers();

}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -10, 10);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void test()
{
    angle += speedSun;
    angle1 += speedPlanet;
    angle2 += speedMoon;

    glutPostRedisplay();
}

/* ===== منو ===== */

void menu(int id)
{
    switch (id)
    {
        /* سرعت */
    case 1: speedPlanet = 0.005; break;
    case 2: speedPlanet = 0.02;  break;
    case 3: speedMoon = 0.01; break;
    case 4: speedMoon = 0.08; break;
    case 5: speedSun = 0.005; break;
    case 6: speedSun = 0.05;  break;

        /* تغییر رنگ در رنج خودش */
    case 10: sunColor[0] = 1; sunColor[1] = 0.8; sunColor[2] = 0; break;  
    case 11: sunColor[0] = 1; sunColor[1] = 1;   sunColor[2] = 0.5; break; 

    case 20: earthColor[0] = 0; earthColor[1] = 0.5; earthColor[2] = 1; break; 
    case 21: earthColor[0] = 0; earthColor[1] = 0;   earthColor[2] = 0.6; break; 

    case 30: moonColor[0] = 0.4; moonColor[1] = 0.4; moonColor[2] = 0.4; break; 
    case 31: moonColor[0] = 0.8; moonColor[1] = 0.8; moonColor[2] = 0.8; break; 

    case 40: venusColor[0] = 1; venusColor[1] = 0.3; venusColor[2] = 0; break; 
    case 41: venusColor[0] = 1; venusColor[1] = 0.7; venusColor[2] = 0.3; break;

        /* دیفالت‌ها */
    case 90:
        sunColor[0] = 1; sunColor[1] = 1; sunColor[2] = 0;
        earthColor[0] = 0; earthColor[1] = 0; earthColor[2] = 1;
        moonColor[0] = 0.6; moonColor[1] = 0.6; moonColor[2] = 0.6;
        venusColor[0] = 1; venusColor[1] = 0.5; venusColor[2] = 0;
        break;

    case 91:
        speedSun = 0.02; speedPlanet = 0.01; speedMoon = 0.05;
        break;
    }
}

void createMenu()
{
    int planetMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Slow Planet", 1);
    glutAddMenuEntry("Fast Planet", 2);

    int moonMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Slow Moon", 3);
    glutAddMenuEntry("Fast Moon", 4);

    int sunMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Slow Sun", 5);
    glutAddMenuEntry("Fast Sun", 6);

    int sunColorMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Dark Yellow", 10);
    glutAddMenuEntry("Light Yellow", 11);

    int earthColorMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Light Blue", 20);
    glutAddMenuEntry("Dark Blue", 21);

    int moonColorMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Dark Gray", 30);
    glutAddMenuEntry("Light Gray", 31);

    int venusColorMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Dark Orange", 40);
    glutAddMenuEntry("Light Orange", 41);

    glutCreateMenu(menu);
    glutAddSubMenu("Planet Speed", planetMenu);
    glutAddSubMenu("Moon Speed", moonMenu);
    glutAddSubMenu("Sun Speed", sunMenu);
    glutAddSubMenu("Sun Color", sunColorMenu);
    glutAddSubMenu("Earth Color", earthColorMenu);
    glutAddSubMenu("Moon Color", moonColorMenu);
    glutAddSubMenu("Venus Color", venusColorMenu);
    glutAddMenuEntry("Default Colors", 90);
    glutAddMenuEntry("Default Speed", 91);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Solar System");

    init();
    createMenu();

    glutDisplayFunc(display);
    glutIdleFunc(test);  

    


    glutMainLoop();
    return 0;
}















