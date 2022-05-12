#ifndef SERLIALIZABLE_H_INCLUDED
#define SERLIALIZABLE_H_INCLUDED

struct Serializable {
    virtual void write(std::ostream &) const {}
    virtual void read(std::istream &)  {}
    virtual ~Serializable() {}
};

#endif // SERLIALIZABLE_H_INCLUDED
