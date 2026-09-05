#pragma once

#include <windows.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mfobjects.h>
#include <mftransform.h>

class DeepeCamMediaStream
{
public:
    DeepeCamMediaStream();
    ~DeepeCamMediaStream();

    HRESULT Initialize();
};
