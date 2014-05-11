#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    framerate=60.0;
    ofSetFrameRate(framerate);
    bb.setup();
    s.setup();
    gp.setup();

    // set initial sample
    setNewSample(gp.getNext());

}

//--------------------------------------------------------------
void ofApp::update(){
    bb.update(1.0/framerate);
    s.update();
    if (bb.newCol()) {
        s.play(bb.getActiveCol());
    }
    if (bb.getCount()>1) {
        setNewSample(gp.getNext());
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    bb.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (button==0) {
            bb.mousePressed(x,y,button);
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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

void ofApp::setNewSample(Individual in)
{
    int64_t dna[BB_COLS];
    for (int i=0; i<BB_COLS; i++){
        dna[i]=in.dna[i%IND_SIZE];
    }
    bb.setSample(dna);
}
