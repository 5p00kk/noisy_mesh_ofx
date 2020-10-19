#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    /* Place camera */
    cam.setDistance(100);
    /* Triangle mesh */
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);

    /* Add mesh vertice, centered at 0 */
    for (int x = 0; x < mesh_size; x++)
    {
        for (int y = 0; y < mesh_size; y++)
        {
            mesh.addVertex(ofPoint(x - (mesh_size/2), (y - (mesh_size/2))));
            mesh.addColor(ofFloatColor(1.0, 1.0, 1.0));
        }
    }
    /* Add vertices connections */
    for (int x = 0; x < mesh_size - 1; x++)
    {
        for (int y = 0; y < mesh_size - 1; y++)
        {
            mesh.addIndex(x + y * mesh_size);
            mesh.addIndex((x + 1) + y * mesh_size);
            mesh.addIndex(x + (y + 1) * mesh_size);
            mesh.addIndex((x + 1) + y * mesh_size);
            mesh.addIndex((x + 1) + (y + 1) * mesh_size);
            mesh.addIndex(x + (y + 1) * mesh_size);
        }
    }

    /* Open Kinect */
    ofxKinectV2 tmp_kinect;
    std::vector<ofxKinectV2::KinectDeviceInfo> device_list = tmp_kinect.getDeviceList();
    if(device_list.size() == 0)
        std::cout << "setup: ERROR: No kinect found\n";
    if(kinect.open(device_list[0].serial))
        std::cout << "setup: SUCCESS: Kinect opened\n";
    else
        std::cout << "setup: ERROR: Kinect not opened\n";
}

//--------------------------------------------------------------
void ofApp::update()
{
    for (int idx = 0; idx < mesh_size*mesh_size; idx++)
    {
        float perlin_noise = ofNoise(idx, ofGetElapsedTimef());
        ofVec3f position = mesh.getVertex(idx);
        position.z = ofMap(perlin_noise, 0, 1, 0, 20);
        mesh.setVertex(idx, position);
        mesh.setColor(idx, ofFloatColor(perlin_noise, 0, 0));
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofPushMatrix();
    cam.begin();
    ofSetColor(255);
    mesh.drawWireframe();
    cam.end();
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{ 

}
