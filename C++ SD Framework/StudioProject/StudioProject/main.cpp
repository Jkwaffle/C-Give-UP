#include "Framework\timer.h"
#include "GameClass.h"

#pragma comment(lib, "winmm.lib")

bool exitGame= false;
CStopWatch gameTimer;
const unsigned char gc_ucFPS = 100;
const unsigned int gc_ucFrameTime = 1000 / gc_ucFPS;

void mainLoop();

int main(){
	Init();
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
