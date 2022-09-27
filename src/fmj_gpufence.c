
#ifdef WINDOWS
	typedef struct{
		ID3D12Fence* ptr;
	}Fence;

	typedef struct{
		HANDLE ptr;
	}EventHandle;
#endif

Fence create_fence(ID3D12Device2* device){
	Fence result = {0};
#if WINDOWS
	ID3D12Fence* fence;
	if (!SUCCEEDED(ID3D12Device_CreateFence(device,0,NONE,&IID_ID3D12Fence,(void**)(&fence)))){
		ASSERT(false)
	}
	result.ptr = fence;
#endif
	return result;
} 

EventHandle create_event_handle(){
	EventHandle result = {0};
#if WINDOWS
	HANDLE fe = CreateEventEx(NULL,FALSE,FALSE,EVENT_ALL_ACCESS);
	ASSERT(fe != NULL);
	result.ptr = fe;
#endif
	return result;
}

/*
create_event_handle :: proc() -> EventHandle{
	result : EventHandle
	when RENDERER == RENDER_TYPE.DX12{
		fence_event := windows.CreateEventW(nil,false,false,nil)	
		assert(fence_event != nil)
		result.ptr = fence_event
	}
	return result
}

is_fence_complete :: proc(fence : ^Fence,fence_value : u64)-> bool{
	when RENDERER == RENDER_TYPE.DX12{
		return fence.ptr->GetCompletedValue() >= fence_value
	}
}

wait_for_fence_value :: proc(fence : ^Fence,fence_value : u64,fence_event : EventHandle,duration : u32){
	when RENDERER == RENDER_TYPE.DX12{
		if is_fence_complete(fence,fence_value) == false{
			fence.ptr->SetEventOnCompletion(fence_value,fence_event.ptr)
			windows.WaitForSingleObject(fence_event.ptr,duration)
		}
	}
}
*/
