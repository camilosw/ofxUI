#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableSmoothing(); 
    ofBackground(0); 

    setGUI1();
    setGUI2();
    setGUI3();
    
    gui1->setDrawBack(false);
    gui2->setDrawBack(false);
    gui3->setDrawBack(false);
    
    ofBackground(red.getScaledValue(), green.getScaledValue(), blue.getScaledValue()); 
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(red.getScaledValue(), green.getScaledValue(), blue.getScaledValue(), 255); 

	ofPushStyle(); 
	ofEnableBlendMode(OF_BLENDMODE_ALPHA); 

	if(drawGridButton.getValue() || drawGridToggle.getValue())
	{
		ofSetColor(255, 255, 255, 25);	
		drawGrid(8,8); 
	}
    
	ofPopStyle(); 
    
    ofSetRectMode(OF_RECTMODE_CENTER); 
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

void testApp::drawGrid(float x, float y)
{
    float w = ofGetWidth(); 
    float h = ofGetHeight(); 
    
    for(int i = 0; i < h; i+=y)
    {
        ofLine(0,i,w,i); 
    }
    
    for(int j = 0; j < w; j+=x)
    {
        ofLine(j,0,j,h); 
    }    
}

void testApp::setGUI1() {
	float dim = 16; 
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING; 
    float length = 255-xInit; 

    vector<string> names; 
	names.push_back("RAD1");
	names.push_back("RAD2");
	names.push_back("RAD3");	

	gui1 = new ofxUICanvas(0, 0, length+xInit, ofGetHeight()); 
	gui1->setWidgetFontSize(OFX_UI_FONT_LARGE);
	gui1->addLabel("PANEL 1: BASICS");
	gui1->addLabel("Press 'h' to Hide GUIs");
	
	gui1->addSpacer(length-xInit, 2);
	gui1->setWidgetFontSize(OFX_UI_FONT_MEDIUM);
	gui1->addLabel("H SLIDERS");
	gui1->add(red.init("RED", 0.0, 255.0, 233, length-xInit,dim));
	gui1->add(green.init("GREEN", 0.0, 255.0, 27, length-xInit,dim));
	gui1->add(blue.init("BLUE", 0.0, 255.0, 52, length-xInit,dim));
	
    gui1->addSpacer(length-xInit, 2); 
    gui1->addLabel("V SLIDERS"); 
	gui1->addSlider("0", 0.0, 255.0, 150, dim, 160);
	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
	gui1->addSlider("1", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("2", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("3", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("4", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("5", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("6", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("7", 0.0, 255.0, 150, dim, 160);
	gui1->addSlider("8", 0.0, 255.0, 150, dim, 160);
	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);

    gui1->addWidgetDown(new ofxUISpacer(length-xInit, 2));     
	gui1->addRadio("RADIO HORIZONTAL", names, OFX_UI_ORIENTATION_HORIZONTAL, dim, dim); 
	gui1->addRadio("RADIO VERTICAL", names, OFX_UI_ORIENTATION_VERTICAL, dim, dim); 

    gui1->addSpacer(length-xInit, 2); 
	gui1->addLabel("BUTTONS");
	gui1->add(drawGridButton.init("DRAW GRID", false, dim, dim));
	gui1->addLabel("TOGGLES");
	gui1->add(drawGridToggle.init("D_GRID", false, dim, dim));
	
    gui1->addSpacer(length-xInit, 2);
    gui1->addLabel("RANGE SLIDER");
	gui1->addRangeSlider("RSLIDER", 0.0, 255.0, 50.0, 100.0, length-xInit, dim);

    gui1->addSpacer(length-xInit, 2);
	gui1->addLabel("2D PAD");
	gui1->add2DPad("PAD", ofPoint(0, length-xInit), ofPoint(0, 120), ofPoint((length-xInit)*.5,120*.5), length-xInit,120);
	
}

void testApp::setGUI2() {
   	float dim = 16; 
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING; 
    float length = 255-xInit; 

	gui2 = new ofxUICanvas(length+xInit+2, 0, length+xInit, ofGetHeight()); 
	gui2->setWidgetFontSize(OFX_UI_FONT_LARGE);
    gui2->addLabel("PANEL 2: ADVANCED"); 

    gui2->addSpacer(length-xInit, 2);
	gui2->setWidgetFontSize(OFX_UI_FONT_MEDIUM);
    gui2->addLabel("LABEL TOGGLES");
    gui2->addLabelToggle("LABEL TOGGLE", false, length-xInit);     
    gui2->addLabelToggle("AUTOSIZE TOGGLE", false);
    gui2->addLabelToggle("MEDIUM TOGGLE", false);

}

void testApp::setGUI3() {
	float dim = 16; 
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING; 
    float length = 255-xInit; 
	gui3 = new ofxUICanvas(length*2+xInit*2+4, 0, length+xInit, ofGetHeight());     
    gui3->setWidgetFontSize(OFX_UI_FONT_LARGE);
    gui3->addLabel("PANEL 3: ADVANCED");
    
    gui3->setWidgetFontSize(OFX_UI_FONT_MEDIUM);
    
    gui3->addSpacer(length-xInit, 2);
    gui3->addLabel("ROTARY SLIDER");
    gui3->addRotarySlider("R2SLIDER", 0, 100, 50, dim*4);

    gui3->addSpacer(length-xInit, 2);
    gui3->addLabel("DROP DOWN");

    vector<string> items; 
    items.push_back("FIRST ITEM"); 
    items.push_back("SECOND ITEM"); 
    items.push_back("THIRD ITEM WHATS UP DOG"); 
    items.push_back("FOURTH ITEM"); 
    items.push_back("FIFTH ITEM"); 
    items.push_back("SIXTH ITEM");     
    
    gui3->addDropDownList("DROP DOWN LIST", items, 200);
}