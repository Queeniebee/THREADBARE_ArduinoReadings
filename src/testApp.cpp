#include "testApp.h"
#include <iostream.h>


//--------------------------------------------------------------
void testApp::setup(){
    
    serial.enumerateDevices();
    serial.setup(0,9600);
    
    ofSetVerticalSync(true);
//    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    
    x = 10;
    y = 10;
    z = 10;
    
    for(int j = 0; j < NUM_VIDS; j++){
        fbo[j].allocate(400, 300, GL_RGBA);
        
    }
    
    paths[0] = "handsTrees.mov";
    paths[1] = "test_video/Resources/test_video.mov";
    paths[2] = "test_video2/Resources/test_video2.mov";
    paths[3] = "handsTrees2.mov";
    
    for(int i = 0; i < NUM_VIDS; i++){
        video[i].loadMovie(paths[i]);
        video[i].play();
    }
//I need to toggle Fullscreen to activate it
    
int monitorCount;
    
int leftMost = 0, topMost = 0;
 
 GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);
    cout<<"Monitor Count: "<<monitorCount<<endl;

    for(int i = 0; i < monitorCount; i++){
        int screenXX=0,screenYY=0, width=0, height=0;

    ofRectangle screen;

    glfwGetMonitorPos(monitors[i],&x,&y);
    const GLFWvidmode * desktopMode = glfwGetVideoMode(monitors[i]);
      
    screen.x = screenXX;
    screen.y = screenYY;
    screen.width = desktopMode->width;
    screen.height = desktopMode->height;

    screens.push_back(screen);clearerr(<#FILE *#>)
    
    if( leftMost > screen.x ) leftMost = screen.x;
    if( topMost > screen.y ) topMost = screen.y;
    
    }

    for(int i = 0; i < monitorCount; i++){
        screens[i].x -= leftMost;
        screens[i].y -= topMost;
        
    }
	std::sort( screens.begin(), screens.end(), screenSort );
    
    uiScreenRect = screens.back();
    
    if(ofGetWindowMode() == OF_WINDOW) ofSetWindowPosition(20, 20);
}

//--------------------------------------------------------------
void testApp::update(){

 
    int bytesRequired = 9;
    int bytesRemaining = bytesRequired;
    int bytesPreventOverwrite = bytesRequired - bytesRemaining;

    unsigned char bytesReturned[bytesRequired];
    
   if(serial.available() > 0){

       serial.readBytes(&bytesReturned[bytesPreventOverwrite], bytesRemaining);
        if (bytesReturned[0]=='1') {
            x = bytesReturned[1];
        } if (bytesReturned[2]=='2'){
            y = bytesReturned[3];
            
        } if (bytesReturned[4]=='3'){
            z = bytesReturned[5];
            
        } if(bytesReturned[6]=='4'){
            FSR = bytesReturned[7];
        }

        cout<<"From the Serial Port:"<<endl;
        cout<<"A0: "<<x<<" A1: "<<y<<" A2: "<<z<<" A3: "<<FSR<<endl;
        serial.flush();
        serial.writeByte('A');
    
    }

    for (int i = 0; i < NUM_VIDS; i++) {
		video[i].update();
	}
    
//    playhead = ofMap(FSR, 0, 255, 0, 0.25, true);
//    playhead2 = ofMap(x, 0, 255, 0.25, 0.5, true);
//    playhead3 = ofMap(y, 0, 255, 0.5, 0.75, true);
//    playhead4 = ofMap(z, 0, 255, 0.75, 1, true);
    
    for(int j = 0; j < NUM_VIDS; j++){
        fbo[j].begin();
        ofSetColor(255, 255, 255, 255);
        ofRect(0,0,400,300);
        video[j].draw(0, 0, 400.0, 300.0);
//        video[j].setPosition(playhead);
        fbo[j].end();
    
    }
    
}
//--------------------------------------------------------------
void testApp::draw(){
    
    float xPos = 10.0;
    float yPos = 150.0;
    
    for(int i = 0; i < NUM_VIDS; i++){
        fbo[i].draw(xPos, yPos);
        yPos += 310.0;

        if (yPos == 770.0) {
            yPos = 150.0;
            xPos += 420.0;
        } else if(xPos == 850.0){
            xPos = 430.0;
        }
    }
 
    
    ofSetColor(10, 10, FSR);
    ofCircle(40,100,20);
    
    ofSetColor(10, 10, x);
    ofCircle(100,100,20);

    ofSetColor(10, 10, y);
    ofCircle(200,100,20);

    ofSetColor(10, 0, z);
    ofCircle(300,100,20);
    
    float d = ofGetLastFrameTime();
//    ofRect(uiScreenRect.x, uiScreenRect.y, 500, 700);
    
    cout<<"On the Screen"<<endl;
    cout<<"A0: "<<x<<" A1: "<<y<<" A2: "<<z<<" A3: "<<FSR<<endl;

    
}
//--------------------------------------------------------------
void urlResponse(ofHttpResponse & response){



}
//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'D'){
    
        ofToggleFullscreen();
    
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
