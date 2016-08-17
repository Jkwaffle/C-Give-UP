#include "Framework\timer.h"
#include "GameClass.h"

#pragma comment(lib, "winmm.lib")

bool exitGame= false;
CStopWatch gameTimer;
const unsigned char gc_ucFPS = 100;
const unsigned int gc_ucFrameTime = 1000 / gc_ucFPS;

void mainLoop();

int main(){

	mainLoop();
}

void mainLoop(){
	gameTimer.startTimer();

	while (!exitGame){

		getInput();
		Update(gameTimer.getElapsedTime());
		Render();
		gameTimer.waitUntil(gc_ucFrameTime);
	}
}
//bool closeGame = false;		// set true to close game
//const unsigned char gc_ucFPS = 100;                // FPS of this game
//const unsigned int gc_uFrameTime = 1000 / gc_ucFPS;    // time for each frame
//
//void mainLoop();
//
//int main(){
//

//	mainLoop();
//
//	return 0;

//
//
//
//
//
//void mainLoop(){
//
//	//gameTimer.startTimer();
//	while(!closeGame){
//		
//		// Add stuff here to do
//
//
//	}
//
//
//}
//
