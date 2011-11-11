#pragma once

#include "ofMain.h"
#include "ofxPd.h"

// note here that I've added the bit ", public ofxPdListener" before the {
// this makes your test app a type of ofxPdListener, which means you can
// implement the callbacks listed in ofxPdListener.h
// such as:
//     floatReceived()
//     bangReceived()
//     listReceived() 
// etc. They are all optional.

class testApp : public ofBaseApp, public ofxPdListener {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		// the puredata instance
		ofxPd pd;
	
		// the audio callbacks
		void audioIn(float *input, int bufferSize, int numChannels);
		void audioOut(float *output, int bufferSize, int numChannels);

		// float send callback
		void floatReceived(const string& dest, float value);
		
		// a variable to store the "amplitude" send from the pd patch
		float amplitude;
};
