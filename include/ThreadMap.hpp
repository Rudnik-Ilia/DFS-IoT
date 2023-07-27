#pragma once

#include <unordered_map>
#include <mutex>
#include <thread> // std::thread::id

#include "WorkerThread.hpp"

namespace dfs
{
    class ThreadMap
    {
        public:
            typedef std::thread::id Key;
            typedef std::shared_ptr<WorkerThread> Value;
            typedef std::pair<Key, Value> KeyValPair;

            typedef typename std::unordered_map<Key, Value>::iterator iterator;
            typedef typename std::unordered_map<Key, Value>::const_iterator const_iterator;

            ThreadMap() = default;
            ThreadMap(ThreadMap &&) = delete;
            ThreadMap(const ThreadMap &) = delete;  
            ThreadMap &operator=(ThreadMap &&) = delete;
            ThreadMap &operator=(const ThreadMap &) = delete;
            ~ThreadMap() = default;

            void Insert(const KeyValPair &kvPair_);
            void Remove(iterator pos_);
            iterator Find(Key key_);
            
            WorkerThread::State GetState(Key key_) const;
        
        private:
            mutable std::mutex m_mutex;
            std::unordered_map<Key, Value> m_threadMap;
    }; 
}


