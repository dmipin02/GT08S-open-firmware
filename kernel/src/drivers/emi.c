#include <drivers/emi.h>

void EMI_MemoryRemap(MREMAP Mode)
{
    bool CacheState;

#ifdef USEINTERRUPTS
    uint32_t intflags = DisableInterrupts();
#endif
    CacheState = MPU_DisableCache();
    EMI_REMAP = Mode & EMI_REMAP_MODE_MASK;
    MPU_RestoreCacheEnState(CacheState);
#ifdef USEINTERRUPTS
    RestoreInterrupts(intflags);
#endif
}
