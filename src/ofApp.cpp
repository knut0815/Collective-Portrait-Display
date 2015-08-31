#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup()
{
    m_imagesPerRow = sqrt(NUM_TO_DISPLAY);
//    m_path = "/Users/Ring/Documents/openFrameworks/apps/myApps/Collective-Portrait-Motion Only/bin/data/screenshots";
    m_path = "/Users/Ring/Desktop/Faces";
    m_watchFolder.start(m_path, 2000);
    ofAddListener(m_watchFolder.fileAdded, this, &ofApp::watchFolderFileAdded);
    m_watchFolder.allowExt("png");
    
    //m_images.resize(NUM_TO_DISPLAY);
}

//--------------------------------------------------------------
void ofApp::update()
{
    for (int i = 0; i < m_images.size(); i++)
    {
        if (i < m_images.size())
        {
           
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofBackground(ofColor::fromHex(0x053e69));
    ofSetColor(ofColor::white);
    for (int i = 0; i < m_images.size(); i++) {
        if (m_images[i]->isAllocated()) {
        m_images[i]->drawSubsection(
                                   (i % 3) * IMG_DISPLAY_WIDTH + ((i % 3) + 1) * IMG_SPACER,
                                   (i / 3) * IMG_DISPLAY_HEIGHT + ((i / 3) + 1) * IMG_SPACER,
                                   IMG_DISPLAY_WIDTH,               //How wide to draw the final image
                                   IMG_DISPLAY_HEIGHT,              //How tall to draw the final image
                                   IMG_DISPLAY_WIDTH - 100,         //Where to start cropping (x)
                                   IMG_DISPLAY_HEIGHT - 200,        //Where to start cropping (y)
                                   IMG_DISPLAY_WIDTH*2,             //The source width of the cropped area
                                   IMG_DISPLAY_HEIGHT*2             //The source height of the cropped area
                                   );
        }
    }
    
#ifdef DEBUG
    ofSetColor(ofColor::red);
    ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()) + "\n" +
                       "Num Images: " + ofToString(m_images.size()), 10, 10);
#endif
}



void ofApp::watchFolderFileAdded(string &fileName)
{
    //m_images.clear();
    //m_watchFolder._watchDir.sort();
    
    m_images.push_front(new ofImage);
    
    if (m_images.size() > NUM_TO_DISPLAY)
    {
        m_images.pop_back();
    }
    string addedPath = m_watchFolder._watchDir.getAbsolutePath() + "/" + fileName;
    
#ifdef DEBUG
    cout << "File " << fileName << " added\n";
    cout << addedPath << endl;
#endif
    m_images.front()->loadImage(addedPath);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}
