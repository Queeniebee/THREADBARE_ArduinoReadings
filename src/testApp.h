#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

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
		
    ofSerial serial;
    ofFbo fbo, fbo2, fbo3, fbo4;
    
    ofVideoPlayer video, video2, video3, video4;
    
    ofTrueTypeFont font;
    string message;
    
    int x; int y; int z;
    int FSR = 10;
    float playhead, playhead2, playhead3, playhead4;
    
    
};
