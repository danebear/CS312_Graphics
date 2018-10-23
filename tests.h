#include "definitions.h"

#ifndef TESTS_H
#define TESTS_H

void DrawPrimitive(PRIMITIVES type, 
                    Vertex inputVerts[], 
                    Attributes inputAttrs[],
                    int numIn, 
                    POINTER_2D(framePtr), 
                    Transform * transFormMatrix = NULL, 
                    VIEW_MATRICES view_m = PERSPECTIVE);


/********************************************
 * Demonstrate Line Drawing for Project 01. 
 *******************************************/
void DrawLineTest(POINTER_2D(framePtr))
{
        Vertex vv[2];
        Attributes aa[2];
        aa[0].color = 0xffff0000;
        aa[1].color = 0xffff0000;
        vv[0].x = 300;
        vv[0].y = 300;
        vv[1].x = 500;
        vv[1].y = 350;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

        vv[1].x = 350;
        vv[1].y = 500;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

        vv[1].x = 250;
        vv[1].y = 100;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

        vv[1].x = 100;
        vv[1].y = 250;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

        vv[1].x = 500;
        vv[1].y = 250;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

        vv[1].x = 100;
        vv[1].y = 250;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

        vv[1].x = 250;
        vv[1].y = 500;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

        vv[1].x = 350;
        vv[1].y = 100;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

        vv[1].x = 100;
        vv[1].y = 350;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

        // Diagonals
        vv[0].x = 500;
        vv[0].y = 100;
        vv[1].x = 100;
        vv[1].y = 500;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

        vv[0].x = 100;
        vv[0].y = 100;
        vv[1].x = 500;
        vv[1].y = 500;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

        // Straights
        vv[0].x = 100;
        vv[0].y = 300;
        vv[1].x = 500;
        vv[1].y = 300;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

        vv[0].x = 300;
        vv[0].y = 100;
        vv[1].x = 300;
        vv[1].y = 500;
        DrawPrimitive(LINE, vv, aa, 2, framePtr);

}

/***********************************************
 * Demonstrate Triangle Drawing for Project 02. 
 **********************************************/
void DrawTriangleTest(POINTER_2D(framePtr))
{
        Vertex v[3];
        Attributes a[3];
        v[0].x = 50;
        v[0].y = 60;
        v[1].x = 100;
        v[1].y = 150;
        v[2].x = 150;
        v[2].y = 60;
        a[0].color = 0xffff0000;
        a[1].color = 0xffff0000;
        a[2].color = 0xffff0000;
        DrawPrimitive(TRIANGLE, v, a, 3, framePtr);

        v[0].x = 250;
        v[0].y = 60;
        v[1].x = 250;
        v[1].y = 150;
        v[2].x = 300;
        v[2].y = 110;
        a[0].color = 0xff00ff00;
        a[1].color = 0xff00ff00;
        a[2].color = 0xff00ff00;
        DrawPrimitive(TRIANGLE, v, a, 3, framePtr);

        v[0].x = 350;
        v[0].y = 110;
        v[1].x = 450;
        v[1].y = 60;
        v[2].x = 450;
        v[2].y = 150;
        a[0].color = 0xff0000ff;
        a[1].color = 0xff0000ff;
        a[2].color = 0xff0000ff;
        DrawPrimitive(TRIANGLE, v, a, 3, framePtr);
        
        v[0].x = 110;
        v[0].y = 250;
        v[1].x = 60;
        v[1].y = 350;
        v[2].x = 150;
        v[2].y = 350;
        a[0].color = 0xffff0000;
        a[1].color = 0xffff0000;
        a[2].color = 0xffff0000;
        DrawPrimitive(TRIANGLE, v, a, 3, framePtr);

        v[0].x = 210;
        v[0].y = 260;
        v[1].x = 260;
        v[1].y = 340;
        v[2].x = 310;
        v[2].y = 310;
        a[0].color = 0xff00ff00;
        a[1].color = 0xff00ff00;
        a[2].color = 0xff00ff00;
        DrawPrimitive(TRIANGLE, v, a, 3, framePtr);

        v[0].x = 370;
        v[0].y = 310;
        v[1].x = 430;
        v[1].y = 350;
        v[2].x = 470;
        v[2].y = 260;
        a[0].color = 0xff0000ff;
        a[1].color = 0xff0000ff;
        a[2].color = 0xff0000ff;
        DrawPrimitive(TRIANGLE, v, a, 3, framePtr);
}

/*****************************************
 * Demonstrate color interpolation for
 * project 05.
 ****************************************/
void InterpolationTest(POINTER_2D(framePtr))
{
        Vertex v[3];
        Attributes a[3];
        v[0].x = 50;
        v[0].y = 60;
        v[1].x = 450;
        v[1].y = 60;
        v[2].x = 250;
        v[2].y = 400;
        a[0].color = 0xffff0000;
        a[1].color = 0xff00ff00;
        a[2].color = 0xff0000ff;
        DrawPrimitive(TRIANGLE, v, a, 3, framePtr);

        v[0].x = 50;
        v[0].y = 450;
        v[1].x = 450;
        v[1].y = 450;
        a[0].color = 0xffff0000;
        a[1].color = 0xff0000ff;
        DrawPrimitive(LINE, v, a, 2, framePtr);
}


#endif