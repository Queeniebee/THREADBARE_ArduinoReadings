#include "testApp.h"
#include <iostream.h>


//--------------------------------------------------------------
void testApp::setup(){
    
    serial.enumerateDevices();
    serial.setup(0,9600);
    
    ofSetVerticalSync(true);
//    ofSetFrameRate(30);

    ofSetWindowShape(800, 600);
    ofSetCircleResolution(100);
    ofBackground(255);
    
    x = 10;
    y = 10;
    z = 10;
    
    message = ("Reading one byte at a time");
    font.loadFont("liberationsans-bold-webfont.ttf", 20, true, false, true);

//    video.loadMovie("GoodHair_JFleurantin.mov");
}

//--------------------------------------------------------------
void testApp::update(){

    int bytesRequired = 9;
    int bytesRemaining = bytesRequired;

    unsigned char bytesReturned[bytesRequired];

    while (bytesRemaining > 0) {
    
        if(serial.available() > 0){

            //cycling through all the bytes coming in from SerialPort
            int bytesPreventOverwrite = bytesRequired - bytesRemaining;
            int result = serial.readBytes(&bytesReturned[bytesPreventOverwrite], bytesRemaining);
            
            if (bytesReturned[result]=='1') {
                x = (int)bytesReturned[result+1];
            } if (bytesReturned[result+2]=='2'){
                y = (int)bytesReturned[result+3];
                
            } if (bytesReturned[result+4]=='3'){
                z = (int)bytesReturned[result+5];
                
            } if(bytesReturned[result+6]=='4'){
                FSR = (int)bytesReturned[result+7];
            }

             bytesRemaining -= result;
        
            cout<<"From the Serial Port:"<<endl;
        cout<<"A0: "<<x<<" A1: "<<y<<" A2: "<<z<<" A3: "<<FSR<<endl;
        serial.flush();
        serial.writeByte('A');

    }
    }
}
//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(10, 10, FSR);
    ofCircle(10,100,20);
    
    ofSetColor(10, 10, x);
    ofCircle(100,100,20);

    ofSetColor(10, 10, y);
    ofCircle(200,100,20);

    ofSetColor(10, 10, z);
    ofCircle(300,100,20);

    
    
    cout<<"On the Screen"<<endl;
    cout<<"A0: "<<x<<" A1: "<<y<<" A2: "<<z<<" A3: "<<FSR<<endl;

    
}

//--------------------------------------------------------------
void urlResponse(ofHttpResponse & response){



}
//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
