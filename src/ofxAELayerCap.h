#pragma once

#include "ofxAEDef.h"

OFX_AE_NAMESPACE_BEGIN

class Layer;

class LayerCap
{
public:
	LayerCap(Layer *layer);
	virtual ~LayerCap();
	virtual void update(){}
	virtual void draw(float alpha=1){}
protected:
	Layer *layer_;
	int start_frame_;
};


OFX_AE_NAMESPACE_END

/* EOF */