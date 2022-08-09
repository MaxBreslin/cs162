#include "node.h"

bool operator>(const Node &lhs, const Node &rhs) {
    return *lhs.data > *rhs.data;
}
bool operator>(const Node &lhs, const char * const &rhs) {
    return *lhs.data > rhs;
}
bool operator>(const char * const &lhs, const Node &rhs) {
    return lhs > *rhs.data;
}
bool operator==(const Node &lhs, const Node &rhs) {
    return *lhs.data == *rhs.data;
}
bool operator==(const Node &lhs, const char * const &rhs) {
    return *lhs.data == rhs;
}
bool operator==(const char * const &lhs, const Node &rhs) {
    return rhs == lhs;
}
bool operator>=(const Node &lhs, const Node &rhs) {
    return (*lhs.data > *rhs.data || *lhs.data == *rhs.data);
}
bool operator>=(const Node &lhs, const char * const &rhs) {
    return (*lhs.data > rhs || *lhs.data == rhs);
}
bool operator>=(const char * const &lhs, const Node &rhs) {
    return (lhs > *rhs.data || lhs == *rhs.data);
}
bool operator<(const Node &lhs, const Node &rhs) {
    return rhs > lhs;
}
bool operator<(const Node &lhs, const char * const &rhs) {
    return rhs > lhs;
}
bool operator<(const char * const &lhs, const Node &rhs) {
    return rhs > lhs;
}
bool operator<=(const Node &lhs, const Node &rhs) {
    return rhs >= lhs;
}
bool operator<=(const Node &lhs, const char * const &rhs) {
    return rhs >= lhs;
}
bool operator<=(const char * const &lhs, const Node &rhs) {
    return rhs >= lhs;
}
bool operator!=(const Node &lhs, const Node &rhs) {
    return !(lhs == rhs);
}
bool operator!=(const Node &lhs, const char * const &rhs) {
    return !(lhs == rhs);
}
bool operator!=(const char * const &lhs, const Node &rhs) {
    return !(lhs == rhs);
}
