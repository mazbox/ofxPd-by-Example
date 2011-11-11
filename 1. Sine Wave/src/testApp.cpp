#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	// puredata works on sounds in chunks of 64 samples (called a tick)
	// 8 ticks per buffer corresponds to 8 * 64 sample buffer size (512 samples)
	int ticksPerBuffer = 8;
	pd.init(2, 0, 44100, ticksPerBuffer);
	
	// open the patch (relative to the data folder)
	pd.openPatch("sineWave.pd");
	
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

}

//--------------------------------------------------------------
void testApp::draw(){

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