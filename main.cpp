#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usd/usdGeom/sphere.h>
#include <pxr/usd/ar/defaultResolver.h>
#include <pxr/base/plug/plugin.h>
#include <pxr/base/plug/registry.h>
#include <filesystem>

#include <winrt/base.h>

namespace fs = std::filesystem;

std::filesystem::path GetModulePath()
{
    WCHAR modulePath[4096];
    DWORD result = GetModuleFileNameW(nullptr, modulePath, ARRAYSIZE(modulePath));
    winrt::check_bool(result != 0 && result != std::size(modulePath));
    return std::filesystem::path{ modulePath }.parent_path();
}

int main()
{
    auto currentPath = GetModulePath().string();
    std::replace(currentPath.begin(), currentPath.end(), '\\', '/');
    currentPath += "/usd/";
    auto plugins = pxr::PlugRegistry::GetInstance().RegisterPlugins(currentPath);

    auto stage = pxr::UsdStage::CreateNew("HelloWorld.usda");
    auto xform = pxr::UsdGeomXform::Define(stage, pxr::SdfPath("/hello"));
    auto sphere = pxr::UsdGeomSphere::Define(stage, pxr::SdfPath("/hello/world"));
    stage->GetRootLayer()->Save();
}

