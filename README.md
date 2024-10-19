IL2CPP Resolver
A run-time API resolver for IL2CPP Unity.

External Version(Rework WIP) | (Old) Pre-HeaderOnly Version

Quick Example
#include <IL2CPP_Resolver.hpp>

void SomeFunction()
{
    IL2CPP::Initialize(); // This needs to be called once!

    Unity::CGameObject* m_Local = Unity::GameObject::Find("LocalPlayer");
    Unity::CComponent* m_LocalData = m_Local->GetComponent("PlayerData");
    m_LocalData->SetMemberValue<bool>("CanFly", true);
}
Registering OnUpdate Callback
void OurUpdateFunction()
{
    // Your special code...
}

void OnLoad()
{
    IL2CPP::Initialize();

    IL2CPP::Callback::Initialize();
    IL2CPP::Callback::OnUpdate::Add(OurUpdateFunction);
}
More: https://sneakyevil.gitbook.io/il2cpp-resolver/
