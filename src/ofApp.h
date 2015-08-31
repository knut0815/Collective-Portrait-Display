#pragma once

#include "ofMain.h"
#include "ofxMtlWatchFolder.h"
#define DEBUG

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void watchFolderFileAdded(string &fileName);
    
    void updateImages();
    
    deque<ofImage*>         m_images;

    ofxMtlWatchFolder       m_watchFolder;
    
    string                  m_path;
    ofDirectory             m_dir;
    int                     m_currentNumFiles;
    int                     m_imagesPerRow;
    
    static const int        NUM_TO_DISPLAY =        15;
    static const int        IMG_SPACER =            15;
    static const int        IMG_DISPLAY_WIDTH =     340; //(1080 - 4 * 15) / 3
    static const int        IMG_DISPLAY_HEIGHT =    366; //(1920 - 6 * 15) / 5
};
