#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	// puredata works on sounds in chunks of 64 samples (called a tick)
	// 8 ticks per buffer corresponds to 8 * 64 sample buffer size (512 samples)
	int ticksPerBuffer = 8;
	
	// note here we've changed the number of inputs (second parameter) to 1.
	pd.init(2, 1, 44100, ticksPerBuffer);
	
	// open the patch (relative to the data folder)
	pd.openPatch("echochamber.pd");
	
	// start pd
	pd.dspOn();
	
	// start the sound stream - always do this last in your setup
	// note that this time, the number of inputs (second parameter) is now 1.
	ofSoundStreamSetup(2, 1, this, 44100, ofxPd::getBlockSize()*ticksPerBuffer, 1);

}

// this is how you get audio into pd
void testApp::audioIn(float *input, int bufferSize, int numChannels) {
	pd.audioIn(input, bufferSize, numChannels);
}


// this is where the openframeworks sound stream connects to ofxPd
// it's also where the audio processing is done
void testApp::audioOut(float *output, int bufferSize, int numChannels) {
	pd.audioOut(output, bufferSize, numChannels);
}
//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetHexColor(0);
	ofDrawBitmapString("Echo Chamber", 10, 20);
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