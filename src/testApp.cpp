#include "testApp.h"
#include <iostream.h>


//--------------------------------------------------------------
void testApp::setup(){
    
    serial.enumerateDevices();
    serial.setup(0,9600);
    
    ofSetVerticalSync(true);
//    ofSetFrameRate(60);
//    ofSetWindowShape(1024,768);
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
    

    
}

//--------------------------------------------------------------
void testApp::update(){

 
    int bytesRequired = 9;
    int bytesRemaining = bytesRequired;
    int bytesPreventOverwrite = bytesRequired - bytesRemaining;

    unsigned char bytesReturned[bytesRequired];
/*
// Documentation Way 
    while (bytesRemaining > 0) {
    
        if(serial.available() > 0){

            //cycling through all the bytes coming in from SerialPort
            int bytesPreventOverwrite = bytesRequired - bytesRemaining;
            int result = serial.readBytes(&bytesReturned[bytesPreventOverwrite], bytesRemaining);
            
            if ( result == OF_SERIAL_ERROR )
            {
                // something bad happened
                ofLog( OF_LOG_ERROR, "unrecoverable error reading from serial" );
                // bail out
                break;
            }
            else if ( result == OF_SERIAL_NO_DATA )
            {
                // nothing was read, try again
            }
            else
            {
            
            if (bytesReturned[result]=='1') {
                x = bytesReturned[result+1];
            } if (bytesReturned[result+2]=='2'){
                y = bytesReturned[result+3];
                
            } if (bytesReturned[result+4]=='3'){
                z = bytesReturned[result+5];
                
            } if(bytesReturned[result+6]=='4'){
                FSR = bytesReturned[result+7];
            }

             bytesRemaining -= result;
            }
        
            cout<<"From the Serial Port:"<<endl;
        cout<<"A0: "<<x<<" A1: "<<y<<" A2: "<<z<<" A3: "<<FSR<<endl;
        serial.flush();
        serial.writeByte('A');

    }
    }
 */
    
   if(serial.available() > 0){
//Found Code Way
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
/*
    fbo2.begin();
    ofSetColor(255, 255, 255, 255);
    ofRect(0,0,400,300);
    video.draw(0, 0, 400.0, 300.0);
    fbo2.end();

    fbo3.begin();
    ofSetColor(255, 255, 255, 255);
    ofRect(0,0,400,300);
    video.draw(0, 0, 400.0, 300.0);
    fbo3.end();
    
    fbo4.begin();
    ofSetColor(255, 255, 255, 255);
    ofRect(0,0,400,300);
    video.draw(0, 0, 400.0, 300.0);
    fbo4.end();
 
 */
    
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
