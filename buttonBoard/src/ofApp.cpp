#include "ofApp.h"
#include <ofxTonic.h>

ofxTonicSynth synth = ofxTonicSynth();
//--------------------------------------------------------------
void ofApp::setup(){
    ofSoundStre6amSetup(2, 0, this, 44100, 256, 4);
    SineWave tone = SineWave();
    SineWave vibratoOsc = SineWave();
    vibratoOsc.freq(10);
    float basePitch = 400;
    Generator frequency = basePitch + (vibratoOsc * basePitch * 0.01);
    tone.freq(frequency);

    cout << "foo" << endl;
    synth.setOutputGen( tone );
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofCircle(20,20,10);

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

void ofApp::audioOutput(float * output, int bufferSize, int nChannels){
    cout << bufferSize << endl;
  synth.fillBufferOfFloats(output, bufferSize, nChannels);
}
