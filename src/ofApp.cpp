#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw(

) {

  ofBackgroundHex(0xACB7EA);

  float w = (750 - 50) / 5.0;
  float h = (750 - 50) / 5.0;

  ofSeedRandom(mouseX * 1000);
  ofPoint startPoint = ofPoint(ofGetWidth() / 2, ofGetHeight() / 2);
  //   float x = 200;
  //   float y = 200;
  float stripWidth = 50;

  float length = 3000;
  float angleRange = 80;

  float angle = 0; // degrees
  int side = 0;
  while (true) {

    float stripLength = stripWidth + ofRandom(0, 200);

    length -= stripLength;
    // cout << length << "\n";
    if (length < 0) {
      break;
    }
    if (side == 0) {
      ofSetHexColor(0x0B1021); // top
    } else {
      ofSetHexColor(0x131E53); // bottom
    }
    side = (side + 1) % 2;

    // update the angle
    angle = angle + ((random() * angleRange) - angleRange / 2);
    // direction = ofVect2
    ofVec2f angleVec = ofVec2f(1, 0).getRotated(angle);
    ofVec2f angleVecPerp = angleVec.getPerpendicular();
    ofPoint endPoint = startPoint + stripLength * angleVec;
    // float endY = y;

    ofDrawLine(startPoint, endPoint);

    ofPoint leftStart = startPoint - angleVecPerp * stripWidth / 2;
    ofPoint leftEnd = endPoint - angleVecPerp * stripWidth / 2;

    ofPoint rightStart = startPoint + angleVecPerp * stripWidth / 2;
    ofPoint rightEnd = endPoint + angleVecPerp * stripWidth / 2;

    ofDrawLine(leftStart, leftEnd);
    ofDrawLine(rightStart, rightEnd);

    ofBeginShape();

    ofVertex(leftStart);
    ofVertex(leftEnd);

    ofVertex(rightEnd);
    ofVertex(rightStart);
    ofEndShape();

    startPoint = endPoint;

    // float rectWidth = ofMap(k, 0, 10, 8, w);

    // if (ofRandom(0, 1) < .99) {
    //   ofDrawRectangle(x + w / 2, y + h / 2, rectWidth, rectWidth);
    // }
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
