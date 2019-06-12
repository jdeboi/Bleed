#include "ofApp.h"

// ofxInkSim.cpp line 195 (draw())
// ofEnableBlendMode(OF_BLENDMODE_SCREEN); instead of ALPHA

//--------------------------------------------------------------
void ofApp::setup(){
    ////////////////////////////
    // bg image
    bg.load("delta.jpg");
    
    ////////////////////////////
    // gui
    // gui.setup(inkSim.getUniformInfo());
    
    ////////////////////////////
    // SVG
    svg.load("delta_justlines2.svg");
    for( int k = 0; k < svg.getNumPath(); k++) {
        ofPath& mypath = svg.getPathAt(k);
        const vector<ofPolyline>& polylines = mypath.getOutline();
        canBleed.push_back(k);
        tributaries.push_back(*new Tributary(polylines[0]));
        
    }
    prevTime=ofGetElapsedTimeMillis();
    
    ////////////////////////////
    // ink
    inkSim.setup(); //inkSim.setDrawMode(ofxInkSim::INKSURF);
    bleedLines();
    
    ofSetFrameRate(20);

}

//--------------------------------------------------------------
void ofApp::update(){
//     if (ofGetElapsedTimeMillis() > 20000) {
    inkSim.update(false);
//     }
}

//--------------------------------------------------------------
void ofApp::bleedLines() {
    for (int i = 0; i < tributaries.size(); i++) {
            tributaries[i].draw(&inkSim, &brush);
            inkSim.stopStroke(&brush);
    }
}

void ofApp::flowLines(int t) {
    if (ofGetElapsedTimeMillis() - prevTime > t) {
        for (int i = 0; i < tributaries.size(); i++) {
            tributaries[i].flow(&inkSim, &brush);
            inkSim.stopStroke(&brush);
        }
    }
}

//--------------------------------------------------------------
void ofApp::randomBleedLine(int t) {
    if (ofGetElapsedTimeMillis() - prevTime > t) {
        if (canBleed.size() > 0) {
            int r = int(ofRandom(0, canBleed.size()));
            tributaries[canBleed[r]].draw(&inkSim, &brush);
            inkSim.stopStroke(&brush);
            canBleed.erase(canBleed.begin() + r);
        }
        else {
            for( int k = 0; k < tributaries.size(); k++) {
                canBleed.push_back(k);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ////////////////////////////
    // bleeding
   
    ofPushMatrix();
    float factor = 0.8;
    float w = bg.getWidth()*factor;
    float h = bg.getHeight()*factor;
    float centerW = (ofGetWidth()-w)/2.0;
   
    ofTranslate(centerW, 0, 0);
    bg.draw(0,0, w, h);
    
    inkSim.draw();

    ofPopMatrix();
    
    
    ////////////////////////////
    // gui
//    gui.draw();
//
//    if (ofGetElapsedTimeMillis() - prevTime > 18000) {
//        inkSim.clear();
//        inkSim.end();
//
//    }
    string info = "fps: " + ofToString(ofGetFrameRate(),2);
    cout << info << endl;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1')
    {
        inkSim.setDrawMode(ofxInkSim::INKFIX);
    }
    else if (key == '2')
    {
        inkSim.setDrawMode(ofxInkSim::INKSURF);
    }
    else if (key == '3')
    {
        inkSim.setDrawMode(ofxInkSim::INKFLOW);
    }
    else if (key == '4')
    {
        inkSim.setDrawMode(ofxInkSim::WATERFLOW);
    }
    else if (key == 'd')
    {
        inkSim.toggleDebug();
        
    }
    else if (key == ' ')
    {
        gui.toggleVisible();
    }
    else if (key == 'r')
    {
        gui.resetToDefault();
    }
    else if (key == 'c')
    {
        inkSim.stopStroke(&brush);
        inkSim.clear();
        
        ofBackground(255);
        bleedLines();
    }
    else if (key == 'f') {
        
        evapOn = !evapOn;
        cout << evapOn << endl;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    inkSim.stroke(&brush, x, y, getInkColor(0, 255, 10));
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    inkSim.stopStroke(&brush);
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

//--------------------------------------------------------------
void ofApp::exit(){

}
