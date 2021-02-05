// ------ GAME INFO ------
// Const
#define TITLE_LENGTH 16
#define SRC_LENGTH 32
#define N_OBJ_COLLECTION 16
// Title
#define GAME_TITLE "GAME NAME"
// Credits
#define DEV_NAME0 "François GETE"
#define DEV_NAME1 "LAG Studio"
// Options
#define FS_OFF .5
#define FS_ON 1
#define FRAME_RATE 24
float WINDOW_RATIO = FS_OFF;
// FPS DEBUG
int nFrame = 0;
int oldClock = 0;
int fps = 0;

// PROTOTYPES
void FPS_Info();

// FPS DEBUG
void FPS_Info(){
    // We get an average frame rate at 24fps.
    // Enough to make animations but still too low for a full game.
    nFrame++;
    // printf("nFrame : %d\n", nFrame);
    if (oldClock != (int)(clock() / 1000)){
        fps = nFrame;
        nFrame = 0;
        oldClock = (int)(clock() / 1000);
        printf("time = %ds | FPS = %d\n", oldClock, fps);
    }
}
