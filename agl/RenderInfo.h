#pragma once

#include "types.h"

namespace sead 
{
    class Camera;
    class Projection;
    class Viewport;
}

namespace agl 
{
    class DisplayList;
    class RenderBuffer;

    namespace lyr 
    {
        class Layer;

        class RenderInfo 
        {
        public:
            u32 mRenderStepIdx;             // _0
            u32 mDisplayType;               // _4
            RenderBuffer* mFrameBuffer;     // _8
            u32 _C;
            Layer* mParentLayer;            // _C
            sead::Camera* mCamera;          // _10
            sead::Projection* mProjection;  // _14
            sead::Viewport* mViewport;      // _18
            DisplayList* mDisplayList;      // _1C
            bool _20;
        };
    };
};