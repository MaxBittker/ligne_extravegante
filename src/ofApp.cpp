#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------

ofColor topColor = ofColor::fromHex(0x0B1021);
ofColor bottomColor = ofColor::fromHex(0x131E53);
void ofApp::draw(

) {

  ofBackgroundHex(0xACB7EA);

  float w = (750 - 50) / 5.0;
  float h = (750 - 50) / 5.0;

  ofSeedRandom(mouseX * 1000);
  ofPoint startPoint = ofPoint(mouseX, mouseY);
  //   float x = 200;
  //   float y = 200;
  float stripWidth = 50;

  float length = 3000;
  float angleRange = 80;

  float previousAngle = ofRandom(0, 360); // degrees
  float currentAngle = previousAngle;
  float nextAngle = previousAngle;

  // float previousAngle = angle;

  int side = 0;
  while (true) {

    float stripLength = stripWidth + ofRandom(0, 100);

    length -= stripLength;
    // cout << length << "\n";
    if (length < 0) {
      break;
    }
    if (side == 0) {
      ofSetColor(topColor, 200); // top
    } else {
      ofSetColor(bottomColor, 200); // bottom
    }
    side = (side + 1) % 2;

    // calculate next angle
    nextAngle = currentAngle + ((ofRandomf() * angleRange) - angleRange / 2);

    float foldAngle = (nextAngle + currentAngle) / 2.0;
    float prevFoldAngle = (currentAngle + previousAngle) / 2.0;

    ofVec2f angleVec = ofVec2f(1, 0).getRotated(nextAngle);
    ofVec2f angleVecPerp = angleVec.getPerpendicular();

    ofVec2f prevAngleVec = ofVec2f(1, 0).getRotated(previousAngle);
    ofVec2f prevAngleVecPerp = angleVec.getPerpendicular();

    ofVec2f foldAngleVecPerp =
        ofVec2f(1, 0).getRotated(foldAngle).getPerpendicular();

    ofVec2f prevFoldAngleVecPerp =
        ofVec2f(1, 0).getRotated(prevFoldAngle).getPerpendicular();

    ofPoint endPoint = startPoint + stripLength * angleVec;

    // cout << prevFoldAngle << "\n";

    float hypotenuseStart =
        (stripWidth / 2) / cos(ofDegToRad(prevFoldAngle - previousAngle));
    float hypotenuseEnd =
        (stripWidth / 2) / cos(ofDegToRad(foldAngle - currentAngle));

    ofPoint leftStart = startPoint - prevFoldAngleVecPerp * hypotenuseStart;
    ofPoint rightStart = startPoint + prevFoldAngleVecPerp * hypotenuseStart;

    ofPoint leftEnd = endPoint - foldAngleVecPerp * hypotenuseEnd;
    ofPoint rightEnd = endPoint + foldAngleVecPerp * hypotenuseEnd;

    ofBeginShape();

    ofVertex(leftStart);
    ofVertex(leftEnd);

    ofVertex(rightEnd);
    ofVertex(rightStart);
    ofEndShape();

    ofSetColor(255);
    // ofDrawLine(leftStart, leftEnd);
    // ofDrawLine(rightStart, rightEnd);
    // ofDrawLine(startPoint, endPoint);

    // advance
    startPoint = endPoint;

    previousAngle = currentAngle;
    currentAngle = nextAngle;

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
