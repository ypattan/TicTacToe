#include "App.h"

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
}
bool rect1(float x, float y){
    if( x >= -0.2 && x <= 0.0){
        if( y >= -0.0 && y <= 0.4){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

bool rect2(float x, float y){
    if( x >= 0.1 && x <= 0.5){
        if( y >= -0.1 && y <= 0.1){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}


void App::draw() {

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    // Set up the transformations stack
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    // Set Color
    glColor3d(1.0, 1.0, 1.0);
    
    // Draw some points
    glBegin(GL_POINTS);
    
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);  
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    
    glEnd();
    
    //draw two polygons
    //rect2
    glBegin(GL_POLYGON);
    glColor3d(1.0, 1.0, 1.0);
    if (rect2(mx,my) == true){
        glColor3d(1.0, 0.0, 0.0);
    }
    glVertex2f(0.1, -0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.5, 0.1);
    glVertex2f(0.5, -0.1);
    
    glEnd();
    
    //rect1
    glBegin(GL_POLYGON);
    glColor3d(1.0, 1.0, 1.0);
    if (rect1(mx,my) == true){
        glColor3d(1.0, 0.0, 0.0);
    }
    glVertex2f(-0.2,0.0);
    glVertex2f(-0.2, 0.4);
    glVertex2f(0.0, 0.4);
    glVertex2f(0.0, 0.0);
    glEnd();
    
    
    // Draw a yellow cross
    glColor3d(1.0, 1.0, 0.0);
    
    glBegin(GL_LINES);
    
    glVertex2f(mx - 0.05f, my);
    glVertex2f(mx + 0.05f, my);
    
    glVertex2f(mx, my - 0.05f);
    glVertex2f(mx, my + 0.05f);
    glEnd();
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}


void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    //redraw polygon
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    //redraw polygon
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}
