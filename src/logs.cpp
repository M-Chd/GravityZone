#include "logs.h"

void Log::update(space& s)
{
    std::vector<logsEvents> logs = s.getLogs();

    if (!logs.empty()){
        for (auto s : logs){

            switch(s){
                case logsEvents::PLACE_EVENT:
                {
                    std::cout << "+ Body placed" << "\n";
                    logs.clear();
                }break;
                case logsEvents::COLLISION_EVENT:
                {
                    std::cout << "+ Collision occured" << "\n";
                    logs.clear();
                }break;
                case logsEvents::DELETE_EVENT:
                {
                    std::cout << "+ Body deleted" << "\n";
                    logs.clear();
                }break;
                case logsEvents::ERROR_EVENT:
                {
                    std::cout << "+ An error occured" << "\n";
                    logs.clear();
                }break;
                default:
                {
                    std::cout << "+ Warining - something wrong occured !" << "\n";
                    logs.clear();
                }break;
            }
        }
        logs.clear();
    }
}
