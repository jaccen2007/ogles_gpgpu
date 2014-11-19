#include "memtransfer_factory.h"
#include "../core.h"

#ifdef __APPLE__
#include "../../platform/ios/memtransfer_ios.h"
#endif

using namespace ogles_gpgpu;

MemTransfer *MemTransferFactory::createInstance() {
    MemTransfer *instance = NULL;
    
    if (Core::usePlatformOptimizations) {
#ifdef __APPLE__
        instance = (MemTransfer *)new MemTransferIOS();
#endif
    }
    
    if (!instance) {
        instance = new MemTransfer();
    }
    
    return instance;
}