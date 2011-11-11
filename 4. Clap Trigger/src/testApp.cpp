#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	// puredata works on sounds in chunks of 64 samples (called a tick)
	// 8 ticks per buffer corresponds to 8 * 64 sample buffer size (512 samples)
	int ticksPerBuffer = 8;
	
	// this initialized pd

	// note that in this example, even though we're not using the audio output
	// you still have to call pd.audioOut to get ofxPd to process the audio,
	// so we'll set ofxPd up with stereo out.
	pd.init(2, 1, 44100, ticksPerBuffer);
	
	// open the patch (relative to the data folder)
	pd.openPatch("claptrigger.pd");
	
	// start pd
	pd.dspOn();
	
	
	// this adds your testApp as a listener
	pd.addListener(*this);
	
	
	// add all the sends you want to listen to here
	pd.addSource("amplitude");
	
	// more here, e.g.
	// pd.addSource("anotherone");
	
	// you must call this at the end of your list of sends you want to listen to.
	pd.subscribe(*this);
	
	// start the sound stream - always do this last in your setup
	ofSoundStreamSetup(2, 1, this, 44100, ofxPd::getBlockSize()*ticksPerBuffer, 1);

}



void testApp::audioIn(float *input, int bufferSize, int numChannels) {
	pd.audioIn(input, bufferSize, numChannels);
}


// even though we don't need any audio out, ofxPd doesn't run unless 
// pd.audioOut is called. It will output silence if you don't have 
// a dac~ in your patch.
void testApp::audioOut(float *output, int bufferSize, int numChannels) {
	pd.audioOut(output, bufferSize, numChannels);
}

// float send callback - this gets called every time a message is sent
// that has a float type, that you've registered for in setup()
void testApp::floatReceived(const string& dest, float value) {

	// dest is the send name, so here we test to see if it's the amplitude
	// (although we don't really need to because it's the only one that's 
	// being sent).
	if(dest=="amplitude") {
		amplitude = value;
	}
}
//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(amplitude, amplitude, amplitude);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	ofSetHexColor(0);
	ofDrawBitmapString("Clap Trigger\n============\nClap to see the screen\nget brighter", 10, 20);
	
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