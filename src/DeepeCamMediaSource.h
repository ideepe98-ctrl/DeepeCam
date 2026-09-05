#pragma once

#include <windows.h>
#include <unknwn.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mfobjects.h>

class DeepeCamMediaSource : public IMFMediaSource
{
public:
    DeepeCamMediaSource();
    virtual ~DeepeCamMediaSource();

    STDMETHODIMP QueryInterface(REFIID riid, void** ppv) override;
    STDMETHODIMP_(ULONG) AddRef() override;
    STDMETHODIMP_(ULONG) Release() override;

    STDMETHODIMP GetEvent(DWORD flags, IMFMediaEvent** event) override;
    STDMETHODIMP BeginGetEvent(IMFAsyncCallback* callback, IUnknown* state) override;
    STDMETHODIMP EndGetEvent(IMFAsyncResult* result, IMFMediaEvent** event) override;
    STDMETHODIMP QueueEvent(
        MediaEventType met,
        REFGUID extendedType,
        HRESULT status,
        const PROPVARIANT* value) override;

    STDMETHODIMP GetCharacteristics(DWORD* characteristics) override;
    STDMETHODIMP CreatePresentationDescriptor(
        IMFPresentationDescriptor** descriptor) override;
    STDMETHODIMP Start(
        IMFPresentationDescriptor* descriptor,
        const GUID* timeFormat,
        const PROPVARIANT* startPosition) override;
    STDMETHODIMP Stop() override;
    STDMETHODIMP Pause() override;
    STDMETHODIMP Shutdown() override;

private:
    long m_refCount = 1;
};
