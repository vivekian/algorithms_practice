#include <iostream> 
#include <vector>

using namespace std; 

namespace { 
    bool ComputeParity(uint64_t Num)
    { 
        uint8_t cnt = 0;

        while(Num) { 
            if (Num & 1) 
                cnt++;
            Num = Num >> 1;
        } 

        return cnt%2;
    }
}

// a faster way to compute by caching results for 8-bit numbers
class ParityCalculator
{ 
    public: 
        ParityCalculator() 
        {
            m_Table.resize(256);

            for (uint16_t i = 0; i < 256; i++) 
                m_Table[i] = ComputeParity(i);
        } 


        bool Compute(uint64_t Num) 
        { 
            uint8_t sum = 0;
            while (Num) { 
                sum += m_Table[Num & 0xFF];
                Num = Num >> 8;
            }

            return sum%2;
        } 

    private: 
        vector <bool> m_Table;
};

int main(int argc, char* argv[]) 
{
    ParityCalculator calc; 

    uint64_t tests[] = {1, 2, 3, 4, 8, 23, 64, 128, 655535};

    for (auto t: tests)
        cout << "parity - " << t << ": " << ComputeParity(t) << endl;
    for (auto t: tests)
        cout << "parity - " << t << ": " << calc.Compute(t) << endl;

    return 0;
} 
