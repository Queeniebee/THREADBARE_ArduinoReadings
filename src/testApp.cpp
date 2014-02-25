#include "testApp.h"
#include <iostream.h>


//--------------------------------------------------------------
void testApp::setup(){
    
    serial.enumerateDevices();
    serial.setup(0,9600);
    
    ofSetVerticalSync(true);
//    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    
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
// I need to toggle Fullscreen to activate it
    
int monitorCount;
    
int leftMost = 0, topMost = 0;
 
 GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);
    cout<<"Monitor Count: "<<monitorCount<<endl;

   int screenXX=0,screenYY=0, screenXXX=0, screenYYY=0;

    glfwGetMonitorPos(monitors[0],&screenXX,&screenYY);
    glfwGetMonitorPos(monitors[1],&screenXXX,&screenYYY);

    const GLFWvidmode * desktopMode = glfwGetVideoMode(monitors[0]);
    
    cout<<"Monitor Position: "<<screenXX<<endl;
    cout<<"Monitor Position: "<<screenXXX<<" "<<screenYYY<<endl;

    
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
//       cout<<"setValues[0]: "<<setValues[0]<<"setValues[1]: "<<setValues[1]<<"setValues[2]: "<<setValues[2]<<"setValues[3]: "<<setValues[3]<<endl;
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

    //I don't know why not getting clean results when iterating through an INT ARRAY    
//    fadeAMT[0] = x; fadeAMT[1] = y; fadeAMT[2] = z; fadeAMT[3] = FSR;

    
    for(int j = 0; j < NUM_VIDS; j++){
        fbo[j].begin();
        ofSetColor(255, 255, 255, fadeAMT);
        ofRect(0,0,400,300);
        video[j].draw(0, 0, 400.0, 300.0);
        fbo[j].end();
    
    }
    
}
//--------------------------------------------------------------
void testApp::draw(){
    
    float xPos = 10.0;
    float yPos = 150.0;
    
    fbo[0].draw(xPos, yPos);
    fbo[1].draw(1450.0, yPos);
    fbo[2].draw(430.0, 460.0);
    fbo[3].draw(1850.0, 480.0);
    
    ofSetColor(10, 10, FSR);
    ofCircle(40,100,20);
    
    ofSetColor(10, 10, x);
    ofCircle(100,100,20);

    ofSetColor(10, 10, y);
    ofCircle(200,100,20);

    ofSetColor(10, 0, z);
    ofCircle(300,100,20);

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
    
    
    if(key == 'l'){
        fadeAMT = x;
    
    } if(key == 'k'){
        fadeAMT = y;
    
    } if(key == 'j'){
        fadeAMT = FSR;
    
    } if(key =='h') {
    
        fadeAMT = z;
    }

    
    
//    switch (key){
//
//     case 'l':
//            fadeAMT = x;
//            break;
//     case 'k':
//            fadeAMT = y;
//            break;
//     case 'j':
//            fadeAMT = z;
//            break;
//     case 'h':
//            fadeAMT = FSR;
//            break;
//     }
    
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
