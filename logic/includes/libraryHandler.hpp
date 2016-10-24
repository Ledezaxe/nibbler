//
// libraryHandler.hpp for Epitech in /home/lucas/epitech/rendus-git/cpp/cpp_nibbler/logic
//
// Made by Lucas Stil
// Login   <lucas@pc-lucas>
//
// Started on  Thu Apr  3 16:16:04 2014 Lucas Stil
// Last update Thu Apr  3 16:44:10 2014 Lucas Stil
//

#ifndef LIBRARYHANDLER_HPP_
# define LIBRARYHANDLER_HPP_

class libraryHandler
{
  public:
    libraryHandler(const char *);
    libraryHandler(const libraryHandler &);
    ~libraryHandler();
    libraryHandler operator=(const libraryHandler &);

    void *getHandle() const;

  private:
    void *handle;
};

#endif /* !LIBRARYHANDLER_HPP_ */
