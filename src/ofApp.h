#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void changeNumber(int n);
    
    //ofImageをインスタンス化
    ofImage myImage;
    string pixelString;
    string asciiCharacters;
    ofTrueTypeFont  font;
    string numString;
    ofTrueTypeFont infoFont;
};
