#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    framerate=60.0;
    ofSetFrameRate(framerate);
    bb.setup();
    s.setup();
    gp.setup();
    slider.setup(new ofPoint(10,100));
    font.loadFont("FiraSansOT-Light.otf",18);

    // set initial sample
    in=gp.getNext();
    setNewSample(in);

}

//--------------------------------------------------------------
void ofApp::update(){
    bb.update(1.0/framerate);
    s.update();
    if (bb.newCol()) {
        s.play(bb.getActiveCol());
    }
    if (bb.getCount()>0) {
        in.addScore(slider.getValue());
        in=gp.getNext();
        setNewSample(in);
        slider.setValue(0);
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    bb.draw();
    char s[255];
    sprintf(s,"Generation: %u\nIndividual: %u",gp.generation,gp.icount);
    font.drawString(s,10,30);
    slider.draw();
    ofPushMatrix();
    ofTranslate(65,260);
    ofRotate(90);
    font.drawString("Score",0,0);
    ofPopMatrix();
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
    slider.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    slider.mousePressed(x,y,button);
   /* if (button==0) {
            bb.mousePressed(x,y,button);
    } */


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
