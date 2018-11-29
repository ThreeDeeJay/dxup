#pragma once

#include "d3d9_base.h"
#include "d3d9_device.h"

namespace dxapex {

  template <typename... Base>
  class D3D9DeviceUnknown : public Unknown<Base...> {

  public:

    D3D9DeviceUnknown(Direct3DDevice9Ex* device)
      : m_device{device} {}

    HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice9** ppDevice) override {
      if (!ppDevice)
        return D3DERR_INVALIDCALL;
      
      *ppDevice = ref( static_cast<IDirect3DDevice9Ex*>(m_device) );
      return D3D_OK;
    }

  protected:
    Direct3DDevice9Ex* m_device;
  };

}