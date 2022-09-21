
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

static bool CheckTearingSupport()
{
	BOOL allowTearing = FALSE;
	// Rather than create the DXGI 1.5 factory interface directly, we create the
	// DXGI 1.4 interface and query for the 1.5 interface. This is to enable the 
	// graphics debugging tools which will not support the 1.5 factory interface 
	// until a future update.
	IDXGIFactory4* factory4;
	if (SUCCEEDED(CreateDXGIFactory1(&IID_IDXGIFactory4,(void**)&factory4)))
	{
		IDXGIFactory5* factory5;
		HRESULT r = IDXGIFactory4_QueryInterface(factory4,&IID_IDXGIFactory5,(void**)&factory5);
		if (SUCCEEDED(r))
		{
			if (FAILED(IDXGIFactory5_CheckFeatureSupport(
							factory5,
							DXGI_FEATURE_PRESENT_ALLOW_TEARING,
							&allowTearing, sizeof(allowTearing))))
			{
				allowTearing = FALSE;
			}
		}
	}
	return allowTearing == TRUE;
}

ID3D12CommandQueue* CreateCommandQueue(ID3D12Device2* device, D3D12_COMMAND_LIST_TYPE type){
	ID3D12CommandQueue* d3d12CommandQueue;
	D3D12_COMMAND_QUEUE_DESC desc = {};
	desc.Type =     type;
	desc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;
	desc.Flags =    D3D12_COMMAND_QUEUE_FLAG_NONE;
	desc.NodeMask = 0;
	DWORD error = GetLastError();
	HRESULT r = ID3D12Device2_CreateCommandQueue(device, &desc, &IID_ID3D12CommandQueue, (void**)&d3d12CommandQueue);
	printf("CreateCommandQueue: %d", (int)r);
	if(!SUCCEEDED(r))
	{
		ASSERT(false);
	}
	error = GetLastError();
	/*
	   ID3D12CommandQueue* d3d12CommandQueue;
	   D3D12_COMMAND_QUEUE_DESC desc = {};
	   desc.Type = type;
	   desc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
	   desc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
	   DWORD error = GetLastError();
	   (device->CreateCommandQueue(&desc, IID_PPV_ARGS(&d3d12CommandQueue)));
	   error = GetLastError();
	   */
	return d3d12CommandQueue;
}

IDXGISwapChain4* CreateSwapChain(HWND hWnd,ID3D12CommandQueue* commandQueue,u32 width, u32 height, u32 bufferCount)
{
	IDXGISwapChain4* dxgiSwapChain4;
	IDXGIFactory4* dxgiFactory4;
	UINT createFactoryFlags = 0;
#if defined(_DEBUG)
	//createFactoryFlags = DXGI_CREATE_FACTORY_DEBUG;
#endif

	CreateDXGIFactory2(createFactoryFlags,&IID_IDXGIFactory4, (void**)&dxgiFactory4);
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
	swapChainDesc.Width = width;
	swapChainDesc.Height = height;
	swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.Stereo = FALSE;
	swapChainDesc.SampleDesc = (DXGI_SAMPLE_DESC){ 1, 0 };
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = bufferCount;
	swapChainDesc.Scaling = DXGI_SCALING_STRETCH;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.AlphaMode = DXGI_ALPHA_MODE_UNSPECIFIED;
	// It is recommended to always allow tearing if tearing support is available.
	swapChainDesc.Flags = CheckTearingSupport() ? DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING : 0;
	//ComPtr<IDXGISwapChain1> swapChain1;
	IDXGISwapChain1* swapChain1;

	//dxgiFactory4->lpVtbl->CreateSwapChainForHwnd(dxgiFactory4,commandQueue,hWnd,&swapChainDesc,NULL,NULL,&swapChain1);
	IDXGIFactory4_CreateSwapChainForHwnd(dxgiFactory4,(IUnknown*)commandQueue,hWnd,&swapChainDesc,NULL,NULL,&swapChain1);
/*	
	dxgiFactory4->CreateSwapChainForHwnd(
										  commandQueue,
										  hWnd,
										  &swapChainDesc,
										  nullptr,
										  nullptr,
										  &swapChain1);
										  */

	// Disable the Alt+Enter fullscreen toggle feature. Switching to fullscreen
	// will be handled manually.
	
	IDXGIFactory4_MakeWindowAssociation(dxgiFactory4, hWnd, DXGI_MWA_NO_ALT_ENTER);
	HRESULT result = IDXGISwapChain1_QueryInterface(swapChain1,&IID_IDXGISwapChain4,(void**)&dxgiSwapChain4);
	ASSERT(SUCCEEDED(result));
	return dxgiSwapChain4;
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
        HRESULT r = D3D12CreateDevice((IUnknown*)adapter, D3D_FEATURE_LEVEL_11_0,&IID_ID3D12Device2,(void**)&d3d12Device2);
		ASSERT(SUCCEEDED(r));

/*        
        HRESULT r  = D3D12CreateDevice(
			_In_opt_  IUnknown          *pAdapter,
			D3D_FEATURE_LEVEL MinimumFeatureLevel,
			_In_      REFIID            riid,
			_Out_opt_ void              **ppDevice
            );
			*/
        
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

u32 GetCurrentBackBufferIndex(IDXGISwapChain4* swapChain4){
	u32 backBufferIndex;
	HRESULT result = IDXGISwapChain4_GetCurrentBackBufferIndex(swapChain4,&backBufferIndex);
	ASSERT(SUCCEEDED(result));
	return backBufferIndex;
}

#endif


