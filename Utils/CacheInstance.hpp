#pragma once
#include <vector>
#include <functional>
#include <string>
#include <unordered_map>

struct CacheConfig {
    std::string typeName;
    std::vector<Unity::CGameObject*>* storage;
    std::function<void(Unity::CGameObject*)> process;
};

class CacheManager {
public:
    void AddCacheConfig(const std::string& typeName, std::vector<Unity::CGameObject*>& storage, std::function<void(Unity::CGameObject*)> process = nullptr) {
        configs[typeName] = { typeName, &storage, process };
    }

    void StartCaching() {
        while (true) {
            for (auto& [typeName, config] : configs) {
                config.storage->clear();
                auto objects = Unity::Object::FindObjectsOfType<Unity::CComponent>(typeName.c_str());

                if (objects) {
                    for (int i = 0; i < objects->m_uMaxLength; i++) {
                        if (auto component = objects->operator[](i)) {
                            if (auto gameObject = component->GetGameObject()) {
                                config.storage->push_back(gameObject);
                                if (config.process) {
                                    config.process(gameObject);
                                }
                            }
                        }
                    }
                }
            }
            sleep(1000);
        }
    }

private:
    std::unordered_map<std::string, CacheConfig> configs;
};

extern CacheManager cacheManager;