#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetFrameRate(30);
	oscReceiver.setup(5000);
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	while (oscReceiver.hasWaitingMessages()) {
		
		ofxOscMessage m;
		oscReceiver.getNextMessage(m);
		
		if (m.getAddress() == "/START_LIVESTREAM")
		{
			grabber.reset();
			string url = "http://" + m.getRemoteIp() + ":8080/video";
			cout << url << endl;
			grabber.setURI(url);
			if (grabber.isConnected()) grabber.waitForDisconnect();
			grabber.connect();
		}

		else if (m.getAddress() == "/STOP_LIVESTREAM")
		{
			grabber.reset();
			if (grabber.isConnected()) grabber.waitForDisconnect();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	if (grabber.isConnected()) {
		grabber.draw(0, 0, ofGetScreenWidth(), ofGetScreenHeight());
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
