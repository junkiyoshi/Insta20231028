#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofNoFill();
	ofSetLineWidth(1);
	ofEnableDepthTest();

	this->frame.setMode(ofPrimitiveMode::OF_PRIMITIVE_LINES);
}

//--------------------------------------------------------------
void ofApp::update() {


}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofSeedRandom(39);

	this->frame.clear();
	auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));

	for (int len = 100; len <= 350; len += 30) {

		auto noise_x = ofNoise(noise_seed.x, len * -0.00015 + ofGetFrameNum() * 0.01);
		auto noise_y = ofNoise(noise_seed.y, len * -0.00015 + ofGetFrameNum() * 0.01);
		auto noise_z = ofNoise(noise_seed.z, len * -0.00015 + ofGetFrameNum() * 0.01);

		if (noise_x < 0.2) { noise_x = 0; }
		else if (noise_x < 0.4) { noise_x = ofMap(noise_x, 0.2, 0.4, 0, 0.5); }
		else if (noise_x < 0.6) { noise_x = 0.5; }
		else if (noise_x < 0.8) { noise_x = ofMap(noise_x, 0.6, 0.8, 0.5, 1.0); }
		else { noise_x = 1; }

		if (noise_y < 0.2) { noise_y = 0; }
		else if (noise_y < 0.4) { noise_y = ofMap(noise_y, 0.2, 0.4, 0, 0.5); }
		else if (noise_y < 0.6) { noise_y = 0.5; }
		else if (noise_y < 0.8) { noise_y = ofMap(noise_y, 0.6, 0.8, 0.5, 1.0); }
		else { noise_y = 1; }

		if (noise_z < 0.2) { noise_z = 0; }
		else if (noise_z < 0.4) { noise_z = ofMap(noise_z, 0.2, 0.4, 0, 0.5); }
		else if (noise_z < 0.6) { noise_z = 0.5; }
		else if (noise_z < 0.8) { noise_z = ofMap(noise_z, 0.6, 0.8, 0.5, 1.0); }
		else { noise_z = 1; }

		auto angle_x = ofMap(noise_x, 0, 1, -90, 90);
		auto angle_y = ofMap(noise_y, 0, 1, -90, 90);
		auto angle_z = ofMap(noise_z, 0, 1, -90, 90);

		ofSetColor(239);

		ofPushMatrix();
		ofRotateZ(angle_z);
		ofRotateY(angle_y);
		ofRotateX(angle_x);

		ofNoFill();
		ofDrawBox(len);

		if (len == 100) {

			ofFill();
			ofSetColor(0);
			ofDrawBox(len);
		}

		ofPopMatrix();
	}


	this->frame.drawWireframe();

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}