#pragma once

#include "Module.h"

namespace WPEFramework {
namespace Exchange {

    //@json
    struct IAVSController : virtual public Core::IUnknown {
        enum { ID = ID_AVSCONTROLLER };
        virtual ~IAVSController(){};

        //@event
        struct INotification : virtual public Core::IUnknown {
            enum { ID = ID_AVSCONTROLLER_NOTIFICATION };
            virtual ~INotification(){};

            enum dialoguestate {
                IDLE,
                LISTENING,
                EXPECTING,
                THINKING,
                SPEAKING
            };

            /// @brief Notifies about dialog state changes
            /// @param state a new state (e.g. SPEAKING)
            virtual void DialogueStateChange(const int state) const = 0;
        };

        virtual void Register(INotification* sink) = 0;
        virtual void Unregister(INotification* sink) = 0;

        /// @brief Mute
        /// @param mute Mute or umute (e.g. true)
        /// @return 0 on success, otherwise error code
        virtual uint32_t Mute(const bool mute) = 0;

        /// @brief Record
        /// @param start Start or stop voice recording (e.g. true)
        /// @retval 0 success
        /// @retval otherwise error code
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

} // Exchange
} // WPEFramework
