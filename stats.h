#include <vector>

struct Stats
{
    float average;
    float max;
    float min;
};

class IAlerter
{
public:
    virtual void raiseAlert() = 0;
};

class EmailAlert : public IAlerter
{
public:
    bool emailSent;

    void raiseAlert()
    {
        this->emailSent = true;
    }

};

class LEDAlert : public IAlerter
{
public:
    bool ledGlows;

    void raiseAlert()
    {
        this->ledGlows = true;
    }

};

class StatsAlerter
{
private:
    std::vector<IAlerter*>alerters;
    float maxthreshold;

public:
    StatsAlerter(const float value, std::vector<IAlerter*> &alerters);
    void checkAndAlert(std::vector<float>);
};

namespace Statistics {
    Stats ComputeStatistics(const std::vector<float>& );
}
