#include "data.h"
using namespace std;

data::data()
{
    memset(prot,0,MAX_CHAR + 1);
    memset(owner,0,MAX_CHAR + 1);
    memset(group,0,MAX_CHAR + 1);
    memset(month,0,MAX_CHAR + 1);
    memset(time,0,MAX_CHAR + 1);
    memset(name,0,MAX_CHAR + 1);
    links = 0;
    blocks = 0;
    day = 0;
    year = 0;
    type = 0;
}

data::~data()
{
    memset(prot,0,MAX_CHAR + 1);
    memset(owner,0,MAX_CHAR + 1);
    memset(group,0,MAX_CHAR + 1);
    memset(month,0,MAX_CHAR + 1);
    memset(time,0,MAX_CHAR + 1);
    memset(name,0,MAX_CHAR + 1);
    links = 0;
    blocks = 0;
    day = 0;
    year = 0;
    type = 0;
}

data::data(const data & source)
{
    memset(prot,0,MAX_CHAR + 1);
    memset(owner,0,MAX_CHAR + 1);
    memset(group,0,MAX_CHAR + 1);
    memset(month,0,MAX_CHAR + 1);
    memset(time,0,MAX_CHAR + 1);
    memset(name,0,MAX_CHAR + 1);

    strcpy(prot, source.prot);
    strcpy(owner, source.owner);
    strcpy(group, source.group);
    strcpy(month, source.month);
    strcpy(time, source.time);
    strcpy(name, source.name);

    links = source.links;
    blocks = source.blocks;
    day = source.day;
    year = source.year;
    type = source.type;
}

data & data::operator = (const data & source) 
{
    if (this != &source) {
        memset(prot,0,MAX_CHAR + 1);
        memset(owner,0,MAX_CHAR + 1);
        memset(group,0,MAX_CHAR + 1);
        memset(month,0,MAX_CHAR + 1);
        memset(time,0,MAX_CHAR + 1);
        memset(name,0,MAX_CHAR + 1);

        strcpy(prot, source.prot);
        strcpy(owner, source.owner);
        strcpy(group, source.group);
        strcpy(month, source.month);
        strcpy(time, source.time);
        strcpy(name, source.name);

        links = source.links;
        blocks = source.blocks;
        day = source.day;
        year = source.year;
        type = source.type;
    }
    return *this;
}

std::ostream & operator << (std::ostream & out, const data & source)
{
    out << source.type;
    out << source.prot;
    out << " " << source.links;
    out << " " << source.owner;
    out << " " << source.group;
    out << " " << source.blocks;
    out << " " << source.month;
    out << " " << source.day;
    if (source.year > 0) out << " " << source.year;
    else out << " " <<  source.time;
    out << " " << source.name;
    return out;
    
}

std::istream & operator >> (std::istream & in, ::data & dest)
{
    memset(dest.prot,0,MAX_CHAR + 1);
    memset(dest.owner,0,MAX_CHAR + 1);
    memset(dest.group,0,MAX_CHAR + 1);
    memset(dest.month,0,MAX_CHAR + 1);
    memset(dest.time,0,MAX_CHAR + 1);
    memset(dest.name,0,MAX_CHAR + 1);
    in >> dest.type;
    in >> dest.prot;
    in >> dest.links;
    in >> dest.owner;
    in >> dest.group;
    in >> dest.blocks;
    in >> dest.month;
    in >> dest.day;
    in >> dest.time;
    dest.year = 0;
    if (dest.time[2] != ':') {
        dest.year      = (dest.time[0] - '0') * 1000;
        dest.year      +=(dest.time[1] - '0') * 100;
        dest.year      +=(dest.time[2] - '0') * 10;
        dest.year      +=(dest.time[3] - '0');
        memset(dest.time,0,MAX_CHAR + 1);
    }
    in.getline(dest.name,MAX_CHAR);

    return in;
}
