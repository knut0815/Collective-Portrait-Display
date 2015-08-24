#ifndef __haikuDisplay__imageLoader__
#define __haikuDisplay__imageLoader__

#include "ofMain.h"
class ImageLoader: public ofThread
{
public:
    ImageLoader();
    void load(string path);
    void threadedFunction();
    void draw();
    
    ofPixels        m_image;
    string          m_path;
    bool            m_isLoading;
    bool            m_isLoaded;
};
#endif