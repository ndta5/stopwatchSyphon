#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(24);
    output.setName("stopwatchSyphon");
    
    //バックグランドを透明色に設定
    ofBackground(0, 0);
    
    ofSetWindowTitle("Stopwatch");

    // Fonts
    fontText.load("Lato-Regular.ttf", 50); // フォントのデータを指定する

    // GUI
    gui.setup();
    gui.add(fontSizeSlider.setup("Font size", 50, 10, 255));
    gui.add(color.set("color", ofColor(255, 255, 0)));

}

//--------------------------------------------------------------
void ofApp::update(){

    if(isRunning){
        elapsedTime = ofGetElapsedTimeMillis() - startTime + pausedTime;
    }

    if(fontSize != fontSizeSlider){
        fontSize = fontSizeSlider;
        fontText.load("Lato-Regular.ttf", fontSize);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    //Stopwatch
    int hours = elapsedTime / 3600000;
    int minutes = elapsedTime / 60000;
    int seconds = elapsedTime / 1000 % 60;
    int milliseconds = elapsedTime % 1000 / 10;
    str = ofToString(hours, 2, '0') + ":" +ofToString(minutes, 2, '0') + ":" + ofToString(seconds, 2, '0') + "." + ofToString(milliseconds, 2, '0');

    //Lap time
    if(lapTime != 0){
        hours = lapTime / 3600000;
        minutes = lapTime / 60000;
        seconds = lapTime / 1000 % 60;
        milliseconds = lapTime % 1000 / 10;
        str += "\n" + ofToString(hours, 2, '0') + ":" +ofToString(minutes, 2, '0') + ":" + ofToString(seconds, 2, '0') + "." + ofToString(milliseconds, 2, '0');
    }

    ofSetColor(color);
    fontText.drawString(str, positionX, positionY);

    //ここでSyphon送信
    output.publishScreen();
    
    gui.draw();

    ofSetColor(255);
    ofDrawBitmapString("press 's' to start/stop 'r' to reset/lap time", 100, 480);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 's'){
        if(isRunning){
            isRunning = false;
            pausedTime = elapsedTime; //一時停止時間を記録
        } else {
            startTime = ofGetElapsedTimeMillis();
            isRunning = true;
        }
    }

    if(key == 'r'){
        if(isRunning){
            lapTime = elapsedTime - splitTime;
            splitTime = elapsedTime;
        } else {
            elapsedTime = 0;
            pausedTime = 0;
            lapTime = 0;
            splitTime = 0;
            isRunning = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    positionX = x;
    positionY = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    positionX = x;
    positionY = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
