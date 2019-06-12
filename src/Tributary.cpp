//
//  tributary.cpp
//  Created by Jenna deBoisblanc on 3/3/18.
//
//

#include <stdio.h>
#include "Tributary.h"

Tributary::Tributary(){}

Tributary::Tributary(ofPolyline p){
    riverPath = p;
}


void Tributary::update(){

}


void Tributary::draw(ofxInkSim *ink, SampleBrush *brush){
    int sep = 2;
    int pt = 0;
//    int xOffset = 100;
//    int yOffset = 100;
//    float factor = 1.1;
    int xOffset = 0;
        int yOffset = 0;
        float factor = 0.8;
    while(pt < riverPath.getLengthAtIndex(riverPath.size()-1)) {
        ofPoint p = riverPath.getPointAtLength(pt);
        ink->stroke(brush, p.x*factor + xOffset, p.y*factor + xOffset, getInkColor(0, 255, 10));
        pt += sep;
    }
}

void Tributary::flow(ofxInkSim *ink, SampleBrush *brush){
    int step = 5;
    if(flowSpot+step < riverPath.getLengthAtIndex(riverPath.size()-1)) {
        ofPoint p0 = riverPath.getPointAtLength(flowSpot);
        ofPoint p1 = riverPath.getPointAtLength(flowSpot+step);
        ink->stroke(brush, p0.x, p0.y, getInkColor(ofRandom(0,5), 255, 10));
        ink->stroke(brush, p1.x, p1.y, getInkColor(ofRandom(0,5), 255, 10));
        flowSpot += step;
    }
}


void Tributary::pulse(){
    
}

float Tributary::getLength() {
    return(riverPath.getLengthAtIndex(riverPath.size()-1));
}



