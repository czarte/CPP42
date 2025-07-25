//
// Created by voparkan on 3/7/25.
//

#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain {
    private:
      std::string ideas[100];
    public:
      	Brain();
		Brain(Brain &other);
		Brain &operator=(Brain &other);
      	~Brain();
		void setIdea(std::string const &idea, int const &index);
		std::string getIdea(int const &index);
};



#endif //BRAIN_H
