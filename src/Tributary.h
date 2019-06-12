//
//  tributary.h
//  ledInstall
//
//  Created by Jenna deBoisblanc on 6/30/17.
//
//

#ifndef Tributary_h
#define Tributary_h

#include "ofMain.h"
#include "ofxInkSim.h"
#include "SampleBrush.h"

class Tributary {
    
public:
    void update();
    void draw(ofxInkSim *ink, SampleBrush *brush);
    void flow(ofxInkSim *ink, SampleBrush *brush);
    void pulse();
    void bleed();
    
    float getLength();
    
    int flowSpot;
    
    vector<ofPoint> getPoints();
    
    ofPolyline riverPath;
 
    Tributary();
    Tributary(ofPolyline p);
    
    
private:
    
};

#endif /* Tributary_h */

