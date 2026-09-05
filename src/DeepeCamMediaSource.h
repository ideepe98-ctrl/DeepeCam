#pragma once

#include "DeepeCamMediaSource.h"

class DeepeCamFactory
{
public:
    static HRESULT CreateInstance(
        REFIID riid,
        void** ppv);
};
