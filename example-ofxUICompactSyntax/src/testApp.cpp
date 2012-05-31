#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing(); 
    ofBackground(0); 

    setGUI1(); 
    
    gui1->setDrawBack(false);
    
    ofBackground(red.getScaledValue(), green.getScaledValue(), blue.getScaledValue()); 
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(red.getScaledValue(), green.getScaledValue(), blue.getScaledValue(), 255); 
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

void testApp::setGUI1() {
	float dim = 16; 
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING; 
    float length = 255-xInit; 

	gui1 = new ofxUICanvas(0, 0, length+xInit, ofGetHeight()); 
	gui1->setWidgetFontSize(OFX_UI_FONT_LARGE);
	gui1->addLabel("PANEL 1: BASICS");
	gui1->addLabel("Press 'h' to Hide GUIs");
	
	gui1->addSpacer(length-xInit, 2);
	gui1->setWidgetFontSize(OFX_UI_FONT_MEDIUM);
	gui1->addLabel("H SLIDERS");
	gui1->addWidgetDown(red.init("RED", 0.0, 255.0, 233, length-xInit,dim));
	gui1->addWidgetDown(green.init("GREEN", 0.0, 255.0, 27, length-xInit,dim));
	gui1->addWidgetDown(blue.init("BLUE", 0.0, 255.0, 52, length-xInit,dim));
}
