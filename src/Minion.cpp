#include "Minion.hpp"

namespace dfs
{
    Minion::Minion(uint16_t port): m_receiver(port)
    {
        
    }

    Minion::~Minion()
    {

    }

    void Minion::Wait()
    {
        m_receiver.Listen();
    }
}