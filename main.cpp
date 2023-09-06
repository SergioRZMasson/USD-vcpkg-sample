#include "pxr/usd/usd/notice.h"
#include "pxr/usd/usd/stage.h"
#include "pxr/usd/usd/prim.h"
#include <pxr/usd/ar/defaultResolver.h>

int main()
{
    const char* fileName = ".\\Kitchen_set.usd";
    pxr::ArDefaultResolver::SetDefaultSearchPath({"./"});
    bool bIsSupported = PXR_NS::UsdStage::IsSupportedFile(fileName);
    if (bIsSupported)
    {
        printf("it is supported!\n");
        PXR_NS::UsdStageRefPtr loadedStage = PXR_NS::UsdStage::Open(fileName);
        if (loadedStage)
        {
            PXR_NS::UsdPrim pseudoRoot = loadedStage->GetPseudoRoot();
            printf("Pseudo root path: %s\n", pseudoRoot.GetPath().GetString().c_str());
            for (PXR_NS::UsdPrim const& c : pseudoRoot.GetChildren())
            {
                printf("\tChild path: %s\n", c.GetPath().GetString().c_str());
            }
        }
    }
    return 0;
}
