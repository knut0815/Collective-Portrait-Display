#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main()
{
	ofSetupOpenGL(1080, 1920, OF_WINDOW);
    ofSetWindowPosition(0, 0);//1080*2
    ofRunApp(new ofApp());
}
