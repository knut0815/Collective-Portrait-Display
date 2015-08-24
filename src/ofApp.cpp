#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup()
{
    m_imagesPerRow = sqrt(NUM_TO_DISPLAY);
    m_path = "/Users/MichaelWalczyk/Documents/openFrameworks/apps/myApps/collectivePortrait_01/bin/data/screenshots";
    m_dir.open(m_path);
    m_dir.setWriteable(true);
    m_dir.allowExt("png");
    m_dir.listDir();
    
    cout << m_dir.numFiles() << endl;
    
    m_currentNumFiles = m_dir.numFiles();
    
    updateImages();
}

//--------------------------------------------------------------
void ofApp::update()
{
    int numFiles = m_dir.numFiles();
    if (m_currentNumFiles != numFiles)
    {
        updateImages();
        m_currentNumFiles = m_dir.numFiles();
    }
    
    for (int i = 0; i < m_threadedImages.size(); i++)
    {
        if (m_threadedImages[i]->m_isLoaded)
        {
            if (m_images.size() <= i) {
                m_images.resize(i+1);
            }
            m_images[i].getPixelsRef() = m_threadedImages[i]->m_image;
            m_images[i].update();
            m_threadedImages[i]->m_isLoaded = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (int i = 0; i < m_images.size(); i++) {
        m_images[i].draw((i % m_imagesPerRow) * IMG_DISPLAY_WIDTH,
                                          (i / m_imagesPerRow) * IMG_DISPLAY_HEIGHT,
                                          IMG_DISPLAY_WIDTH,
                                          IMG_DISPLAY_HEIGHT);
    }
}

void ofApp::updateImages()
{
    m_threadedImages.clear();
    m_images.clear();
    m_dir.sort();
    int limit = min(m_dir.numFiles(), 9);
    
    for (int i = 0; i < limit; i++) {
        int indexFromEnd = (m_dir.numFiles() - 1) - i;
#ifdef DEBUG
        cout << m_dir.getPath(indexFromEnd) << endl;
#endif
        //ofImage img;
        //img.loadImage(m_dir.getPath(indexFromEnd));
        //m_images.push_back(img);
        m_threadedImages.push_back(new ImageLoader);
        m_threadedImages.back()->load(m_dir.getPath(indexFromEnd));
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}
