#include "ofApp.h"

// an example of what OSC messages to check for using ofxRPiezos

#define NUM_PIEZOS 8

//--------------------------------------------------------------
void ofApp::setup(){
	// listen on the given port
	cout << "listening for osc messages on port " << PORT << "\n";
	receiver.setup(PORT);

    envelopes.resize(NUM_PIEZOS);
    triggers.resize(NUM_PIEZOS);
    triggerTimers.resize(NUM_PIEZOS);
    for( int i=0; i<NUM_PIEZOS; ++i) {
        envelopes[i] = 0.0f;
        triggers[i] = 0.0f;
        triggerTimers[i] = 0;
    }

	ofBackground( 0 );
    ofDisableAntiAliasing();
}

//--------------------------------------------------------------
void ofApp::update(){

	while(receiver.hasWaitingMessages()){
		ofxOscMessage m;
		receiver.getNextMessage(m);

        // first data is the piezo index, second is the value 
        if( m.getAddress() == "/piezos/trigger" ){

            int channel = m.getArgAsInt32(0);
            float value = m.getArgAsFloat(1);
            
            triggers[channel] = value;
            triggerTimers[channel] = 8;
            
        }else if( m.getAddress() == "/piezos/envelope" ){
            
            int channel = m.getArgAsInt32(0);
            float value = m.getArgAsFloat(1);

            envelopes[channel] = value;
            
        }
	}
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 85, 85);
	string buf;
	buf = "listening for osc messages\non port " + ofToString(PORT);
	ofDrawBitmapString(buf, 20, 20);

    ofTranslate( 20, 50);
    
    int w = ofGetWidth()-40;
    int h = 20;
    
    for( int i=0; i<NUM_PIEZOS; ++i){
        
        ofDrawBitmapString( "/piezos/trigger ch"+ofToString(i), 0, 15 );
        if( triggerTimers[i]>0 ){
            ofFill();
            ofSetColor(255, 85, 85, 255*triggers[i]);
            ofDrawRectangle( 0, 20, w, h);
            triggerTimers[i]--;
        }
 
        ofNoFill();
        ofSetColor(255, 85, 85);
        ofDrawRectangle( 0, 20, w, h);
        
        ofTranslate(0, 40);
        
        ofDrawBitmapString( "/piezos/envelope ch"+ofToString(i), 0, 15 );

        ofFill();
        ofDrawRectangle( 0, 20, w*envelopes[i], h);
 
        ofNoFill();
        ofSetColor(255, 85, 85);
        ofDrawRectangle( 0, 20, w, h);
        
        ofTranslate(0, 40);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){}
void ofApp::keyReleased(int key){}
void ofApp::mouseMoved(int x, int y){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
void ofApp::mouseReleased(int x, int y, int button){}
void ofApp::mouseEntered(int x, int y){}
void ofApp::mouseExited(int x, int y){}
void ofApp::windowResized(int w, int h){}
void ofApp::gotMessage(ofMessage msg){}
void ofApp::dragEvent(ofDragInfo dragInfo){}
