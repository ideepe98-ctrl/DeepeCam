
#include "DeepeCamMediaStream.h"

DeepeCamMediaStream::DeepeCamMediaStream()
{
}

DeepeCamMediaStream::~DeepeCamMediaStream()
{
}

STDMETHODIMP DeepeCamMediaStream::QueryInterface(
    REFIID riid,
    void** ppv)
{
    if (!ppv)
        return E_POINTER;

    *ppv = nullptr;

    if (riid == IID_IUnknown ||
        riid == IID_IMFMediaEventGenerator ||
        riid == IID_IMFMediaStream)
    {
        *ppv = static_cast<IMFMediaStream*>(this);
        AddRef();
        return S_OK;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) DeepeCamMediaStream::AddRef()
{
    return static_cast<ULONG>(
        InterlockedIncrement(&m_refCount));
}

STDMETHODIMP_(ULONG) DeepeCamMediaStream::Release()
{
    ULONG count = static_cast<ULONG>(
        InterlockedDecrement(&m_refCount));

    if (count == 0)
        delete this;

    return count;
}

STDMETHODIMP DeepeCamMediaStream::GetEvent(
    DWORD,
    IMFMediaEvent**)
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaStream::BeginGetEvent(
    IMFAsyncCallback*,
    IUnknown*)
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaStream::EndGetEvent(
    IMFAsyncResult*,
    IMFMediaEvent**)
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaStream::QueueEvent(
    MediaEventType,
    REFGUID,
    HRESULT,
    const PROPVARIANT*)
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaStream::GetMediaSource(
    IMFMediaSource**)
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaStream::GetStreamDescriptor(
    IMFStreamDescriptor**)
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaStream::RequestSample(
    IUnknown*)
{
    return E_NOTIMPL;
}
