#pragma once

#include "ofMain.h"
#include "imageLoader.h"
//#define DEBUG

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void updateImages();
    
    vector<ofImage>     m_images;
    vector<ImageLoader*> m_threadedImages;
    string              m_path;
    ofDirectory         m_dir;
    int                 m_currentNumFiles;
    int                 m_imagesPerRow;
    
    static const int    NUM_TO_DISPLAY =        9;
    static const int    IMG_DISPLAY_WIDTH =     300;
    static const int    IMG_DISPLAY_HEIGHT =    300;
};
