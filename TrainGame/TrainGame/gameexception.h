#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <QString>

/**
 * @brief GameException baseclass for exceptions
 */
class GameException
{
public:
    /**
     * @brief GameException constructor
     * @param msg cause of exception
     */
    explicit GameException(const QString& msg);


    virtual ~GameException() = default;

    /**
     * @brief msg return cause of the exception
     * @return
     */
    virtual QString msg() const;
private:
    const QString msg_;
};

#endif // GAMEEXCEPTION_H
