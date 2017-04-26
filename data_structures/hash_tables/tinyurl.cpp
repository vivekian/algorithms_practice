#include <iostream>
#include <unordered_map> 
#include <string> 
#include <random> 

using namespace std; 

class TinyURL
{ 
    public: 
        string encode(string longURL);
        string decode(string shortURL);

    private: 
        unordered_map<string, string> m_longshort; 
        unordered_map<string, string> m_shortlong; 

        string get_random_str(const int numchars)
        { 
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(0,25);
            string ret;

            for (auto i=0; i<numchars; ++i) 
            {
                ret += (i%2) ? 'a' : 'A' + dis(gen);
            }

            return ret; 
        }
};

string TinyURL::encode(string longURL)
{
    if (m_longshort.count(longURL) > 0) { 
        return m_longshort[longURL];
    }

    string shortURL = get_random_str(6); 
    m_longshort[longURL] = shortURL;
    m_shortlong[shortURL] = longURL; 

    return shortURL; 
}

string TinyURL::decode(string shortURL)
{ 
    auto itr = m_shortlong.find(shortURL);

    if (itr == m_shortlong.end()) { 
        return "";
    }
    
    return itr->second;
}

int main()
{ 
    TinyURL converter; 
    string small = converter.encode("abcd");
    cout << converter.decode(small) << endl; 
    return 0; 
} 

