#pragma once

#include "util/mtx.h"
#include "render/LayerAGL.h"

class ObjLayerRenderer;

class ObjLayer : public LayerAgl 
{
public:
    class Node : public LayerAgl::Node 
    {
        SEAD_RTTI_OVERRIDE(Node, LayerAgl::Node)

    public:
        virtual void CalcView(s32 viewIndex, const Mtx34& cameraMtx, const Mtx44& deviceProjectionMtx, ObjLayerRenderer* renderer) = 0;
        virtual void vf2C(s32 viewIndex, const Mtx34& cameraMtx, const Mtx44& deviceProjectionMtx, ObjLayerRenderer* renderer) = 0;
        virtual void drawAllShapes1(s32 viewIndex, const Mtx34& cameraMtx, const Mtx44& deviceProjectionMtx, ObjLayerRenderer* renderer) = 0;
        virtual void drawAllShapes2(s32 viewIndex, const Mtx34& cameraMtx, const Mtx44& deviceProjectionMtx, ObjLayerRenderer* renderer) = 0;
        virtual void drawShadowCastShapes(s32 viewIndex, const Mtx34& cameraMtx, const Mtx44& deviceProjectionMtx, ObjLayerRenderer* renderer) { }
        virtual void drawReflectionShapes1(s32 viewIndex, const Mtx34& cameraMtx, const Mtx44& deviceProjectionMtx, ObjLayerRenderer* renderer) { }
        virtual void drawReflectionShapes2(s32 viewIndex, const Mtx34& cameraMtx, const Mtx44& deviceProjectionMtx, ObjLayerRenderer* renderer) { }
        virtual bool hasShadowCastShapes() const { return false; }
    };

public:
    ObjLayer();
    virtual ~ObjLayer();

    // ...

    u8 _420[0x42C - 0x420];
};