
#if WINDOWS
#include <stdbool.h>

#include <windows.h>
#define COBJMACROS
#include "dxgi1_6.h"
//#include "dxgi.h"
//#include "D3DX12.h"
#include "D3d12.h"
#include "D3DCompiler.h"
#pragma comment (lib, "dxguid.lib")

bool EnableDebugLayer(){
#if defined(_DEBUG)
	// Always enable the debug layer before doing anything DX12 related
	// so all possible errors generated while creating DX12 objects
	// are caught by the debug layer.
	ID3D12Debug* debugInterface;
	D3D12GetDebugInterface(IID_PPV_ARGS(&debugInterface));
	if (!debugInterface)
	{
		ASSERT(false);
	}
	debugInterface->EnableDebugLayer();
#endif
	return true;
}

IDXGIAdapter4* GetAdapter(bool useWarp)
{
	IDXGIFactory4* dxgifactory;
	UINT create_fac_flags = 0;
#if defined(_DEBUG)
	//create_fac_flags = DXGI_CREATE_FACTORY_DEBUG;
#endif

	CreateDXGIFactory2(create_fac_flags,&IID_IDXGIFactory4, (void**)&dxgifactory);
	IDXGIAdapter1* dxgi_adapter1;
	IDXGIAdapter4* dxgi_adapter4;

	if (useWarp)
	{
		//NEVER
		//dxgifactory->EnumWarpAdapter(IID_PPV_ARGS(&dxgi_adapter1));
		//dxgi_adapter4 = (IDXGIAdapter4*)dxgi_adapter1;
		//dxgi_adapter1->As(&dxgi_adapter4);
	}
	else
	{
		SIZE_T maxDedicatedVideoMemory = 0;
		for (UINT i = 0; IDXGIFactory4_EnumAdapters1(dxgifactory,i, &dxgi_adapter1) != DXGI_ERROR_NOT_FOUND; ++i)
		{
			DXGI_ADAPTER_DESC1 dxgiAdapterDesc1;
			IDXGIAdapter1_GetDesc1(dxgi_adapter1, &dxgiAdapterDesc1);
			//dxgi_adapter1->GetDesc1(&dxgiAdapterDesc1);

			// Check to see if the adapter can create a D3D12 device without actually 
			// creating it. The adapter with the largest dedicated video memory
			// is favored.
			if ((dxgiAdapterDesc1.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) == 0 && 
					SUCCEEDED(
						D3D12CreateDevice(
							NULL,
							D3D_FEATURE_LEVEL_11_0, 
							&IID_ID3D12Device, 
							NULL)) &&
					dxgiAdapterDesc1.DedicatedVideoMemory > maxDedicatedVideoMemory)
			{
				maxDedicatedVideoMemory = dxgiAdapterDesc1.DedicatedVideoMemory;
				dxgi_adapter4 = (IDXGIAdapter4*)dxgi_adapter1;
			}
		}
	}
	return dxgi_adapter4;
}

ID3D12Device2* CreateDevice(IDXGIAdapter4* adapter){
        
#if USE_DEBUG_LAYER
        EnableDebugLayer();
#endif
        ID3D12Device2* d3d12Device2;
        //D3D12CreateDevice(adapter, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&d3d12Device2));
		//
        
        HRESULT WINAPI D3D12CreateDevice(
			_In_opt_  IUnknown          *pAdapter,
			D3D_FEATURE_LEVEL MinimumFeatureLevel,
			_In_      REFIID            riid,
			_Out_opt_ void              **ppDevice
            );
        
        // Enable debug messages in debug mode.
#if USE_DEBUG_LAYER
        ID3D12InfoQueue* pInfoQueue;
        HRESULT result = d3d12Device2->QueryInterface(&pInfoQueue);
        if (SUCCEEDED(result))
        {
            pInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_CORRUPTION, TRUE);
            pInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_ERROR, TRUE);
            pInfoQueue->SetBreakOnSeverity(D3D12_MESSAGE_SEVERITY_WARNING, TRUE);
            // Suppress whole categories of messages
            //D3D12_MESSAGE_CATEGORY Categories[] = {};
            
            // Suppress messages based on their severity level
            D3D12_MESSAGE_SEVERITY Severities[] =
            {
                D3D12_MESSAGE_SEVERITY_INFO
            };
            
            // Suppress individual messages by their ID
            D3D12_MESSAGE_ID DenyIds[] = {
                D3D12_MESSAGE_ID_CLEARRENDERTARGETVIEW_MISMATCHINGCLEARVALUE,   // I'm really not sure how to avoid this message.
                D3D12_MESSAGE_ID_MAP_INVALID_NULLRANGE,                         // This warning occurs when using capture frame while graphics debugging.
                D3D12_MESSAGE_ID_UNMAP_INVALID_NULLRANGE,                       // This warning occurs when using capture frame while graphics debugging.
            };
            
            D3D12_INFO_QUEUE_FILTER NewFilter = {};
            //NewFilter.DenyList.NumCategories = _countof(Categories);
            //NewFilter.DenyList.pCategoryList = Categories;
            NewFilter.DenyList.NumSeverities = _countof(Severities);
            NewFilter.DenyList.pSeverityList = Severities;
            NewFilter.DenyList.NumIDs = _countof(DenyIds);
            NewFilter.DenyList.pIDList = DenyIds;
            
            pInfoQueue->PushStorageFilter(&NewFilter);
        }
        else
        {
            ASSERT(false);
        }
#endif
        return d3d12Device2;
    }
#endif

