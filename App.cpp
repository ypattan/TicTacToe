#include "App.h"
#include <math.h>
using namespace std;

float info[9][3];
int player_num = 0;
//info[x][0] = x-coordinates
//info[x][1] = y-coordinates
//info[x][2] = player1 (1.0) or player2 (2.0)
int scoring[9];

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables
    mx = 0.0;
    my = 0.0;
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
    
    //draw tic-tac-toe grid
    glColor3d(1.0, 1.0, 0.0);
    
    glBegin(GL_LINES);
    
    //left vertical line of grid
    glVertex2f(-.25, 0.75);
    glVertex2f(-0.25, -0.75);
    
    //right vertical line of grid
    glVertex2f(0.25, 0.75);
    glVertex2f(0.25 , -0.75);
    
    //top horizontal line of grid
    glVertex2f(-0.75, 0.25);
    glVertex2f(0.75, 0.25);
    
    //bottom horizontal line of grid
    glVertex2f(-0.75, -0.25);
    glVertex2f(0.75, -0.25);
    
    glEnd();
    
    for(int i = 0; i < player_num; i++){
        if(info[i][2] == 1.0){
            //draw "x"
            glBegin(GL_LINES);
            glColor3d(0.0, 1.0, 1.0);
            glVertex2f(info[i][0] + 0.1,info[i][1] + 0.1);
            glVertex2f(info[i][0] - 0.1, info[i][1] - 0.1);
            glVertex2f(info[i][0] - 0.1, info[i][1] + 0.1);
            glVertex2f(info[i][0] + 0.1, info[i][1] - 0.1);
            glEnd();
        }
        if (info[i][2] == 2.0){
            //draw "o"
            glBegin(GL_LINES);
            glColor3d(1.0, 0.0, 1.0);
            //make a loop that calculates pt1 then pt2, where pt2 is pt1 for next interation of the loop
            float theta = 0.0;
            for(int k  = 0; k < 20; k++){
                glVertex2f(info[i][0] + (0.1* cos(18 * k)), info[i][1] + (0.1* sin(18 * k )));
                glVertex2f(info[i][0] + (0.1* cos(18 * (k + 1))), info[i][1] + (0.1* sin(18 * (k + 1))));
            }
            glEnd();
        }
    }
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void assignCoord(float m, float n){
    float b;
    if ((player_num % 2) == 0){
        b = 1.0;
    }
    if ((player_num % 2) == 1){
        b = 2.0;
    }
    if((n<0.75) && (n>0.25)){
        if((m > (-0.75)) && (m < (-0.25))){
            info[player_num][0] = -0.5;
            info[player_num][1] = 0.5;
            info[player_num][2] = b;
            scoring[0] = info[player_num][2];
        }else if ((m > (-0.25)) && (m < (0.25))){
            info[player_num][0] = 0.0;
            info[player_num][1] = 0.5;
            info[player_num][2] = b;
            scoring[1] = info[player_num][2];
        }else if ((m > (0.25)) && (m < (0.75))){
            info[player_num][0] = 0.5;
            info[player_num][1] = 0.5;
            info[player_num][2] = b;
            scoring[2] = info[player_num][2];
        }
    }else if ((n < 0.25) && (n > (-0.25))){
        if((m > (-0.75)) && (m < (-0.25))){
            info[player_num][0] = -0.5;
            info[player_num][1] = 0.0;
            info[player_num][2] = b;
            scoring[3] = info[player_num][2];
        }else if ((m > (-0.25)) && (m < (0.25))){
            info[player_num][0] = 0.0;
            info[player_num][1] = 0.0;
            info[player_num][2] = b;
            scoring[4] = info[player_num][2];
        }else if ((m > (0.25)) && (m < (0.75))){
            info[player_num][0] = 0.5;
            info[player_num][1] = 0.0;
            info[player_num][2] = b;
            scoring[5] = info[player_num][2];
        }
    }else if ((n < (-0.25)) && (n > (-0.75))){
        if((m > (-0.75)) && (m < (-0.25))){
            info[player_num][0] = -0.5;
            info[player_num][1] = -0.5;
            info[player_num][2] = b;
            scoring[6] = info[player_num][2];
        }else if ((m > (-0.25)) && (m < (0.25))){
            info[player_num][0] = 0.0;
            info[player_num][1] = -0.5;
            info[player_num][2] = b;
            scoring[7] = info[player_num][2];
        }else if ((m > (0.25)) && (m < (0.75))){
            info[player_num][0] = 0.5;
            info[player_num][1] = -0.5;
            info[player_num][2] = b;
            scoring[8] = info[player_num][2];
        }
    }
}

//  _0_|_1_|_2_
//  _3_|_4_|_5_
//  _6_|_7_|_8_
int score(){
    int g = 0;
    if(scoring[0] == 1 && scoring[1] == 1 && scoring[2] == 1){
        g = 1;
    }else if(scoring[0] == 1 && scoring[3] == 1 && scoring[6] == 1){
        g = 1;
    }else if(scoring[0] == 1 && scoring[4] == 1 && scoring[8] == 1){
        g = 1;
    }else if(scoring[3] == 1 && scoring[4] == 1 && scoring[5] == 1){
        g = 1;
    }else if(scoring[6] == 1 && scoring[7] == 1 && scoring[8] == 1){
        g = 1;
    }else if(scoring[2] == 1 && scoring[4] == 1 && scoring[6] == 1){
        g = 1;
    }else if(scoring[2] == 1 && scoring[5] == 1 && scoring[8] == 1){
        g = 1;
    }else if(scoring[1] == 1 && scoring[4] == 1 && scoring[7] == 1){
        g = 1;
    }else if(scoring[0] == 2 && scoring[3] == 2 && scoring[6] == 2){
        g = 2;
    }else if(scoring[0] == 2 && scoring[4] == 2 && scoring[8] == 2){
        g = 2;
    }else if(scoring[3] == 2 && scoring[4] == 2 && scoring[5] == 2){
        g = 2;
    }else if(scoring[6] == 2 && scoring[7] == 2 && scoring[8] == 2){
        g = 2;
    }else if(scoring[2] == 2 && scoring[4] == 2 && scoring[6] == 2){
        g = 2;
    }else if(scoring[2] == 2 && scoring[5] == 2 && scoring[8] == 2){
        g = 2;
    }else if(scoring[1] == 2 && scoring[4] == 2 && scoring[7] == 2){
        g = 2;
    }else if(scoring[0] == 2 && scoring[1] == 2 && scoring[2] == 2){
        g = 2;
    }
    return g;
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    //check to make sure click was inside the grid
    if( (mx > -0.75) && (mx < 0.75) && (my > -0.75) && (my < 0.75)){
        if(score() != 0){
            cout << "Player " << score() << " won!" << endl;
            player_num = 0;
            for ( int j = 0; j < 9; j++){
                scoring[j] = 0;
                info[j][0] = 0;
                info[j][1] = 0;
                info[j][2] = 0;
            }
            redraw();
        }else{
            //redraw polygon
            assignCoord(mx,my);
            redraw();
            player_num++;
        }
    }
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    //redraw polygon
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 'a'){
        if (scoring[0] == 0){
            mouseDown(-0.5, 0.5);
        }else if(scoring[1] == 0){
            mouseDown(0.0, 0.5);
        }else if(scoring[2] == 0){
            mouseDown(0.5, 0.5);
        }else if(scoring[3] == 0){
            mouseDown(-0.5, 0.0);
        }else if(scoring[4] == 0){
            mouseDown(0.0, 0.0);
        }else if(scoring[5] == 0){
            mouseDown(0.5, 0.0);
        }else if(scoring[6] == 0){
            mouseDown(-0.5, -0.5);
        }else if(scoring[7] == 0){
            mouseDown(0.0, -0.5);
        }else if(scoring[8] == 0){
            mouseDown(0.5, -0.5);
        }
    }
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}
