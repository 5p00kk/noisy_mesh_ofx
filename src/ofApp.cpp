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
}

//--------------------------------------------------------------
void ofApp::update()
{

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
