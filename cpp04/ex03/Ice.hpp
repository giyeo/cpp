#ifndef __ICE_HPP__
#define __ICE_HPP__

class Ice {
    public:
        Ice();
        ~Ice();
        Ice(const Ice &other);
        Ice& operator=(const Ice &other);
};

#endif