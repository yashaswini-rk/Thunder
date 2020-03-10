#pragma once

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    //@json
    struct IAVSController : virtual public Core::IUnknown {
        enum { ID = ID_AVSCONTROLLER };
        virtual ~IAVSController(){};

        virtual uint32_t Mute(const bool mute) = 0;

        virtual uint32_t Record(const bool start) = 0;
    };

    struct IAVSClient : virtual public Core::IUnknown {
        enum { ID = ID_AVSCLIENT };

        virtual ~IAVSClient(){};

        virtual bool Initialize(PluginHost::IShell* service, const std::string& alexaClientConfig,
            const std::string& smartScreenConfig, const std::string& pathToInputFolder, const std::string& audioSource,
            const bool enableKWD, const std::string& logLevel) = 0;
        virtual bool Deinitialize() = 0;
        virtual IAVSController* Controller() = 0;
        virtual void StateChange(PluginHost::IShell* audioSource) = 0;
    };


       //@JSON-API

        // struct ICommands : virtual public Core::IUnknown {
        //     enum { ID = ID_AVSCLIENT_INPUT };
        //     virtual ~ICommand(){};

        //     virtual uint32_t Mute() = 0;
        //     virtual uint32_t MicrophoneToggle() = 0;
        //     virtual uint32_t Tap() = 0;
        //     virtual uint32_t HoldToggled() = 0;
        // };


} // Exchange
} // WPEFramework
