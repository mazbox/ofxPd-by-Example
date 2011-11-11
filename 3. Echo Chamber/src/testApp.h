#pragma once

#include "ofMain.h"
#include "ofxPd.h"

class testApp : public ofBaseApp{

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
};
