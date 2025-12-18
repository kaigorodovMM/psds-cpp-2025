#include <cmath>
#include <stdexcept>
#include <vector>


struct DataStats {
    double avg = 0.0;
    double sd = 0.0;
};

DataStats CalculateDataStats(std::vector<int>& vect) {
    int n = 0;
    
    DataStats rezult = {0, 0};
    if (vect.begin() == vect.end()){
        return rezult;
    }
    for (auto it = vect.begin(); it != vect.end(); ++it) {
        ++n;
        rezult.avg += *it;
    }
    rezult.avg /= n;
    for (auto it = vect.begin(); it != vect.end(); ++it) {
        rezult.sd += pow((*it - rezult.avg), 2);
    }
    rezult.sd /= n;
    rezult.sd = sqrt(rezult.sd);
    return rezult;
}

DataStats CalculateDataStats(const std::vector<int>& vect) {
    int n = 0;
    
    DataStats rezult = {0, 0};
    if (vect.begin() == vect.end()){
        return rezult;
    }
    for (auto it = vect.begin(); it != vect.end(); ++it) {
        ++n;
        rezult.avg += *it;
    }
    rezult.avg /= n;
    for (auto it = vect.begin(); it != vect.end(); ++it) {
        rezult.sd += pow((*it - rezult.avg), 2);
    }
    rezult.sd /= n;
    rezult.sd = sqrt(rezult.sd);
    return rezult;
}
