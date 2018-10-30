#include "definitions.h"
#include "tests.h"

/************************************************************
 * UPDATE_SCREEN:
 * Blits pixels from RAM to VRAM for rendering
 ***********************************************************/
void SendFrame(SDL_Texture* GPU_OUTPUT, SDL_Renderer * ren, SDL_Surface* frameBuf) 
{
    SDL_UpdateTexture(GPU_OUTPUT, NULL, frameBuf->pixels, frameBuf->pitch);
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, GPU_OUTPUT, NULL, NULL);
    SDL_RenderPresent(ren);
}

/*************************************************************
 * POLL_CONTROLS:
 * Updates the state of the application based on:
 * keyboard, mouse, touch screen, gamepad inputs 
 ************************************************************/
void PollUserInputs(bool & playing)
{
    SDL_Event e;
    while(SDL_PollEvent(&e)) 
    {
        if(e.type == SDL_QUIT) 
        {
            playing = false;
        }
        if(e.key.keysym.sym == 'q' && e.type == SDL_KEYDOWN) 
        {
            playing = false;
        }
    }
}

/****************************************
 * Renders a triangle/convex polygon
 * to the screen with the appropriate 
 * fill pattern
 ***************************************/
void DrawClippedTriangle(POINTER_2D(framePtr), Vertex* triangle, Attributes* attrs, int count)
{
    // Error check
    if(count < 3) return;
	
	// Your code goes here
}

/****************************************
 * Renders a line to the screen with the
 * appropriate coloring
 ***************************************/
void DrawLine(POINTER_2D(framePtr), Vertex* line, Attributes* attrs, int count)
{
    // Error check
    if(count != 2) return;
	
	// Your code goes here
}

/****************************************
 * Renders a point to the screen with the
 * appropriate coloring
 ***************************************/
void DrawPoint(POINTER_2D(framePtr), Vertex* v, Attributes* attrs, int count)
{
    if(count == 0) return;

    // Your code goes here
}


/*************************************************************
 * TRANSFORM_VERTICES:
 * Where rotations, translations, scaling operations
 * transform the input vertices. NOTE: This does not 
 * include the camera view transform.
 ************************************************************/
void TransformVertices( Vertex inputVerts[], Attributes inputAttrs[], int numInput, 
                        Vertex transVerts[], Attributes transAttrs[], int & numTrans, 
                        Transform* trans)
{
    // Dummy code - your code will replace this
    for(numTrans = 0; numTrans < numInput; numTrans++)
    {
        transVerts[numTrans] = inputVerts[numTrans];
        transAttrs[numTrans] = inputAttrs[numTrans];
    }
}

/*************************************************************
 * CLIP_VERTICES:
 * Depending on our view type - clip to the frustrum that 
 * maps to our screen's aspect ratio.  
 ************************************************************/
void ClipVertices(Vertex transVerts[], Attributes transAttrs[], int numTrans, 
                  Vertex clippedVerts[], Attributes clippedAttrs[], int & numClipped, 
                  VIEW_MATRICES view)
{
    // Dummy code - your code will replace this
    for(numClipped = 0; numClipped < numTrans; numClipped++)
    {
        clippedVerts[numClipped] = transVerts[numClipped];
        clippedAttrs[numClipped] = transAttrs[numClipped];
    }
}

/*************************************************************
 * VIEW_TRANSFORM_VERTICES:
 * Converts our clipped geometry to screen space. 
 * This usually means using PERSPECTIVE or ORTHOGRAPHIC 
 * views.
 ************************************************************/
void ViewTransformVertices( Vertex clippedVerts[], Attributes clippedAttrs[], int numClipped, 
                            Vertex viewVerts[], Attributes viewAttrs[], int & numView, 
                            VIEW_MATRICES view)
{
    // Dummy code - your code will replace this
    for(numView = 0; numView < numClipped; numView++)
    {
        viewVerts[numView] = clippedVerts[numView];
        viewAttrs[numView] = clippedAttrs[numView];
    }
}

/***************************************************************************
 * Processes the indiecated PRIMITIVES type through stages of:
 *  1) Transformation
 *  2) Clipping
 *  3) Perspective or Orthographic projection
 *  4) Vertex Interpolation
 *  5) Fragment Shading
 **************************************************************************/
void DrawPrimitive(PRIMITIVES type, 
                    Vertex inputVerts[], 
                    Attributes inputAttrs[],
                    int numIn, 
                    POINTER_2D(framePtr), 
                    Transform * transFormMatrix, // Default parameter available
                    VIEW_MATRICES view_m)        // Default parameter available
{
    // Matrix Transformations
    Vertex transVerts[MAX_VERTICES];
    Attributes transAttrs[MAX_VERTICES];
    int numTrans;    
    TransformVertices(inputVerts, inputAttrs, numIn, transVerts, transAttrs, numTrans, transFormMatrix); 

    // Clip to our frustrum
    Vertex clippedVerts[MAX_VERTICES];
    Attributes clippedAttrs[MAX_VERTICES];
    int numClipped; 
    ClipVertices(transVerts, transAttrs, numTrans, clippedVerts, clippedAttrs, numClipped, view_m);

    // View space transform
    Vertex viewVerts[MAX_VERTICES];
    Attributes viewAttrs[MAX_VERTICES];
    int numView;
    ViewTransformVertices(clippedVerts, clippedAttrs, numClipped, viewVerts, viewAttrs, numView, view_m);

    // Vertex Interpolation & Fragment Drawing
    switch(type)
    {
        case POINT:
            DrawPoint(framePtr, viewVerts, viewAttrs, numView);
            break;
        case LINE:
            DrawLine(framePtr, viewVerts, viewAttrs, numView);
            break;
        case TRIANGLE:
            DrawClippedTriangle(framePtr, viewVerts, viewAttrs, numView);
            break;
    }
}

/***********************************************
 * Sets the screen to the indicated color value.
 **********************************************/
void ClearScreen(POINTER_2D(framePtr), COLOR color = 0xff000000)
{
    for(int y = 0; y < S_HEIGHT; y++)
    {
        for(int x = 0; x < S_WIDTH; x++)
        {
            framePtr[y][x] = color;
        }
    }
}

/*************************************************************
 * MAIN:
 * Main game loop, initialization, memory management
 ************************************************************/
int main()
{
    // -----------------------DATA TYPES----------------------
    SDL_Window* WIN;                // Our Window
    SDL_Renderer* REN;              // Interfaces CPU with GPU
    SDL_Texture * GPU_OUTPUT;       // GPU buffer image (GPU Memory)
    SDL_Surface* FRAME_BUF;         // CPU buffer image (Main Memory) 
    POINTER_2D(framePtr);           // Assists with setting pixels in FRAME_BUF

    // ------------------------INITIALIZATION-------------------
    SDL_Init(SDL_INIT_EVERYTHING);
    WIN = SDL_CreateWindow(GAME_NAME, 200, 200, S_WIDTH, S_HEIGHT, 0);
    REN = SDL_CreateRenderer(WIN, -1, SDL_RENDERER_SOFTWARE);
    FRAME_BUF = SDL_CreateRGBSurface(0, S_WIDTH, S_HEIGHT, 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);
    FRAME_BUF = SDL_ConvertSurface(SDL_GetWindowSurface(WIN), SDL_GetWindowSurface(WIN)->format, 0);
    GPU_OUTPUT = SDL_CreateTextureFromSurface(REN, FRAME_BUF);
    framePtr = SETUP_POINTER_2D(FRAME_BUF);

    // Draw loop 
    bool running = true;
    while(running) 
    {           
        // Poll for user inputs
        PollUserInputs(running);

        // Refresh Screen
        ClearScreen(framePtr);

		// Call DrawPrimitive here or access framePtr directly
		// Your code goes here
		
        // Ensure framerate at 60fps, push to screen
        SDL_Delay(17);	  
        SendFrame(GPU_OUTPUT, REN, FRAME_BUF);
    }

    // Cleanup
    SDL_FreeSurface(FRAME_BUF);
    SDL_DestroyTexture(GPU_OUTPUT);
    SDL_DestroyRenderer(REN);
    SDL_DestroyWindow(WIN);
    SDL_Quit();
    return 0;
}
