#include "stats.h"
#include<cmath>



Stats Statistics::ComputeStatistics(const std::vector<float>&values ) {
    //Implement statistics here
    Stats computedStatistics{};

    if (values.size() == 0)
    {
        computedStatistics.average = NAN;
        computedStatistics.max = NAN;
        computedStatistics.min = NAN;
            
    }
    else
    {
        for (int i = 0; i < values.size(); i++)
        {
            if (i == 0)
            {
                computedStatistics.max = values[i];
                computedStatistics.min = values[i];
            }
            else
            {
                if (computedStatistics.max < values[i])
                {
                    computedStatistics.max = values[i];

                }
                if (computedStatistics.min > values[i])
                {
                    computedStatistics.min = values[i];
                }

            }
            computedStatistics.average = computedStatistics.average + values[i];


        }

        computedStatistics.average = computedStatistics.average / values.size();
    }

    return computedStatistics;

}


StatsAlerter::StatsAlerter(const float value, std::vector<IAlerter*> &alerter)
{
    
    this->maxthreshold = value;
    this->alerters = alerter;

}


void  StatsAlerter::checkAndAlert(std::vector<float>values)
{
    for (int i = 0; i < values.size(); i++)
    {
        if (values[i] >= maxthreshold)
        {
            alerters[0]->raiseAlert();
            alerters[1]->raiseAlert();
        }
    }
}

