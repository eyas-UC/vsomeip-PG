#ifndef VSOMEIP_SERVER
#define VSOMEIP_SERVER

#include "vsomeip/vsomeip.hpp"
#include <string>
#include "config.h"


class vsomeip_server
{
    public:
    // init function
    void init(const std::string& name)
    {
        m_app = vsomeip::runtime::get()->create_application(name);
        m_app->init();
        auto gama= [this](const std::shared_ptr<vsomeip::message> &p_response){
            this->request_handler(p_response);
        };

        // auto gamma = std::bind(&vsomeip_server::request_handler,this,std::placeholders::_1);
        m_app->register_message_handler(SERVICE_ID, SERVICE_INSTANCE, METHOD_ID,gama);

    }
    // Request handler
    void request_handler(const std::shared_ptr<vsomeip::message> &p_response)
    {
        auto payload = p_response->get_payload();
        payload->get_data();
        payload->get_length();
        // send data to server through the socket
    }


    // response


    // pass data to flask server use IPC
    void pass_data_to_ipc()
    {

    }








    private:
        std::shared_ptr<vsomeip::application> m_app;
        // std::shared_ptr<vsomeip::>
};









#endif