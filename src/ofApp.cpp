#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
const bool debug = false;
const bool animation = true;
ofColor topColor = ofColor::fromHex(0x10163B);
ofColor bottomColor = ofColor::fromHex(0x182F63);

float intialLength = 3000;
double t = 0;
ofPoint Center = ofPoint(0, 0);

void ofApp::draw(

) {
  if (animation) {

    t += 0.001;
  }

  ofBackgroundHex(0xACB7EA);

  ofSeedRandom(mouseX * 1000);
  ofPoint startPoint = ofPoint(mouseX, mouseY);

  float stripWidth = 50;

  float length = 3000;
  int attempts = 0;
  // draw:

  float previousAngle = ofNoise(t) * 360; // degrees
  float currentAngle = previousAngle + 180;
  float nextAngle = previousAngle;

  // float previousAngle = angle;

  int side = 0;
  int n = 0;
  while (true) {

    // float stripLength = 25 + ofRandom(0, 200);
    float stripLength = 25 + (ofNoise((n * 0.3) + 1000, t) * 300);
    stripLength = min(length, stripLength);
    length -= stripLength;
    // cout << length << "\n";

    if (side == 0) {
      ofSetColor(topColor, 250); // top
    } else {
      ofSetColor(bottomColor, 250); // bottom
    }
    side = (side + 1) % 2;

    // calculate next angle
    // float angleOffset = ofRandom(90, 160) * (ofRandomf() > 0 ? -1 : 1);
    float angleOffset = ((ofRandom(0, 40) + ofNoise(n * 0.3, t) * 30) + 90) *
                        (ofRandomf() > 0 ? -1 : 1);

    nextAngle = currentAngle + angleOffset;
    nextAngle = ofWrapDegrees(nextAngle);
    // cout << angleOffset << "\n";

    if (length <= 0) {
      nextAngle = currentAngle + 180;
    }

    ofVec2f angleVec = ofVec2f(1, 0).getRotated(currentAngle);
    ofVec2f angleVecPerp = angleVec.getPerpendicular();

    // ofVec2f prevAngleVec = ofVec2f(1, 0).getRotated(previousAngle);
    // ofVec2f prevAngleVecPerp = prevAngleVec.getPerpendicular();

    float foldAngle = (nextAngle + currentAngle) / 2.0;
    foldAngle += 90;
    float prevFoldAngle = (currentAngle + previousAngle) / 2.0;
    prevFoldAngle += 90;

    ofVec2f foldAngleVecPerp =
        ofVec2f(1, 0).getRotated(foldAngle).getPerpendicular();

    ofVec2f prevFoldAngleVecPerp =
        ofVec2f(1, 0).getRotated(prevFoldAngle).getPerpendicular();

    ofPoint endPoint = startPoint + stripLength * angleVec;
    ofRectangle BoundingBox = ofRectangle(0, 0, ofGetWidth(), ofGetHeight());
    if (!BoundingBox.inside(endPoint) && attempts++ < 100) {

      // goto draw;
    }

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
    ofVertex(rightEnd);

    ofVertex(leftEnd);

    ofVertex(rightStart);

    ofEndShape();
    ofSetColor(topColor);
    ofDrawLine(leftStart, rightEnd);
    ofSetColor(bottomColor);
    ofDrawLine(rightStart, leftEnd);

    if (debug) {

      ofSetColor(255);

      ofDrawLine(startPoint + angleVecPerp * stripWidth / 2,
                 endPoint + angleVecPerp * stripWidth / 2);
      ofDrawLine(startPoint - angleVecPerp * stripWidth / 2,
                 endPoint - angleVecPerp * stripWidth / 2);

      ofSetColor(100);

      ofDrawLine(startPoint, endPoint);

      ofSetColor(220, 20, 200);

      ofDrawLine(endPoint + foldAngleVecPerp * stripWidth,
                 endPoint - foldAngleVecPerp * stripWidth);

      // ofSetColor(20, 20, 250);

      // ofDrawLine(startPoint + foldAngleVecPerp * stripWidth,
      //            startPoint - foldAngleVecPerp * stripWidth);
    }

    // advance
    startPoint = endPoint;

    previousAngle = currentAngle;
    currentAngle = nextAngle;
    n++;
    if (length <= 0) {
      break;
    }
  }
  ofPopMatrix();
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
