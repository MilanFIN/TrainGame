#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <QString>

class GameException
{
public:
    explicit GameException(const QString& msg);

    virtual ~GameException() = default;

    virtual QString msg() const;
private:
    const QString msg_;
};

#endif // GAMEEXCEPTION_H
