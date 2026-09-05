#include "DeepeCamMediaSource.h"

DeepeCamMediaSource::DeepeCamMediaSource()
{
}

DeepeCamMediaSource::~DeepeCamMediaSource()
{
}

STDMETHODIMP DeepeCamMediaSource::QueryInterface(
    REFIID riid,
    void** ppv)
{
    if (!ppv)
        return E_POINTER;

    *ppv = nullptr;

    if (riid == IID_IUnknown ||
        riid == IID_IMFMediaEventGenerator ||
        riid == IID_IMFMediaSource)
    {
        *ppv = static_cast<IMFMediaSource*>(this);
        AddRef();
        return S_OK;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) DeepeCamMediaSource::AddRef()
{
    return static_cast<ULONG>(
        InterlockedIncrement(&m_refCount));
}

STDMETHODIMP_(ULONG) DeepeCamMediaSource::Release()
{
    ULONG count = static_cast<ULONG>(
        InterlockedDecrement(&m_refCount));

    if (count == 0)
        delete this;

    return count;
}

STDMETHODIMP DeepeCamMediaSource::GetEvent(
    DWORD,
    IMFMediaEvent**)
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaSource::BeginGetEvent(
    IMFAsyncCallback*,
    IUnknown*)
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaSource::EndGetEvent(
    IMFAsyncResult*,
    IMFMediaEvent**)
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaSource::QueueEvent(
    MediaEventType,
    REFGUID,
    HRESULT,
    const PROPVARIANT*)
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaSource::GetCharacteristics(
    DWORD* characteristics)
{
    if (!characteristics)
        return E_POINTER;

    *characteristics = MFMEDIASOURCE_IS_LIVE;
    return S_OK;
}

STDMETHODIMP DeepeCamMediaSource::CreatePresentationDescriptor(
    IMFPresentationDescriptor**)
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaSource::Start(
    IMFPresentationDescriptor*,
    const GUID*,
    const PROPVARIANT*)
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaSource::Stop()
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaSource::Pause()
{
    return E_NOTIMPL;
}

STDMETHODIMP DeepeCamMediaSource::Shutdown()
{
    return S_OK;
}
