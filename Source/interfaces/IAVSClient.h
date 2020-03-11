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

            /// @brief notifies about dialogue state changes
            /// @param state The new state (e.g. SPEAKING)
            virtual void DialogueStateChange(const dialoguestate state) const = 0;
        };

        virtual void Register(INotification* sink) = 0;
        virtual void Unregister(INotification* sink) = 0;

        /// @brief Mutes both AVS_SPEAKER_VOLUME and AVS_ALERTS_VOLUME
        /// @param mute Mute or umute (e.g. true)
        /// @return 0 on success, otherwise error code
        virtual uint32_t Mute(const bool mute) = 0;

        /// @brief Starts voice recording
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
