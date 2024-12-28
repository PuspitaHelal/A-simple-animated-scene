#include <GL/gl.h>

#include <GL/glut.h>

#include <math.h>

float boatX = 0.0f; // Global variable to track boat position
float cloudX1 = -40.0f; // Cloud 1 X-position
float cloudX2 = -60.0f; // Cloud 2 X-position
void drawCircle(float cx, float cy, float radius) {

    int num_segments = 100;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(cx, cy);

    for (int i = 0; i <= num_segments; i++) {

        float angle = 2.0f * M_PI * i / num_segments;

        float x = cx + radius * cos(angle);

        float y = cy + radius * sin(angle);

        glVertex2f(x, y);

    }

    glEnd();

}



void drawSun(float cx, float cy, float radius) {



      glColor3f(1.0, 0.9, 0.0);
    drawCircle(cx, cy, radius);

}
// Function to draw clouds with more highlighted black border
void drawCloud(float cx, float cy, bool isFirstCloud) {
    // Draw the black border (outline) with more emphasis
    glColor3f(0.0, 0.0, 0.0); // Black color
    drawCircle(cx, cy, 9.5); // Larger black outer circle
    drawCircle(cx + 7.5, cy, 8.2); // Right circle with black border
    drawCircle(cx - 7.5, cy, 8.2); // Left circle with black border
    drawCircle(cx + 3.5, cy + 4.0, 7.5); // Top-right circle with black border
    drawCircle(cx - 3.5, cy + 4.0, 7.5); // Top-left circle with black border

    // Draw the cloud (white inside)
    if (isFirstCloud) {
        glColor3f(1, 1, 1); // White for the first cloud
    } else {
        glColor3f(1, 1, 1); // White for the second cloud
    }

    // Draw overlapping cloud circles (slightly smaller radius)
    drawCircle(cx, cy, 8.0); // Center circle
    drawCircle(cx + 7.0, cy, 7.0); // Right circle
    drawCircle(cx - 7.0, cy, 7.0); // Left circle
    drawCircle(cx + 3.0, cy + 4.0, 6.0); // Top-right circle
    drawCircle(cx - 3.0, cy + 4.0, 6.0); // Top-left circle
}

// Cloud movement and overlap update
void update(int value) {
    boatX += 1.3f; // Increase speed by using a larger increment (e.g., 0.5)
    if (boatX > 160) { // Reset the boat position when it goes off-screen
        boatX = -160;
    }



    glutPostRedisplay(); // Request the display to be updated
    glutTimerFunc(30, update, 0); // Re-trigger the update function after 30 ms
}


void display(void) {

    glClear(GL_COLOR_BUFFER_BIT);



    // Draw sky and ground

    glColor3f(0.2,0.8,1);


    glBegin(GL_POLYGON);

        glVertex3f(-100.0, 33.3, 0.0);

        glVertex3f(100.0, 33.33, 0.0);

        glVertex3f(100.0, 100.0, 0.0);

        glVertex3f(-100.0, 100.0, 0.0);

    glEnd();



    glColor3f(0.1,0.5,1);
    glBegin(GL_POLYGON);

        glVertex3f(-100.0, -33.33, 0.0);

        glVertex3f(100.0, -33.33, 0.0);

        glVertex3f(100.0, 33.33, 0.0);

        glVertex3f(-100.0, 33.3, 0.0);

    glEnd();



    glColor3f(0, 0.9, 0.4);

    glBegin(GL_POLYGON);

        glVertex3f(-100.0, -100.0, 0.0);

        glVertex3f(100.0, -100.0, 0.0);

        glVertex3f(100.0, -33.3, 0.0);

        glVertex3f(-100.0, -33.33, 0.0);

    glEnd();



    // First Building

    glColor3f(1.0, 0.9, 0.8);

    glBegin(GL_POLYGON);

        glVertex3f(-15.0, 33.3, 0.0);

        glVertex3f(15.0, 33.33, 0.0);

        glVertex3f(15.0, 73.3, 0.0);

        glVertex3f(-15.0, 73.3, 0.0);

    glEnd();



    glColor3f(1, 0.7, 0.6);

    glBegin(GL_POLYGON);

        glVertex3f(15.0, 33.3, 0.0);

        glVertex3f(25.0, 33.33, 0.0);

        glVertex3f(25.0, 65.3, 0.0);

        glVertex3f(15.0, 73.3, 0.0);

    glEnd();



    // Windows for first building

    glColor3f(0.1, 0, 0.1);

    glBegin(GL_POLYGON);

        glVertex3f(5.0, 41.0, 0.0);

        glVertex3f(12.0, 41.0, 0.0);

        glVertex3f(12.0, 48.0, 0.0);

        glVertex3f(5.0, 48.0, 0.0);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex3f(5.0, 51.0, 0.0);

        glVertex3f(12.0, 51.0, 0.0);

        glVertex3f(12.0, 58.0, 0.0);

        glVertex3f(5.0, 58.0, 0.0);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex3f(5.0, 61.0, 0.0);

        glVertex3f(12.0, 61.0, 0.0);

        glVertex3f(12.0, 68.0, 0.0);

        glVertex3f(5.0, 68.0, 0.0);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex3f(-10.0, 41.0, 0.0);

        glVertex3f(-3.0, 41.0, 0.0);

        glVertex3f(-3.0, 48.0, 0.0);

        glVertex3f(-10.0, 48.0, 0.0);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex3f(-10.0, 51.0, 0.0);

        glVertex3f(-3.0, 51.0, 0.0);

        glVertex3f(-3.0, 58.0, 0.0);

        glVertex3f(-10.0, 58.0, 0.0);

    glEnd();

    glBegin(GL_POLYGON);

        glVertex3f(-10.0, 61.0, 0.0);

        glVertex3f(-3.0, 61.0, 0.0);

        glVertex3f(-3.0, 68.0, 0.0);

        glVertex3f(-10.0, 68.0, 0.0);

    glEnd();



    // Second Building

glColor3f(1.0, 0.9, 0.8);

glBegin(GL_POLYGON);

    glVertex3f(35.0, 33.3, 0.0);

    glVertex3f(65.0, 33.33, 0.0);

    glVertex3f(65.0, 73.3, 0.0);

    glVertex3f(35.0, 73.3, 0.0);

glEnd();



glColor3f(1, 0.7, 0.6);

glBegin(GL_POLYGON);

    glVertex3f(65.0, 33.3, 0.0);

    glVertex3f(75.0, 33.33, 0.0);

    glVertex3f(75.0, 65.3, 0.0);

    glVertex3f(65.0, 73.3, 0.0);

glEnd();



// Windows for second building

glColor3f(0.1, 0, 0.1);

glBegin(GL_POLYGON);

    glVertex3f(55.0, 41.0, 0.0);

    glVertex3f(62.0, 41.0, 0.0);

    glVertex3f(62.0, 48.0, 0.0);

    glVertex3f(55.0, 48.0, 0.0);

glEnd();

glBegin(GL_POLYGON);

    glVertex3f(55.0, 51.0, 0.0);

    glVertex3f(62.0, 51.0, 0.0);

    glVertex3f(62.0, 58.0, 0.0);

    glVertex3f(55.0, 58.0, 0.0);

glEnd();

glBegin(GL_POLYGON);

    glVertex3f(55.0, 61.0, 0.0);

    glVertex3f(62.0, 61.0, 0.0);

    glVertex3f(62.0, 68.0, 0.0);

    glVertex3f(55.0, 68.0, 0.0);

glEnd();

glBegin(GL_POLYGON);

    glVertex3f(40.0, 41.0, 0.0);

    glVertex3f(47.0, 41.0, 0.0);

    glVertex3f(47.0, 48.0, 0.0);

    glVertex3f(40.0, 48.0, 0.0);

glEnd();

glBegin(GL_POLYGON);

    glVertex3f(40.0, 51.0, 0.0);

    glVertex3f(47.0, 51.0, 0.0);

    glVertex3f(47.0, 58.0, 0.0);

    glVertex3f(40.0, 58.0, 0.0);

glEnd();

glBegin(GL_POLYGON);

    glVertex3f(40.0, 61.0, 0.0);

    glVertex3f(47.0, 61.0, 0.0);

    glVertex3f(47.0, 68.0, 0.0);

    glVertex3f(40.0, 68.0, 0.0);

glEnd();




// Boat
glPushMatrix();

// Apply scaling transformation to shrink the boat slightly
glScalef(0.8f, 0.8f, 1.0f); // Scale by 0.7 in the X and Y axes (slightly bigger than before)

glTranslatef(boatX, 0.0f, 0.0f); // Apply translation for boat animation
glColor3f(0.4, 0.2, 0); // Brown color for the hull
glBegin(GL_POLYGON);
    glVertex3f(-20.0, -15.0, 0.0); // Left edge
    glVertex3f(20.0, -15.0, 0.0);  // Right edge
    glVertex3f(40.0, 0.0, 0.0);   // Bottom-right curve
    glVertex3f(-40.0, 0.0, 0.0);  // Bottom-left curve
glEnd();

// Windshield
glColor3f(0.7, 0.7, 0.9); // Light blue for windshield
glBegin(GL_POLYGON);
    glVertex3f(-20.0, 0.0, 0.0);  // Left side
    glVertex3f(20.0, 0.0, 0.0);   // Right side
    glVertex3f(15.0, 10.0, 0.0);  // Top point
    glVertex3f(-15.0, 10.0, 0.0); // Top point
glEnd();

// Windows
glColor3f(0.0, 0.0, 0.0); // Black for the windows
glBegin(GL_POLYGON);
    glVertex3f(-15.0, 2.0, 0.1);
    glVertex3f(-9.0, 2.0, 0.1);
    glVertex3f(-9.0, 8.0, 0.1);
    glVertex3f(-15.0, 8.0, 0.1);
glEnd();
glBegin(GL_POLYGON);
    glVertex3f(-4.0, 2.0, 0.1);
    glVertex3f(4.0, 2.0, 0.1);
    glVertex3f(4.0, 8.0, 0.1);
    glVertex3f(-4.0, 8.0, 0.1);
glEnd();

// Third window
glBegin(GL_POLYGON);
    glVertex3f(9.0, 2.0, 0.1);
    glVertex3f(15.0, 2.0, 0.1);
    glVertex3f(15.0, 8.0, 0.1);
    glVertex3f(9.0, 8.0, 0.1);
glEnd();

glColor3f(0.8, 0.5, 0.7); // Light blue for windshield
glBegin(GL_POLYGON);
    glVertex3f(-10.0, 10.0, 0.0);  // Left side
    glVertex3f(10.0, 10.0, 0.0);  // Right side
    glVertex3f(10.0, 20.0, 0.0);  // Top point
    glVertex3f(-10.0, 20.0, 0.0);  // Top point
glEnd();

// Window color
glColor3f(0.0, 0.0, 0.0); // Black for the windows

// First window
glBegin(GL_POLYGON);
    glVertex3f(-8.0, 12.0, 0.1);
    glVertex3f(-2.0, 12.0, 0.1);
    glVertex3f(-2.0, 18.0, 0.1);
    glVertex3f(-8.0, 18.0, 0.1);
glEnd();

// Second window
glBegin(GL_POLYGON);
    glVertex3f(2.0, 12.0, 0.1);
    glVertex3f(8.0, 12.0, 0.1);
    glVertex3f(8.0, 18.0, 0.1);
    glVertex3f(2.0, 18.0, 0.1);
glEnd();

// Mast for the flag on the boat's left corner
glColor3f(0.4, 0.2, 0); // Brown color for mast
glBegin(GL_POLYGON);
    glVertex3f(-30.0, 0.0, 0.0);  // Left edge
    glVertex3f(-28.0, 0.0, 0.0);  // Right edge
    glVertex3f(-28.0, 20.0, 0.0); // Right edge (top of the mast)
    glVertex3f(-30.0, 20.0, 0.0); // Left edge (top of the mast)
glEnd();

// Flag on the boat
glColor3f(0.7,0.3,0.7); // Red color for the flag
glBegin(GL_TRIANGLES);
    glVertex3f(-30.0, 20.0, 0.0);  // Top of the mast
    glVertex3f(-20.0, 15.0, 0.0);  // Bottom-right point of the flag
    glVertex3f(-30.0, 10.0, 0.0);  // Bottom-left point of the flag
glEnd();

glPopMatrix();

// Draw the sun
    drawSun(-80.0, 80.0, 14.0);

    drawCloud(cloudX1, 80.0, true);  // First cloud (white)
    drawCloud(cloudX2,75.0, false); // Second cloud (light gray)
    glFlush();

}



void init(void) {

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);

}



int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);

    glutInitWindowPosition(0, 0);

    glutCreateWindow("My First Project");

    init();

    glutDisplayFunc(display);
      glutTimerFunc(30, update, 0); // Start the boat animation

    glutMainLoop();

    return 0;

}
