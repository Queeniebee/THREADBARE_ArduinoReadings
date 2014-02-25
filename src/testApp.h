#pragma once

#define GLFW_EXPOSE_NATIVE_COCOA
#define GLFW_EXPOSE_NATIVE_NSGL

#include "ofMain.h"
#include "ofxOpenCv.h"
#include <GLFW/glfw3.h>
#include "GLFW/glfw3native.h"
#include <Cocoa/Cocoa.h>
#include <Carbon/Carbon.h>
#include "ofAppGLFWWindow.h"

#define NUM_VIDS 4

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void urlResponse(ofHttpResponse & response);
    ofAppGLFWWindow * WINDOW;

    ofSerial serial;
    ofFbo fbo[NUM_VIDS];
    string paths[NUM_VIDS];
    
    ofVideoPlayer video[NUM_VIDS];
    
    ofRectangle uiScreenRect;
    vector<ofRectangle> screens;
    int x; int y; int z;
    int FSR = 10;
    float playhead, playhead2, playhead3, playhead4;
    
    
};

struct screenSortClass {
    bool operator()(ofRectangle a, ofRectangle b)
    {
        return a.x < b.x;
        }
    } screenSort;