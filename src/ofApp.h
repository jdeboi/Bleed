#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
#include "Tributary.h"
#include "ofxInkSim.h"
#include "SampleBrush.h"
#include "GUI.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        void bleedLines();
        void flowLines(int t);
        void randomBleedLine(int t);
        vector<int> canBleed;
        unsigned long prevTime;
    
        // background Image
        ofImage bg;
    
        // gui
        GUI gui;
    
        // SVG
        ofxSVG svg;
        float step;
        vector<Tributary> tributaries;
    
        vector<ofPoint> points;

    
        // Ink
        ofxInkSim inkSim;
        SampleBrush brush;
    
    
    
        bool evapOn = false;
    
};
