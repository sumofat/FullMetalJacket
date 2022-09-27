#if WINDOWS

typedef enum{
	CBV_SRV_UV = 0,
			   SAMPLER     = 1,
			   RTV         = 2,
			   DSV         = 3,
			   NUM_TYPES   = 4,
}DescriptorHeapType;

typedef struct{
	ID3D12DescriptorHeap* ptr;
	DescriptorHeapType type;
	u64 increment_size;
	u64 cpu_mem_offset;
	u64 gpu_mem_offset;
	int max_cpu_desc;
	int cpu_desc_count;
}DescriptorHeap; 

typedef enum{
	NONE           = 0x0,
	SHADER_VISIBLE = 0x1,
}DescriptorHeapFlags;

DescriptorHeap create_descriptor_heap(ID3D12Device2* device,DescriptorHeapType type,int num_descriptors,DescriptorHeapFlags flags){
	DescriptorHeap heap = {};
	heap.type = type;
	heap.max_cpu_desc = num_descriptors;
	heap.cpu_desc_count = 0;
	heap.increment_size = ID3D12Device_GetDescriptorHandleIncrementSize(device,type);
	D3D12_DESCRIPTOR_HEAP_DESC desc = {};
	desc.NumDescriptors = num_descriptors;
	desc.Type = (D3D12_DESCRIPTOR_HEAP_TYPE)type;
	desc.Flags = (D3D12_DESCRIPTOR_HEAP_FLAGS)flags;
	desc.NodeMask = 0;

	HRESULT r = ID3D12Device_CreateDescriptorHeap(device,&desc,&IID_ID3D12DescriptorHeap,(void**)&heap.ptr);
	if (FAILED(r)){
		ASSERT(false);
	}

	D3D12_CPU_DESCRIPTOR_HANDLE cpu_h; 
	ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(heap.ptr,&cpu_h);
	D3D12_GPU_DESCRIPTOR_HANDLE gpu_h;
	ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(heap.ptr,&gpu_h);

	heap.cpu_mem_offset = cpu_h.ptr;
	heap.gpu_mem_offset = gpu_h.ptr;
	return heap;
}

#endif

