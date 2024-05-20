#ifndef IMDB
#define IMDB
#include <memory>
#include <string>
#include <mutex>
// create an in memory singlton class that contains the data
// this class stores a string and return it
class imdb
{
    private:
    imdb();
    ~imdb()
    {
        m_instance.reset();
    };

    private:
    std::shared_ptr<imdb> m_instance = nullptr;
    std::string m_data;
    std::mutex data_mutex;

    public:
    std::shared_ptr<imdb> get_db()
    {
        if(m_instance == nullptr)
        {
            m_instance = std::make_shared<imdb>();
        }
        return m_instance;
    }

    void store_in_db(const std::string & input)
    {
        std::lock_guard<std::mutex> lock(data_mutex);
        m_data = input;
    }

    std::string& get_data()
    {
        std::lock_guard<std::mutex> lock(data_mutex);
        return m_data;
    }
};






#endif