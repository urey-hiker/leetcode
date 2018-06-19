#include <string>

using namespace std;

class isMatch
{
  public:
    bool solve(string s, string p)
    {
        auto pitr = p.begin();
        auto sitr = s.begin();
        
        if (pitr == p.end()) {
            if (sitr == s.end()) {
                return true;
            }
            return false;
        }
        if (*pitr == '*')
        {
            return false;
        }
        if (p.size() == 1)
        {
            if (s.size() > 1 || s.size() == 0)
            {
                return false;
            }
            if (*pitr == '.')
            {
                return true;
            }
            if (*pitr == *sitr)
            {
                return true;
            }
            return false;
        }
        char c = 0;
        // bool lp = false;
        c = *pitr;
        if (*(pitr + 1) == '*')
        {
            auto res = this->solve(string().assign(sitr, s.end()), string().assign(pitr + 2, p.end()));
            if (res == true)
            {
                return true;
            }
            while (sitr != s.end() && (c == '.' || *sitr == c))
            {
                res = this->solve(string().assign(++sitr, s.end()), string().assign(pitr + 2, p.end()));
                if (res == true)
                {
                    return true;
                }
            }
            return false;
        }
        if (sitr == s.end()) {
            return false;
        }
        if (c != '.' && *sitr != c)
        {
            return false;
        }
        return this->solve(string().assign(sitr + 1, s.end()), string().assign(pitr + 1, p.end()));
    }
};