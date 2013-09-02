#include "ofxAELayer.h"
#include "ofGraphics.h"
#include "ofxAELayerHelper.h"
#include "ofxAEMask.h"

namespace ofxAE {
void Layer::update()
{
	if(isDirty()) {
		refreshMatrix();
	}
	for(vector<LayerHelper_*>::iterator helper = helper_.begin(); helper != helper_.end(); ++helper) {
		(*helper)->update();
	}
}

void Layer::draw()
{
	pushMatrix();
	render();
	popMatrix();
}
void Layer::render()
{
	for(vector<LayerHelper_*>::iterator helper = helper_.begin(); helper != helper_.end(); ++helper) {
		(*helper)->render();
	}
}

void Layer::setOrientation(const ofVec3f& orientation)
{
	switch(getRotationOrder()) {
		case ROTATION_ORDER_XYZ:
			TransformNode::setOrientation(orientation.x,ofVec3f(1,0,0),
										  orientation.y,ofVec3f(0,1,0),
										  orientation.z,ofVec3f(0,0,1));
			break;
		case ROTATION_ORDER_YZX:
			TransformNode::setOrientation(orientation.y,ofVec3f(0,1,0),
										  orientation.z,ofVec3f(0,0,1),
										  orientation.x,ofVec3f(1,0,0));
			break;
		case ROTATION_ORDER_ZXY:
			TransformNode::setOrientation(orientation.z,ofVec3f(0,0,1),
										  orientation.x,ofVec3f(1,0,0),
										  orientation.y,ofVec3f(0,1,0));
			break;
		case ROTATION_ORDER_XZY:
			TransformNode::setOrientation(orientation.x,ofVec3f(1,0,0),
										  orientation.z,ofVec3f(0,0,1),
										  orientation.y,ofVec3f(0,1,0));
			break;
		case ROTATION_ORDER_YXZ:
			TransformNode::setOrientation(orientation.y,ofVec3f(0,1,0),
										  orientation.x,ofVec3f(1,0,0),
										  orientation.z,ofVec3f(0,0,1));
			break;
		case ROTATION_ORDER_ZYX:
			TransformNode::setOrientation(orientation.z,ofVec3f(0,0,1),
										  orientation.y,ofVec3f(0,1,0),
										  orientation.x,ofVec3f(1,0,0));
			break;
	}
}

void Layer::resetPropertyFrame()
{
	for(vector<PropertyBase_*>::iterator prop = property_.begin(); prop != property_.end(); ++prop) {
		(*prop)->resetFrame();
	}
}
void Layer::setPropertyFrame(int frame)
{
	for(vector<PropertyBase_*>::iterator prop = property_.begin(); prop != property_.end(); ++prop) {
		(*prop)->setFrame(frame);
	}
	for(vector<LayerHelper_*>::iterator helper = helper_.begin(); helper != helper_.end(); ++helper) {
		(*helper)->setPropertyFrame(frame);
	}
}

}
/* EOF */