#include <stdexcept>


struct Date {
    unsigned year = 0u;
    unsigned month = 0u;
    unsigned day = 0u;
};

struct StudentInfo {
    size_t id;
    char mark;
    int score;
    unsigned course;
    Date birth_date;
};

bool operator<(Date date1, Date date2) {
    return std::tie(date1.year, date1.month, date1.day) 
    < std::tie(date2.year, date2.month, date2.day);
}

bool operator==(Date date1, Date date2) {
    return std::tie(date1.year, date1.month, date1.day) 
    == std::tie(date2.year, date2.month, date2.day);
}

bool operator>(Date date1, Date date2) {
    return !(date1 < date2) and !(date1 == date2);
}
bool operator>=(Date date1, Date date2) {
    return !(date1 < date2) or (date1 == date2);
}
bool operator<=(Date date1, Date date2) {
    return (date1 < date2) or (date1 == date2);
}
bool operator!=(Date date1, Date date2) {
    return !(date1 == date2);
}

bool operator==(StudentInfo st1, StudentInfo st2) {
    return std::tie(st1.mark, st1.score) == std::tie(st2.mark, st2.score);
}
bool operator!=(StudentInfo st1, StudentInfo st2) {
    return !(std::tie(st1.mark, st1.score) == std::tie(st2.mark, st2.score));
}

bool operator<(StudentInfo st1, StudentInfo st2) {

    if (st1.mark != st2.mark) {
        return st1.mark > st2.mark;  
    }
    if (st1.score != st2.score) {
        return st1.score < st2.score;  
    }
    if (st1.course != st2.course) {
        return st1.course > st2.course;  
    }
    if (st1.birth_date != st2.birth_date) {
        return st1.birth_date < st2.birth_date;  
    }
    else
        return false;
       
}
bool operator>(StudentInfo st1, StudentInfo st2) {
    return !(st1 < st2) and !(st1 == st2);
}
bool operator>=(StudentInfo st1, StudentInfo st2) {
    return !(st1 < st2) or (st1 == st2);
}
bool operator<=(StudentInfo st1, StudentInfo st2) {
    return (st1 < st2) or (st1 == st2);
}