#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"
#include "ofxGui.h"
#include <chrono>
#include <iomanip>
#include <sstream>

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
		
private:
    ofxSyphonServer output;
    ofTrueTypeFont fontText;
    int startTime = 0;
    int elapsedTime = 0;
    int pausedTime = 0;
    int lapTime = 0;
    int splitTime = 0;
    int fontSize = 0;
    int positionX = 100;
    int positionY = 100;
    bool isRunning = false;
    string str;
    
    ofxIntSlider fontSizeSlider;
    ofParameter<ofColor> color;
    ofxPanel gui;
};
