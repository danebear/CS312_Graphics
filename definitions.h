#define SDL_MAIN_HANDLED
#include "SDL2/sdl.h"

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

/******************************************************
 * DEFINES:
 *  -Macros for universal variables/hook-ups
 *****************************************************/
#define GAME_NAME   "Pipeline"
#define S_WIDTH     512
#define S_HEIGHT    512
#define POINTER_2D(name)        Uint32 (*name)[S_WIDTH]
#define SETUP_POINTER_2D(name)  (Uint32 (*)[S_WIDTH])name->pixels
#define COLOR                   Uint32    
#define MAX_VERTICES 6
#define ABS(in) (in > 0 ? (in) : -(in))
#define SWAP(TYPE, FIRST, SECOND) { TYPE tmp = FIRST; FIRST = SECOND; SECOND = tmp; }

/******************************************************
 * Types of primitives our pipeline will render.
 *****************************************************/
enum PRIMITIVES 
{
    TRIANGLE,
    LINE,
    POINT
};

/*****************************************************
 * Types of view matrices for clipping, transforms.
 ****************************************************/
enum VIEW_MATRICES
{
    PERSPECTIVE,
    ORTHOGRAPHIC
};

/****************************************************
 * Describes a geometric point. 
 ****************************************************/
struct Vertex
{
    int x;
    int y;
};

/*******************************************************
 * Describes vertex-specific values for primitives.
 ******************************************************/
struct Attributes
{
    COLOR color;
};

/******************************************************
 * Your Description goes here.
 *****************************************************/
struct Transform
{
    // Your code goes here
};

#endif