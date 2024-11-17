///////////////////////////////////////////////////////////////////////////////////////////////////////////
///                                                                                                        
/// Copyright, 2021 PopcornSAR Co., Ltd. All rights reserved.                                              
/// This software is copyright protected and proprietary to PopcornSAR Co., Ltd.                           
/// PopcornSAR Co., Ltd. grants to you only those rights as set out in the license conditions.             
///                                                                                                        
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// AUTOSAR VERSION                   : R20-11
/// GENERATED BY                      : PARA, Adaptive Application Generator
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// GENERATED FILE NAME               : controldata.h
/// SOFTWARE COMPONENT NAME           : ControlData
/// GENERATED DATE                    : 2024-11-12 08:42:40
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef PARA_AA_GEN_SOFTWARE_COMPONENT_RPORT_ACTUATOR_AA_CONTROLDATA_H
#define PARA_AA_GEN_SOFTWARE_COMPONENT_RPORT_ACTUATOR_AA_CONTROLDATA_H
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/// INCLUSION HEADER FILES
///////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "deepracer/service/controldata/svcontroldata_proxy.h"
 
#include "ara/log/logger.h"
 
#include <mutex>
#include <thread>
 
namespace actuator
{
namespace aa
{
namespace port
{
 
class ControlData
{
public:
    /// @brief Constructor
    ControlData();
    
    /// @brief Destructor
    ~ControlData();
    
    /// @brief Start port
    void Start();
    
    /// @brief Terminate port
    void Terminate();
    
    /// @brief Subscribe event, CEvent
    void SubscribeCEvent();
     
    /// @brief Stop event subscription, CEvent
    void StopSubscribeCEvent();
     
    /// @brief Event receive handler, CEvent
    void ReceiveEventCEventTriggered();
     
    /// @brief Event receive handler, CEvent
    void ReceiveEventCEventCyclic();
     
    /// @brief Read event data, CEvent
    void ReadDataCEvent(ara::com::SamplePtr<deepracer::service::controldata::proxy::events::CEvent::SampleType const> samplePtr);
    
    /// @brief Set receive event data handler, CEvent
    void SetReceiveEventCEventHandler(std::function<void(const deepracer::service::controldata::proxy::events::CEvent::SampleType&)> handler);
    
private:
    /// @brief Callback for find service
    void Find(ara::com::ServiceHandleContainer<deepracer::service::controldata::proxy::SvControlDataProxy::HandleType> handles,
              ara::com::FindServiceHandle findHandle);
    
    /// @brief Callback for event receiver, CEvent
    void RegistReceiverCEvent();
    
    
private:
    /// @brief Logger for this port
    ara::log::Logger& m_logger;
    
    /// @brief Flag of port status
    bool m_running;
    
    /// @brief Flag of find service status
    bool m_found;
    
    /// @brief Mutex for this port
    std::mutex m_mutex; 
    
    /// @brief AUTOSAR Port Interface
    std::shared_ptr<deepracer::service::controldata::proxy::SvControlDataProxy> m_interface;
    
    /// @brief Find service handle
    std::shared_ptr<ara::com::FindServiceHandle> m_findHandle;

    /// @brief Receive event handler
    std::function<void(const deepracer::service::controldata::proxy::events::CEvent::SampleType&)> m_receiveEventCEventHandler;

};
 
} /// namespace port
} /// namespace aa
} /// namespace actuator
 
#endif /// PARA_AA_GEN_SOFTWARE_COMPONENT_RPORT_ACTUATOR_AA_CONTROLDATA_H