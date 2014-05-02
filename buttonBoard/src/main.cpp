#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

	ofSetupOpenGL(768,768, OF_WINDOW);
	// we do want a square app right? Cause generated music is square!
	ofRunApp( new ofApp());

}
