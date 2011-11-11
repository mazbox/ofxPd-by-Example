#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	// puredata works on sounds in chunks of 64 samples (called a tick)
	// 8 ticks per buffer corresponds to 8 * 64 sample buffer size (512 samples)
	int ticksPerBuffer = 8;
	pd.init(2, 0, 44100, ticksPerBuffer);
	
	// open the patch (relative to the data folder)
	pd.openPatch("theremin.pd");
	
	// start pd
	pd.dspOn();
	
	// start the sound stream - always do this last in your setup
	ofSoundStreamSetup(2, 0, this, 44100, ofxPd::getBlockSize()*ticksPerBuffer, 1);

}


void testApp::audioOut(float *output, int bufferSize, int numChannels) {
	pd.audioOut(output, bufferSize, numChannels);
}
//--------------------------------------------------------------
void testApp::update(){
	
	// this is where we're going to send messages to pd.
	// you could send it anywhere in the code, for instance,
	// in the mousePressed() method, but for now we'll just
	// do it in update.
	pd.sendFloat("frequency", (ofGetHeight() - mouseY) + 20);
	pd.sendFloat("volume", mouseX/(float)ofGetWidth());
	
	// also note, that you can send different kinds of messages 
	// (please see ofxPd.h for a list of all the messages you can send)
	// e.g.
	// for bangs:
	//     pd.sendBang("the-bang-name");
	//
	// for lists: (taken from ofxPd.h)
	//     pd.startList("test");	// "test" is the reciever name in pd
	//	   pd.addSymbol("hello");
	//     pd.addFloat(1.23);
	//     pd.finish();
	//
	// for midi messages:
	//	   pd.sendNote(pitch, velocity);
	//	   pd.sendCtl(controlNum, value);
	//
	// as mentioned before, please check ofxPd for a comprehensive list.

}

//--------------------------------------------------------------
void testApp::draw(){
	
	// don't worry about this, this is just drawing the axes and labels
	ofSetHexColor(0);
	
	glPushMatrix();
	glTranslatef(ofGetWidth()/2, ofGetHeight()/2, 0);
	ofLine(-100, 0, 100, 0);
	ofLine(0, -100, 0, 100);
	ofDrawBitmapString("Louder", 110, 3);
	ofDrawBitmapString("Quieter", -170, 3);
	ofDrawBitmapString("Higher", -20, -110);
	ofDrawBitmapString("Lower", -20, 110);
	glPopMatrix();
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