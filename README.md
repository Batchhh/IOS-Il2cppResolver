# IOS-IL2CPP Resolver
A run-time API resolver for IL2CPP Unity.


## Environment Variables

Change in Config.h

`BINARY_NAME` to target the right file! Default is "UnityFramework"

`WAIT_TIME_SEC` 

## Example usage
#### This need to be added in your tweak.xm!
```c
static inline const char* IL2CPP_FRAMEWORK(const char* NAME) {
        NSString *appPath = [[NSBundle mainBundle] bundlePath];
        NSString *binaryPath = [NSString stringWithFormat:@"%s", NAME];
        if ([binaryPath isEqualToString:@"UnityFramework"])
        {
            binaryPath = [appPath stringByAppendingPathComponent:@"Frameworks/UnityFramework.framework/UnityFramework"];
        }
        else
        {
            binaryPath = [appPath stringByAppendingPathComponent:binaryPath];
        }
        return [binaryPath UTF8String];
    }
```
### INIT (IMPORTANT)
```c
#include "IL2CPP_Resolver.hpp"

IL2CPP::Initialize(true, WAIT_TIME_SEC, IL2CPP_FRAMEWORK(BINARY_NAME) // This needs to be called once!

IL2CPP::Initialize(false, WAIT_TIME_SEC, IL2CPP_FRAMEWORK(BINARY_NAME) // This will not wait for the module. 
```

For more usage check the [wiki](https://github.com/Batchhh/IOS-Il2cppResolver/wiki/Start-here!)

## Authors

- [@sneakyevil](https://www.github.com/sneakyevil) Base source
- [@Batchh](https://www.github.com/Batchhh) Modified and adapted for IOS usage


## License

[MIT](https://choosealicense.com/licenses/mit/)
