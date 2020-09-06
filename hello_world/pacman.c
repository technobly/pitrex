#include <pitrex/pitrexio-gpio.h>
#include <vectrex/vectrexInterface.h>
extern int optimizationON;
// start of a port of https://mitxela.com/projects/console/pacman

// Polygon List
unsigned char maze[] = { 24, // segments

    34, // points in a line
       224,104, 185,104, 184,103, 184,80, 185,79, 220,79, 221,78, 222,78, 223,77,
       223,76, 224,75, 224,4, 223,3, 223,2, 222,1, 221,1, 220,0, 5,0, 4,1, 3,1,
       2,2, 2,3, 1,4, 1,75, 2,76, 2,77, 3,78, 4,78, 5,79, 40,79, 41,80, 41,103,
       40,104, 1,104, // actual points

    34,
       1,127, 40,127, 41,128, 41,151, 40,152, 5,152, 4,153, 3,153, 2,154, 2,155,
       1,156, 1,243, 2,244, 2,245, 3,246, 4,246, 5,247, 220,247, 221,246, 222,246,
       223,245, 223,244, 224,243, 224,156, 223,155, 223,154, 222,153, 221,153,
       220,152, 185,152, 184,151, 184,128, 185,127, 224,127,

    26,
       224,107, 183,107, 181,105, 181,78, 183,76, 219,76, 221,74, 221,5, 219,3,
       118,3, 116,5, 116,33, 114,35, 111,35, 109,33, 109,5, 107,3, 6,3, 4,5, 4,74,
       6,76, 42,76, 44,78, 44,105, 42,107, 1,107,

    34,
       1,124, 42,124, 44,126, 44,153, 42,155, 6,155, 4,157, 4,194, 6,196, 18,196,
       20,198, 20,201, 18,203, 6,203, 4,205, 4,242, 6,244, 219,244, 221,242, 221,205,
       219,203, 207,203, 205,201, 205,198, 207,196, 219,196, 221,194, 221,157,
       219,155, 183,155, 181,153, 181,126, 183,124, 224,124,

    9,
       164,126, 164,153, 162,155, 159,155, 157,153, 157,126, 159,124, 162,124, 164,126,

    17,
       164,54, 164,105, 162,107, 159,107, 157,105, 157,85, 155,83, 135,83, 133,81,
       133,78, 135,76, 155,76, 157,74, 157,54, 159,52, 162,52, 164,54,

    9,
       181,57, 183,59, 202,59, 204,57, 204,54, 202,52, 183,52, 181,54, 181,57,

    9,
       181,33, 183,35, 202,35, 204,33, 204,22, 202,20, 183,20, 181,22, 181,33,

    9,
       135,35, 162,35, 164,33, 164,22, 162,20, 135,20, 133,22, 133,33, 135,35,

    17,
       87,52, 138,52, 140,54, 140,57, 138,59, 118,59, 116,61, 116,81, 114,83, 111,83,
       109,81, 109,61, 107,59, 87,59, 85,57, 85,54, 87,52,

    9,
       63,35, 90,35, 92,33, 92,22, 90,20, 63,20, 61,22, 61,33, 63,35,

    9,
       42,35, 23,35, 21,33, 21,22, 23,20, 42,20, 44,22, 44,33, 42,35,

    9,
       42,52, 23,52, 21,54, 21,57, 23,59, 42,59, 44,57, 44,54, 42,52,

    17,
       70,76, 68,74, 68,54, 66,52, 63,52, 61,54, 61,105, 63,107, 66,107, 68,105,
       68,85, 70,83, 90,83, 92,81, 92,78, 90,76, 70,76,

    17,
       85,100, 104,100, 105,101, 120,101, 121,103, 137,103, 137,128, 88,128, 88,103,
       104,103, 104,102, 120,102, 121,100, 140,100, 140,131, 85,131, 85,100,

    9,
       68,126, 66,124, 63,124, 61,126, 61,153, 63,155, 66,155, 68,153, 68,126,

    9,
       63,172, 90,172, 92,174, 92,177, 90,179, 63,179, 61,177, 61,174, 63,172,

    13,
       44,174, 42,172, 23,172, 21,174, 21,177, 23,179, 35,179, 37,181, 37,201, 39,203,
       42,203, 44,201, 44,174,

    17,
       61,198, 61,218, 59,220, 23,220, 21,222, 21,225, 23,227, 90,227, 92,225, 92,222,
       90,220, 70,220, 68,218, 68,198, 66,196, 63,196, 61,198,

    17,
       87,196, 85,198, 85,201, 87,203, 107,203, 109,205, 109,225, 111,227, 114,227,
       116,225, 116,205, 118,203, 138,203, 140,201, 140,198, 138,196, 87,196,

    17,
       116,177, 116,157, 118,155, 138,155, 140,153, 140,150, 138,148, 87,148, 85,150,
       85,153, 87,155, 107,155, 109,157, 109,177, 111,179, 114,179, 116,177,

    9,
       135,179, 133,177, 133,174, 135,172, 162,172, 164,174, 164,177, 162,179, 135,179,

    17,
       157,198, 157,218, 155,220, 135,220, 133,222, 133,225, 135,227, 202,227, 204,225,
       204,222, 202,220, 166,220, 164,218, 164,198, 162,196, 159,196, 157,198,

    13,
       181,174, 181,201, 183,203, 186,203, 188,201, 188,181, 190,179, 202,179, 204,177,
       204,174, 202,172, 183,172, 181,174
};

// 16x16 sprite lists

unsigned char PacSprites[] = { 0,248, 3,248, 7,240, 7,224, 15,192, 15,128, 15,0, 15,128, 15,192, 7,224, 7,240, 3,248, 0,248, 0,0, 0,0, 0,0, 0,248, 3,254, 7,255, 7,255, 15,252, 15,224, 15,0, 15,224, 15,252, 7,255, 7,255, 3,254, 0,248, 0,0, 0,0, 0,0, 1,240, 7,252, 15,254, 15,254, 31,255, 31,255, 31,255, 31,255, 31,255, 15,254, 15,254, 7,252, 1,240, 0,0, 0,0, 0,0, 1,240, 1,252, 0,254, 0,126, 0,63, 0,31, 0,15, 0,31, 0,63, 0,126, 0,254, 1,252, 1,240, 0,0, 0,0, 0,0, 1,240, 7,252, 15,254, 15,254, 3,255, 0,127, 0,15, 0,127, 3,255, 15,254, 15,254, 7,252, 1,240, 0,0, 0,0, 0,0, 1,240, 7,252, 15,254, 15,254, 31,255, 31,255, 31,255, 31,255, 31,255, 15,254, 15,254, 7,252, 1,240, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 24,3, 28,7, 30,15, 31,31, 31,191, 15,254, 15,254, 7,252, 1,240, 0,0, 0,0, 0,0, 0,0, 6,12, 14,14, 15,30, 31,31, 31,31, 31,191, 31,191, 31,191, 15,254, 15,254, 7,252, 1,240, 0,0, 0,0, 0,0, 1,240, 7,252, 15,254, 15,254, 31,255, 31,255, 31,255, 31,255, 31,255, 15,254, 15,254, 7,252, 1,240, 0,0, 0,0, 0,0, 1,240, 7,252, 15,254, 15,254, 31,191, 31,31, 30,15, 28,7, 24,3, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 1,240, 7,252, 15,254, 15,254, 31,191, 31,191, 31,191, 31,31, 31,31, 15,30, 14,14, 6,12, 0,0, 0,0, 0,0, 0,0, 1,240, 7,252, 15,254, 15,254, 31,255, 31,255, 31,255, 31,255, 31,255, 15,254, 15,254, 7,252, 1,240, 0,0, 0,0, 0,0 };

unsigned char PacDeathAnimation[] = {
0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 2,32, 1,72, 8,16, 4,0, 0,12, 24,0, 0,16, 4,8, 9,64, 2,32, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,128, 0,128, 0,128, 0,128, 0,128, 0,128, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,128, 0,128, 1,192, 1,192, 1,192, 3,224, 1,64, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,128, 1,192, 3,224, 3,224, 7,240, 15,248, 7,112, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,128, 1,192, 7,240, 15,248, 63,254, 63,126, 30,60, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, \
1,192, 7,240, 63,254, 127,255, 63,126, 14,56, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 7,240, 127,255, 127,255, 63,254, 15,120, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 120,15, 127,255, 127,255, 63,254, 15,120, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 112,7, 126,63, 127,255, 63,254, 31,252, 7,112, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 32,2, 120,15, 124,31, 127,127, 63,254, 63,254, 31,252, 7,112, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 48,6, 56,14, 60,30, 62,62, 63,126, 31,252, 31,252, 15,248, 3,224, 0,0, 0,0, 0,0, 0,0, 0,0, 3,224, 15,248, 31,252, 31,252, 63,254, 63,254, 63,254, 63,254, 63,254, 31,252, 31,252, 15,248, 3,224, 0,0, 0,0, 0,0 };

unsigned char GhostSprites[] = {
1,224, 7,248, 15,252, 28,242, 24,96, 25,230, 57,231, 60,243, 63,255, 63,255, 63,255, 63,255, 55,59, 35,49, 0,0, 0,0, 1,224, 7,248, 15,252, 28,242, 24,96, 25,230, 57,231, 60,243, 63,255, 63,255, 63,255, 63,255, 61,239, 24,198, 0,0, 0,0, 1,224, 7,248, 15,252, 19,206, 1,134, 25,230, 57,231, 51,207, 63,255, 63,255, 63,255, 63,255, 55,59, 35,49, 0,0, 0,0, 1,224, 7,248, 15,252, 19,206, 1,134, 25,230, 57,231, 51,207, 63,255, 63,255, 63,255, 63,255, 61,239, 24,198, 0,0, 0,0, 1,224, 7,248, 6,216, 16,194, 16,194, 25,230, 63,255, 63,255, 63,255, 63,255, 63,255, 63,255, 55,59, 35,49, 0,0, 0,0, 1,224, 7,248, 6,216, 16,194, 16,194, 25,230, 63,255, 63,255, 63,255, 63,255, 63,255, 63,255, 61,239, 24,198, 0,0, 0,0, 1,224, 7,248, 15,252, 31,254, 25,230, 16,194, 48,195, 50,203, 57,231, 63,255, 63,255, 63,255, 55,59, 35,49, 0,0, 0,0, 1,224, 7,248, 15,252, 31,254, 25,230, 16,194, 48,195, 50,203, 57,231, 63,255, 63,255, 63,255, 61,239, 24,198, 0,0, 0,0, 1,224, 6,24, 8,4, 16,2, 19,50, 35,49, 32,1, 32,1, 35,49, 36,201, 32,1, 34,17, 37,41, 24,198, 0,0, 0,0, 1,224, 6,24, 8,4, 16,2, 19,50, 35,49, 32,1, 32,1, 35,49, 36,201, 32,1, 40,197, 53,43, 35,49, 0,0, 0,0, 0,0, 1,224, 7,248, 15,252, 12,204, 28,206, 31,254, 31,254, 28,206, 27,54, 31,254, 29,238, 24,198, 0,0, 0,0, 0,0, 0,0, 1,224, 7,248, 15,252, 12,204, 28,206, 31,254, 31,254, 28,206, 27,54, 31,254, 23,58, 2,16, 0,0, 0,0, 0,0 };

unsigned char GhostEyeSprites[] = {
0,0, 0,0, 0,0, 3,12, 7,158, 6,154, 7,158, 3,12, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 12,48, 30,120, 22,88, 30,120, 12,48, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 6,24, 13,52, 15,60, 15,60, 6,24, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 6,24, 15,60, 15,60, 11,44, 6,24, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0 };

unsigned char BonusCherrySprites[] = {
12,0, 15,0, 2,192, 2,32, 1,30, 0,183, 3,95, 7,109, 7,235, 7,174, 7,96, 3,192, 0,0, 0,0, 0,0, 0,0, 0,32, 1,220, 2,250, 5,39, 7,93, 7,247, 6,255, 3,218, 3,254, 1,108, 0,248, 0,32, 0,0, 0,0, 0,0, 0,0, 0,96, 1,152, 3,252, 3,236, 3,244, 7,246, 7,246, 7,254, 15,251, 15,251, 15,255, 12,127, 7,254, 0,0, 0,0, 0,0, 0,112, 1,140, 1,252, 1,252, 1,252, 0,80, 0,208, 0,80, 0,16, 0,80, 0,208, 0,80, 0,32, 0,0, 0,0, 0,0
};

unsigned char ScoreNumberSprites[] = {
0,0, 0,0, 0,0, 0,0, 49,142, 74,81, 74,80, 74,72, 74,68, 74,66, 49,159, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 49,136, 74,76, 74,74, 74,73, 74,95, 74,72, 49,136, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 49,142, 74,81, 74,81, 74,78, 74,81, 74,81, 49,142, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 99,57, 148,133, 148,133, 148,189, 148,165, 148,165, 99,25, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 24,196, 37,38, 37,36, 37,36, 37,36, 37,36, 24,206, 0,0, 0,0, 0,0, 0,0, 0,0
};

unsigned char EnergizerSprite[] = { 0b00111100,0,
				    0b01111110,0,
				    0b11111111,0,
				    0b11111111,0,
				    0b11111111,0,
				    0b11111111,0,
				    0b01111110,0,
				    0b00111100,0,
				    0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0, 0,0 };

// 8x8 sprites
unsigned char EnergizerSprite8x8[8] = { 60, 126, 255, 255, 255, 255, 126, 60 };

void line(int xl, int yb, int xr, int yt) {
#define MOVE_RIGHT 12
#define MOVE_DOWN 4
  v_directDraw32((xl-128+MOVE_RIGHT)*128, -(yb-128+MOVE_DOWN)*128, (xr-128+MOVE_RIGHT)*128, -(yt-128+MOVE_DOWN)*128, 64);
}

void drawMaze(void) {
  int i = 0;
  int lines = maze[i++];
  while (lines --> 0) {
    int points = maze[i++]-1;
    int ox = maze[i++];
    int oy = maze[i++];
    while (points --> 0) {
      int x = maze[i++];
      int y = maze[i++];
      line(ox, oy, x, y);
      ox = x; oy = y;
    }
  }
}

void v_printBitmapUni(unsigned char *bitmapBlob, int width, int height, int size, int x, int y);   

void startFrame(void) {
  v_readJoystick1Analog();
  v_readButtons();
  v_WaitRecal();
  //v_doSound();
  v_setBrightness(64);        /* set intensity of vector beam... */
  //v_playAllSFX();
}

char *Pac = PacSprites;
void PacAnimate(void) {
  static int speed = 0, Next = 32;
  return; // remove once bitmaps working again
  v_printBitmapUni(Pac, 2, 16, 60,  -8, -12);
  speed += 1;
  if ((speed&7) == 7) {
    Pac += Next;
    if ((int)Pac == (int)(PacSprites + sizeof(PacSprites)/4)) {
      Next = -Next;
      Pac += Next;
    } else if ((int)Pac == (int)(PacSprites)) {
      Next = -Next;
    }
  }
}

void Pills(void) {
  return; // remove once bitmaps working again
  v_printBitmapUni(EnergizerSprite, 2, 16, 60,  -108, -111);
  v_printBitmapUni(EnergizerSprite, 2, 16, 60,  -108,   114);
  v_printBitmapUni(EnergizerSprite, 2, 16, 60,   92,   114);
  v_printBitmapUni(EnergizerSprite, 2, 16, 60,   92,  -111);
}

void Ghosts(void) {
  v_printBitmapUni(GhostSprites, 2, 16, 60,  25, 38); // just test single bitmap for now
  return;                                             // remove this 'return' once the bitmap above is working
  v_printBitmapUni(GhostSprites, 2, 16, 60,  25, 20);
  v_printBitmapUni(GhostSprites, 2, 16, 60,  25,  0);
  v_printBitmapUni(GhostSprites, 2, 16, 60,   6, 38);
}

int main(int argc, char **argv) {
  vectrexinit(1);
  v_init();
  optimizationON = 1;
  v_setRefresh(50);
  for (;;)
  {
    startFrame();
    drawMaze();
    //PacAnimate(); // restore this once bitmaps working again

    // Ghosts(); uncomment this to test bitmaps.  currently broken.

    //Pills();      // restore this once bitmaps working again
  }
  return 0;
}